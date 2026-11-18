#include <stdio.h>
#include <ctype.h>
#include <string.h>


    char keywords[][10] = {
        "int", "float", "char", "if", "else",
        "while", "for", "return", "void"
    };

 int isKeyword(char str[]) {
    for (int i = 0; i < 9; i++) {
        if (strcmp(str, keywords[i]) == 0)
            return 1;
    }
    return 0;
}

int main() {
    FILE *fp;
    char ch, word[50];
    int i;

    fp = fopen("input.c", "r");

    if (fp == NULL) {
        printf("File not found");
        return 0;
    }

    while ((ch = fgetc(fp)) != EOF) {

        if (ch == ' ' || ch == '\n' || ch == '\t')
            continue;

        if (ch == '/') {
            ch = fgetc(fp);

            if (ch == '/') {
                while ((ch = fgetc(fp)) != '\n');
                continue;
            }

            printf("/ -> Operator\n");
            ungetc(ch, fp);
            continue;
        }

        if (isalpha(ch)) {
            i = 0;

            while (isalnum(ch)) {
                word[i++] = ch;
                ch = fgetc(fp);
            }

            word[i] = '\0';
            ungetc(ch, fp);

            if (isKeyword(word))
                printf("%s -> Keyword\n", word);
            else
                printf("%s -> Identifier\n", word);
        }

        else if (isdigit(ch)) {
            i = 0;

            while (isdigit(ch)) {
                word[i++] = ch;
                ch = fgetc(fp);
            }

            word[i] = '\0';
            ungetc(ch, fp);

            printf("%s -> Number\n", word);
        }

        else if (strchr("+-*=<>!", ch)) {
            printf("%c -> Operator\n", ch);
        }

        else if (strchr("(){}[],;", ch)) {
            printf("%c -> Special Symbol\n", ch);
        }
    }

    fclose(fp);
    return 0;
}

