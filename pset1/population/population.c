#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    //declaring variables
    int s, e, c = 0;
    do //loop to get a start vallue > 9
    {
        s = get_int("start size: ");
    }
    while (s < 9);
    do // loop to make sure that the end vallue >= start vallue
    {
        e = get_int("end size: ");
    }
    while (e < s);
    //loop to do the maths and see the years to get to the end vallue
    while (s < e)
    {
        c++;
        s = s + (s / 3) - (s / 4);
    }
    printf("Years: %i\n", c);
}
