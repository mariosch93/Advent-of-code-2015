#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int min_area(int a, int b, int c)
{
    int d;
    if (a > b)
    {
        d = b;
    }
    else
    {
        d = a;
    }
    if (d > c)
    {
        return c;
    }
    else
    {
        return d;
    }
}

int main()
{

    int l, w, h;
    int area = 0;
    int p1, p2, p3;
    int ribbon = 0;

    FILE *input_file = fopen("day2_input.txt", "r");
    char line[15];
    if (input_file == NULL)
    {
        perror("Error");
        return -1;
    }

    while (1)
    {
        if (fgets(line, 15, input_file) == NULL)
        {
            break;
        }
        sscanf(line, "%dx%dx%d", &l, &w, &h);
        int ma = min_area(l * w, w * h, h * l);
        int c_a = 2 * l * w + 2 * w * h + 2 * h * l;
        area = c_a + area + ma;
        p1 = l + l + h + h;
        p2 = w + w + h + h;
        p3 = l + l + w + w;
        int m_per = min_area(p1, p2, p3);
        int bow = l * w * h;
        ribbon = m_per + ribbon + bow;
    }
    printf("the area is %d", area);
    printf("ribbon=%d", ribbon);
    fclose(input_file);

    return 0;
}