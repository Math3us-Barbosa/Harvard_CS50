#include <time.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>


//void bubblesort(int *v, int max);
void printarray(int *v, int max);
void randomarray(int *v, int max);
void mergesort(int*v, int left, int right);
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
    printarray(v,max);
    printf("array ordenado com mergesort: ");
    mergesort(v,0,max-1);
    printarray(v,max);
    free(v);


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
    for(int i = 0; i < max; i++)
    {
        v[i] = temp[i];
    }
    free (temp);
}
void printarray(int *v, int max)
{
    for(int i = 0; i < max; i++)
    {
        printf("%i",v[i]);
    }
    printf("\n");
}
void randomarray(int *v,int max)
{
    for(int i = 0; i < max; i++)
    {
        v[i] = rand()%100;
    }
}

void mergesort(int*v, int left, int right)
{
    if(left<right)
    {
        int mid = floor(right-left/2);
        mergesort(v, left, mid);
        mergesort(v, mid+1, right);
        merge(v, left, mid, right);
    }


}

/*void bubblesort(int *v, int max)
{
    int aux, cont = 0;
    for(int i = 0; i < max;i++)
    {
        for(int j = 0; j < max -i; j++)
        {
            if(v[j] > v[j+1])
            {
                aux = v[j];
                v[j] = v[j+1];
                v[j+1] = aux;
            }
        }
    }
}
*/
