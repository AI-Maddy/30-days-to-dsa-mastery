/*
Overview:
- Finds first non-repeating char using freq table.
Approach:
- Count frequencies then scan.
Complexity:
- Time: O(n)
- Space: O(1)
*/

#include <stdio.h>

int main(void){ const char*s="swiss"; int freq[256]={0}; for(int i=0;s[i];i++) freq[(unsigned char)s[i]]++; for(int i=0;s[i];i++) if(freq[(unsigned char)s[i]]==1){ printf("%c\n", s[i]); break;} return 0; }
