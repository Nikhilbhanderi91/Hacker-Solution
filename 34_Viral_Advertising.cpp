#include <stdio.h>
#include <stdlib.h>

// Function to calculate total cumulative likes
int viralAdvertising(int n) {
    int shared = 5;          // Initial shares on day 1
    int cumulativeLikes = 0; // Total likes

    for (int day = 1; day <= n; day++) {
        int likes = shared / 2;    // Half of recipients like the post
        cumulativeLikes += likes;  // Update total likes
        shared = likes * 3;        // Each liker shares with 3 friends
    }

    return cumulativeLikes;
}

int main() {
    int n;
    scanf("%d", &n);          // Read number of days

    int result = viralAdvertising(n);

    printf("%d\n", result);   // Print total cumulative likes

    return 0;
}
