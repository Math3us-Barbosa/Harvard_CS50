#include <time.h>
#include <stdio.h>
#include <stdlib.h>


void mergesort(int*v,int max);
void merge(int *v, int left, int right);
int main(void)
{
    int max;
    srand(time(NULL));
    printf("type de size of the array\n");
    scanf("%i",&max);
    printf("unsorted array:  ");
    int *v = malloc(20*sizeof(int));
    for(int i = 0; i < max; i++)
    {
        v[i] = rand()%100;
        printf("%i ",v[i]);
    }
    printf("\n");
    printf("array ordenado: ");
    mergesort(v,max);

}
void merge(int *v,int left,int right)
{
    int max = right;
    int *temp;
}


void mergesort(int*v, left,right)
{
    if(lef<right)
    {
        int medium = flooor(right-left/2)
        mergesort(v, left, medium);
        mergesort(v, medium+1, right);
        merge(v,left,right);
    }


}

