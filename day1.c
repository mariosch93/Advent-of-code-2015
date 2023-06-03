#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *input_file = fopen("day1_input.txt", "r");

    int floor = 0;
    long int basement = 0;
    while (1)
    {
        char ch = fgetc(input_file);

        if (feof(input_file))
        {
            break;
        }
        if (ch == '(')
        {
            floor = floor + 1;
        }
        else if (ch == ')')
        {
            floor = floor - 1;
        }
        if (floor == -1 && basement == 0)
        {
            basement = ftell(input_file);
        }
    }
    printf("The floor that santa goes is: %d \n", floor);
    printf("The moment that santa went to basement is: %d \n", basement);

    fclose(input_file);
    return 0;
}
