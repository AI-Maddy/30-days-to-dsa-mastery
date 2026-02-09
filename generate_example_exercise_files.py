import os
import re
from pathlib import Path

BASE_DIR = Path("30-days-to-dsa-mastery")

# Regex to detect example/exercise headings
EXAMPLE_RE = re.compile(r"^##\s*Example\s+(\d+)\s*[-—]?\s*(.*)", re.IGNORECASE)
EXERCISE_RE = re.compile(r"^##\s*Exercise\s+(\d+)\s*[-—]?\s*(.*)", re.IGNORECASE)

def extract_blocks(readme_path):
    """
    Yield blocks of the form:
    {
      'type': 'example' or 'exercise',
      'number': '1',
      'title': 'O(1) Access',
      'description_lines': [ ... ]
    }
    """
    blocks = []
    current = None

    with readme_path.open("r", encoding="utf-8") as f:
        for line in f:
            ex_match = EXAMPLE_RE.match(line)
            exr_match = EXERCISE_RE.match(line)

            if ex_match or exr_match:
                # Save previous block
                if current:
                    blocks.append(current)

                if ex_match:
                    current = {
                        "type": "example",
                        "number": ex_match.group(1),
                        "title": ex_match.group(2).strip(),
                        "description_lines": []
                    }
                else:
                    current = {
                        "type": "exercise",
                        "number": exr_match.group(1),
                        "title": exr_match.group(2).strip(),
                        "description_lines": []
                    }
            else:
                # If we're inside a block, keep collecting description
                if current is not None:
                    # Stop description when we hit another heading of same or higher level
                    if line.startswith("# "):  # new main section
                        blocks.append(current)
                        current = None
                    else:
                        current["description_lines"].append(line)

    if current:
        blocks.append(current)

    return blocks

def write_c_file(target_path: Path, block):
    target_path.parent.mkdir(parents=True, exist_ok=True)

    desc = "".join(block["description_lines"]).strip()
    if not desc:
        desc = "TODO: Add detailed description."

    with target_path.open("w", encoding="utf-8") as f:
        f.write("/*\n")
        f.write(f" * Type      : {block['type'].capitalize()}\n")
        f.write(f" * Number    : {block['number']}\n")
        if block["title"]:
            f.write(f" * Title     : {block['title']}\n")
        f.write(" *\n")
        f.write(" * Description:\n")
        for line in desc.splitlines():
            f.write(f" *   {line}\n")
        f.write(" *\n")
        f.write(" * Instructions:\n")
        f.write(" *   - Implement the solution in C.\n")
        f.write(" *   - Use main() for quick testing or expose functions for reuse.\n")
        f.write(" *   - Add time/space complexity notes at the bottom.\n")
        f.write(" */\n\n")
        f.write("#include <stdio.h>\n\n")
        f.write("int main(void) {\n")
        f.write("    // TODO: Implement this example/exercise.\n")
        f.write("    return 0;\n")
        f.write("}\n")

    print(f"✔ Created {target_path}")

def process_day(day_dir: Path):
    readme = day_dir / "README.md"
    if not readme.exists():
        return

    blocks = extract_blocks(readme)
    if not blocks:
        return

    for block in blocks:
        if block["type"] == "example":
            filename = f"example{int(block['number']):02d}.c"
            target = day_dir / "examples" / filename
        else:
            filename = f"exercise{int(block['number']):02d}.c"
            target = day_dir / "exercises" / filename

        write_c_file(target, block)

def main():
    if not BASE_DIR.exists():
        print(f"Base directory '{BASE_DIR}' not found.")
        return

    for day_dir in sorted(BASE_DIR.iterdir()):
        if day_dir.is_dir() and day_dir.name.startswith("Day"):
            process_day(day_dir)

    print("\nAll example/exercise C files generated (where headings were found).")

if __name__ == "__main__":
    main()