#include <stdio.h>
#include <stdlib.h>

#define MAX 5000  


int multiply(int x, int res[], int res_size) {
    int carry = 0;

    for (int i = 0; i < res_size; i++) {
        int prod = res[i] * x + carry;
        res[i] = prod % 10;
        carry = prod / 10;
    }

    while (carry) {
        res[res_size] = carry % 10;
        carry /= 10;
        res_size++;
    }

    return res_size;
}

// Compute factorial of n
void extraLongFactorials(int n) {
    int res[MAX];
    res[0] = 1;
    int res_size = 1;

    for (int x = 2; x <= n; x++) {
        res_size = multiply(x, res, res_size);
    }

    // Print factorial in correct order
    for (int i = res_size - 1; i >= 0; i--) {
        printf("%d", res[i]);
    }
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);
    extraLongFactorials(n);
    return 0;
}
