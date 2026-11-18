#include <stdio.h>
#include <time.h>

// Normal loop
void function1()
{
    for (int i = 0; i < 4; i++)
    {
        printf("Hello World\n");
    }
}

// Unrolled loop
void function2()
{
    printf("Hello World\n");
    printf("Hello World\n");
    printf("Hello World\n");
    printf("Hello World\n");
}

int main()
{
    clock_t t1, t2;

    // Normal loop execution
    printf("\n----- WITH LOOP -----\n");

    t1 = clock();
    function1();
    t1 = clock() - t1;

    double timetaken1 = (double)t1 / CLOCKS_PER_SEC;

    printf("Time Taken: %f seconds\n", timetaken1);


    // Unrolled loop execution
    printf("\n----- WITHOUT LOOP (UNROLLED) -----\n");

    t2 = clock();
    function2();
    t2 = clock() - t2;

    double timetaken2 = (double)t2 / CLOCKS_PER_SEC;

    printf("Time Taken: %f seconds\n", timetaken2);

    return 0;
}
