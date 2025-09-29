#include <stdio.h>
#include <stdlib.h>

/* 
 * Return maximum size of subset where no two sum to multiple of k
 * Time: O(n + k)
 * Space: O(k)
 */
int nonDivisibleSubset(int k, int n, const int *s) {
    int *freq = (int*)calloc(k, sizeof(int));
    if (!freq) return 0; // safety

    // Count remainders
    for (int i = 0; i < n; i++) {
        int rem = s[i] % k;
        if (rem < 0) rem += k; // handle negatives
        freq[rem]++;
    }

    int res = 0;

    // At most one with remainder 0
    if (freq[0] > 0) res++;

    // Handle pairs of remainders
    for (int r = 1; r <= k / 2; r++) {
        if (r == k - r) {
            if (freq[r] > 0) res++;
        } else {
            res += (freq[r] > freq[k - r]) ? freq[r] : freq[k - r];
        }
    }

    free(freq);
    return res;
}

int main(void) {
    int n, k;
    if (scanf("%d %d", &n, &k) != 2) return 1;

    int *s = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) scanf("%d", &s[i]);

    int ans = nonDivisibleSubset(k, n, s);
    printf("%d\n", ans);

    free(s);
    return 0;
}
