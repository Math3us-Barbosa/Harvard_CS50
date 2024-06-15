#include <time.h>
#include <stdio.h>
#include <stdlib.h>


void mergesort(int*v);

int main(void)
{
    int max;
    srand(time(NULL));
    printf("type de size of the array\n");
    scanf("%i"&max);
    printf("unsorted array:  ");
    int *v = malloc(20*sizeof(int));
    for(int i = 0; int i < max; i++)
    {
        v[i] = rand()%100;
        printf("%i",v[i]);
    }
    printf("\n");
    printf("array ordenado: ");
    mergesort(v);
}

void mergesort(int*v)
{
    if(sizeof(v) == 1)
    {
        return
    }
    int v1[sizeof(v)/2]


}
