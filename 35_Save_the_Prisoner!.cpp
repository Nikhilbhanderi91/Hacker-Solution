#include <stdio.h>

int saveThePrisoner(int n, int m, int s) {
    int last = (s + m - 1) % n;
    return (last == 0) ? n : last;
}

int main() {
    int t;
    scanf("%d", &t); 

    for (int i = 0; i < t; i++) {
        int n, m, s;
        scanf("%d %d %d", &n, &m, &s);

        int result = saveThePrisoner(n, m, s);
        printf("%d\n", result);
    }

    return 0;
}
