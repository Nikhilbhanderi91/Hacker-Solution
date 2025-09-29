#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* readline();
char* ltrim(char*);
char* rtrim(char*);
int parse_int(char*);

int utopianTree(int n) {
    int height = 1;
    for (int cycle = 0; cycle < n; cycle++) {
        if (cycle % 2 == 0) {
            height *= 2;
        } else {
            height += 1;
        }
    }
    return height;
}

int main() {
    int t = parse_int(ltrim(rtrim(readline())));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n = parse_int(ltrim(rtrim(readline())));
        int result = utopianTree(n);
        printf("%d\n", result);
    }
    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;
    char* data = (char*)malloc(alloc_length);

    while (1) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) break;

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') break;

        alloc_length <<= 1;
        data = (char*)realloc(data, alloc_length);
        if (!data) return NULL;
    }

    if (data_length > 0 && data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';
    }

    return data;
}

char* ltrim(char* str) {
    if (!str) return NULL;
    while (*str && isspace(*str)) str++;
    return str;
}

char* rtrim(char* str) {
    if (!str) return NULL;
    int len = strlen(str);
    while (len > 0 && isspace(str[len - 1])) {
        str[--len] = '\0';
    }
    return str;
}

int parse_int(char* str) {
    char* endptr;
    int value = strtol(str, &endptr, 10);
    if (endptr == str || *endptr != '\0') exit(EXIT_FAILURE);
    return value;
}
