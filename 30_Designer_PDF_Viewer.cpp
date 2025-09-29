#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int designerPdfViewer(int h_count, int* h, char* word) {
    int max_height = 0;
    int length = strlen(word);

    for (int i = 0; i < length; i++) {
        int index = word[i] - 'a';
        if (h[index] > max_height) {
            max_height = h[index];
        }
    }
    return max_height * length;
}

int main() {
    int h[26];
    for (int i = 0; i < 26; i++) {
        scanf("%d", &h[i]);
    }

    char word[100];
    scanf("%s", word);

    int result = designerPdfViewer(26, h, word);
    printf("%d\n", result);

    return 0;
}
