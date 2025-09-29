#include <stdio.h>
#include <stdlib.h>


int* permutationEquation(int p_count, int* p, int* result_count) {
    *result_count = p_count;
    
    int* result = (int*)malloc(p_count * sizeof(int));
    int* indexOfValue = (int*)malloc((p_count + 1) * sizeof(int)); 
    
    for (int i = 0; i < p_count; i++) {
        indexOfValue[p[i]] = i;
    }
    
    for (int x = 1; x <= p_count; x++) {
        int firstIndex = indexOfValue[x];
        int secondIndex = indexOfValue[firstIndex + 1];
        result[x - 1] = secondIndex + 1;
    }
    
    free(indexOfValue);
    return result;
}

int main() {
    int n;
    scanf("%d", &n);
    
    int* p = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &p[i]);
    }
    
    int result_count;
    int* result = permutationEquation(n, p, &result_count);
    
    for (int i = 0; i < result_count; i++) {
        printf("%d\n", result[i]);
    }
    
    free(p);
    free(result);
    
    return 0;
}
