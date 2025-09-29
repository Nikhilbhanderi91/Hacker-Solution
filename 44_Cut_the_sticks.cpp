#include <stdio.h>
#include <stdlib.h>

/* Comparison function for qsort */
int cmpfunc(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

/* Function: cutTheSticks */
int* cutTheSticks(int arr_count, int* arr, int* result_count) {
    /* Sort the array in ascending order */
    qsort(arr, arr_count, sizeof(int), cmpfunc);

    int* result = (int*)malloc(arr_count * sizeof(int));
    int res_idx = 0;

    int remaining = arr_count;
    result[res_idx++] = remaining;

    for (int i = 1; i < arr_count; i++) {
        if (arr[i] != arr[i - 1]) {
            remaining = arr_count - i;
            result[res_idx++] = remaining;
        }
    }

    *result_count = res_idx;
    return result;
}

int main() {
    int n;
    scanf("%d", &n);  // Read number of sticks

    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);  // Read each stick length
    }

    int result_count;
    int* result = cutTheSticks(n, arr, &result_count);

    for (int i = 0; i < result_count; i++) {
        printf("%d\n", result[i]);
    }

    /* Free allocated memory */
    free(arr);
    free(result);

    return 0;
}
