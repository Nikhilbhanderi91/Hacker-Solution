#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to trim left spaces
char* ltrim(char* str) {
    while (*str && isspace(*str)) str++;
    return str;
}

// Function to trim right spaces
char* rtrim(char* str) {
    char* end = str + strlen(str) - 1;
    while (end >= str && isspace(*end)) end--;
    *(end + 1) = '\0';
    return str;
}

// Function to split a string by space
char** split_string(char* str) {
    char** splits = NULL;
    char* token = strtok(str, " ");
    int count = 0;

    while (token) {
        splits = (char**) realloc(splits, sizeof(char*) * (count + 1)); // Cast added
        if (!splits) {
            perror("realloc failed");
            exit(EXIT_FAILURE);
        }
        splits[count++] = token;
        token = strtok(NULL, " ");
    }

    return splits;
}

// Function to parse integer
int parse_int(char* str) {
    char* endptr;
    int value = strtol(str, &endptr, 10);
    if (endptr == str || *endptr != '\0') exit(EXIT_FAILURE);
    return value;
}

// Function to compute library fine
int libraryFine(int d1, int m1, int y1, int d2, int m2, int y2) {
    if (y1 > y2) return 10000;
    if (y1 < y2) return 0;
    if (m1 > m2) return 500 * (m1 - m2);
    if (m1 < m2) return 0;
    if (d1 > d2) return 15 * (d1 - d2);
    return 0;
}

int main() {
    // Read input for actual return date
    char line1[50];
    fgets(line1, sizeof(line1), stdin);
    char** actual = split_string(rtrim(ltrim(line1)));
    int d1 = parse_int(actual[0]);
    int m1 = parse_int(actual[1]);
    int y1 = parse_int(actual[2]);

    // Read input for expected return date
    char line2[50];
    fgets(line2, sizeof(line2), stdin);
    char** expected = split_string(rtrim(ltrim(line2)));
    int d2 = parse_int(expected[0]);
    int m2 = parse_int(expected[1]);
    int y2 = parse_int(expected[2]);

    // Compute and print fine
    int fine = libraryFine(d1, m1, y1, d2, m2, y2);
    printf("%d\n", fine);

    // Free memory
    free(actual);
    free(expected);

    return 0;
}
