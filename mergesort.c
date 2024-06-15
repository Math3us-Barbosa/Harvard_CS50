#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int max;
    srand(time(NULL));
    printf("digite o tamanho do vetor\n");
    scanf("%i"&max);
    int *v = malloc(20*sizeof(int));
    for(int i = 0; int i < max; i++)
    {
        v[i] = rand()%100
    }


}
