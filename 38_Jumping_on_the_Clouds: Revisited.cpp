#include <stdio.h>
#include <stdlib.h>

// Function to calculate remaining energy after circular jumps
int jumpingOnClouds(int c_count, int* c, int k) {
    int energy = 100;
    int position = 0;

    do {
        position = (position + k) % c_count;
        energy -= 1 + (c[position] * 2); // 1 for jump + 2 if thundercloud
    } while (position != 0);

    return energy;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int* c = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &c[i]);
    }

    int result = jumpingOnClouds(n, c, k);
    printf("%d\n", result);

    free(c);
    return 0;
}
