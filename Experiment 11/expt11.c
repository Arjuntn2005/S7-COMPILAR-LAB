#include <stdio.h>
#include <string.h>

int main() {
    char L[10], R[10][20], s[30], st[50] = "$", in[50];
    int n, i = 0, k, p;

    printf("Number of rules: ");
    scanf("%d", &n);

    for (k = 0; k < n; k++) {
        scanf("%s", s);              // like E->E+E
        L[k] = s[0];                 // left side
        strcpy(R[k], s + 3);         // right side
    }

    printf("Input string: ");
    scanf("%s", in);

    printf("Stack\tInput\tAction\n");

    while (1) {
        printf("%s\t%s$\t", st, in + i);

        for (k = 0; k < n; k++) {    // does stack end with a right side?
            p = strlen(st) - strlen(R[k]);
            if (p >= 0 && strcmp(st + p, R[k]) == 0)
                break;
        }

        if (k < n) {                 // REDUCE
            st[p] = L[k];
            st[p + 1] = 0;
            printf("REDUCE %c->%s\n", L[k], R[k]);
        }
        else if (in[i]) {            // SHIFT
            p = strlen(st);
            st[p] = in[i++];
            st[p + 1] = 0;
            printf("SHIFT %c\n", st[p]);
        }
        else {                       // input over
            if (strlen(st) == 2 && st[1] == L[0])
                puts("ACCEPT");
            else
                puts("REJECT");
            break;
        }
    }
    return 0;
}
