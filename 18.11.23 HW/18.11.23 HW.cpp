#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <stdio.h>
#include <iostream>
#include <ctype.h>

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    const char* input_file = "input_Caesar.txt";
    const char* output_file = "output_Caesar.txt";
    int key = 3;

    FILE* in = fopen(input_file, "r");
    FILE* out = fopen(output_file, "w");

    if (!in || !out) {
        printf("Unable to open the file.\n");
        return 1;
    }

    int ch;
    while ((ch = fgetc(in)) != EOF) {
        if (isalpha(ch)) {
            char offset = (ch >= 'a' && ch <= 'z') ? 'a' : 'A';
            ch = (ch - offset + key) % 26 + offset;
        }
        fputc(ch, out);
    }

    fclose(in);
    fclose(out);

    FILE* read_out = fopen(output_file, "r");
    if (!read_out) {
        printf("Unbale to open the file for reading.\n");
        return 1;
    }

    printf("Output file contains:\n");
    while ((ch = fgetc(read_out)) != EOF) {
        putchar(ch);
    }

    fclose(read_out);

    return 0;
}