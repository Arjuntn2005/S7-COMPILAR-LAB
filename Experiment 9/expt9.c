#include <stdio.h>
#include <string.h>

char result[20][20];

void display(char state[], int n)
{
    printf("\nEpsilon closure of %s = {", state);

    for (int i = 0; i < n; i++)
    {
        printf(" %s", result[i]);
    }

    printf(" }");
}

int main()
{
    FILE *in = fopen("input.dat", "r");

    char state1[20], symbol[10], state2[20];
    char states[20][20];

    int n, i, j, k, found, changed;

    if (in == NULL)
    {
        printf("input.dat not found!");
        return 1;
    }

    printf("Enter the no of states: ");
    scanf("%d", &n);

    if (n < 1 || n > 20)
    {
        printf("Invalid number of states!");
        fclose(in);
        return 1;
    }


    printf("Enter the states: ");

    for (i = 0; i < n; i++)
    {
        scanf("%19s", states[i]);
    }

    for (i = 0; i < n; i++)
    {
        j = 0;
        strcpy(result[j++], states[i]);

        do
        {
            changed = 0;
            rewind(in);

            while (fscanf(in, "%19s %9s %19s",
                          state1, symbol, state2) == 3)
            {
                if (strcmp(symbol, "e") == 0)
                {
                    found = 0;

                    for (k = 0; k < j; k++)
                    {
                        if (strcmp(result[k], state1) == 0)
                        {
                            found = 1;
                        }
                    }

                    if (found)
                    {
                        found = 0;

                        for (k = 0; k < j; k++)
                        {
                            if (strcmp(result[k], state2) == 0)
                            {
                                found = 1;
                            }
                        }

                        if (!found && j < 20)
                        {
                            strcpy(result[j++], state2);
                            changed = 1;
                        }
                    }
                }
            }

        } while (changed);

        display(states[i], j);
    }

    fclose(in);

    printf("\n");

    return 0;
}
