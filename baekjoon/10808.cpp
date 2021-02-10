#include <cstdio>
int main() {
    char s[101];
    int c[26] = {0, };
    scanf("%s", s);
    for (int i=0; s[i]; i++) c[s[i]-'a']++;
    for (int i=0; i<26; i++) printf("%d ", c[i]);
    return 0;
}
