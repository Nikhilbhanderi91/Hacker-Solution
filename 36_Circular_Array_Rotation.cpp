#include <stdio.h>
#include <stdlib.h>

int* circularArrayRotation(int* a, int n, int k, int* queries, int q, int* result_count) {
    *result_count = q;
    int* result = (int*)malloc(q * sizeof(int)); 
    k = k % n;

    for (int i = 0; i < q; i++) {
        int index = (queries[i] - k + n) % n; 
        result[i] = a[index];
    }

    return result;
}

int main() {
    int n, k, q;
    scanf("%d %d %d", &n, &k, &q);

    int* a = (int*)malloc(n * sizeof(int));     
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    int* queries = (int*)malloc(q * sizeof(int));
    for (int i = 0; i < q; i++) scanf("%d", &queries[i]);

    int result_count;
    int* result = circularArrayRotation(a, n, k, queries, q, &result_count);

    for (int i = 0; i < result_count; i++) {
        printf("%d\n", result[i]);
    }

    free(a);
    free(queries);
    free(result);

    return 0;
}
