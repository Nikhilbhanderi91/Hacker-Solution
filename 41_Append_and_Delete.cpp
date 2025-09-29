#include <stdio.h>
#include <string.h>

char* appendAndDelete(char* s, char* t, int k) {
    static char yes[] = "Yes";
    static char no[] = "No";

    int lenS = strlen(s);
    int lenT = strlen(t);

    // Find common prefix length
    int common = 0;
    while (common < lenS && common < lenT && s[common] == t[common]) {
        common++;
    }

    int min_ops = (lenS - common) + (lenT - common);

    if (k >= lenS + lenT) {
        return yes;  // Can delete all and rebuild
    } else if (k >= min_ops && (k - min_ops) % 2 == 0) {
        return yes;  // Extra moves can be spent as delete+append
    } else {
        return no;
    }
}

int main() {
    char s[10001], t[10001];
    int k;

    scanf("%s", s);
    scanf("%s", t);
    scanf("%d", &k);

    printf("%s\n", appendAndDelete(s, t, k));

    return 0;
}
