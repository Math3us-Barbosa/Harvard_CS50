#include <time.h>
#include <stdio.h>
#include <stdlib.h>

void randomarray(int *v, int max);
void mergesort(int*v,int max);
void merge(int *v, int left, int mid, int right);
int main(void)
{
    int max;
    srand(time(NULL));
    printf("type de size of the array\n");
    scanf("%i",&max);
    printf("unsorted array:  ");
    int *v = malloc(max*sizeof(int));
    randomarray(v,max);
    printf("\n");
    printf("array ordenado: ");


}
void merge(int *v, int left, int mid, int right)
{
    int max = right - left +1 , p1 = left, p2 = mid + 1;
    int *temp = malloc(max*sizeof(int));
    for(int i =0; i <max; i++)
    {
        if(v[p1] < v[p2])
        {
            temp[i] = v[p1];
        }
        else
        {
            temp[i] = v[p2];
        }
    }
    for(int i = 0; i < tamanho; i++)
    {
        v[i] = temp[i];
    }

}

void randomarray(int *v,max)
{
    for(int i = 0; i < max; i++)
    {
        v[i] = rand()%100;
        printf("%i ",v[i]);
    }
}

void mergesort(int*v, left,right)
{
    if(lef<right)
    {
        int medium = flooor(right-left/2)
        mergesort(v, left, medium);
        mergesort(v, mid+1, right);
        merge(v, left, mid, right);
    }


}

void()
