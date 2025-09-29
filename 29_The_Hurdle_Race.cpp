#include <stdio.h>
#include <stdlib.h>

int hurdleRace(int k, int height_count, int* height) {
    int max_height = height[0];
    for (int i = 1; i < height_count; i++) {
        if (height[i] > max_height) {
            max_height = height[i];
        }
    }
    if (max_height > k) {
        return max_height - k;
    } else {
        return 0;
    }
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int* height = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &height[i]);
    }

    int result = hurdleRace(k, n, height);
    printf("%d\n", result);

    free(height);
    return 0;
}
