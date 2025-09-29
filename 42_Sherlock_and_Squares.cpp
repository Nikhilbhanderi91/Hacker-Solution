#include <stdio.h>
#include <math.h>

int squares(int a, int b) {
    int start = (int)ceil(sqrt((double)a));
    int end   = (int)floor(sqrt((double)b));

    if (end < start) return 0;
    return end - start + 1;
}

int main() {
    int q;
    scanf("%d", &q);

    for (int i = 0; i < q; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        printf("%d\n", squares(a, b));
    }

    return 0;
}
