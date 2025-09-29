#include <stdio.h>
#include <stdlib.h>


int findDigits(int n) {
    int count = 0;
    int original = n;

    while (n > 0) {
        int digit = n % 10;
        if (digit != 0 && original % digit == 0) {
            count++;
        }
        n /= 10;
    }

    return count;
}

int main() {
    int t;
    scanf("%d", &t);

    for (int i = 0; i < t; i++) {
        int n;
        scanf("%d", &n);
        printf("%d\n", findDigits(n));
    }

    return 0;
}
