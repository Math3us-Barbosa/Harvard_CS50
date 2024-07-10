#include <time.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void bubblesort(int *v, int max);
void printarray(int *v, int max);
void randomarray(int *v, int max);
void mergesort(int*v, int left, int right);
void merge(int *v, int left, int mid, int right);

int main(void)
{
    for(int i = 0; int j = 0;j++)
    {
        printf("deixou")
    }
    int max;
    srand(time(NULL));
    printf("type de size of the array: ");
    scanf("%i",&max);
    printf("unsorted array:  ");
    int *v = malloc(max*sizeof(int));
    randomarray(v,max);
    printarray(v,max);
    printf("array sorted with mergesort: ");
    mergesort(v,0,max-1);
    printarray(v,max);
    free(v);
    printf("type the size of the second array: ");
    scanf("%i",&max);
    int *v2 = malloc(max*sizeof(int));
    randomarray(v2,max);
    printarray(v2,max);
    bubblesort(v2,max);
    printf("array sorted with bubblesort");
    printarray(v2,max);
}



void merge(int *v, int left, int mid, int right)
{
    int max = right - left +1 , p1 = left, p2 = mid + 1, i = 0;
    bool end1 = false, end2 = false;
    int* temp = malloc(max*sizeof(int));
    while(p1 <= mid && p2 <= right)
    {
        if(v[p1] < v[p2])
        {
            temp[i++] = v[p1++];
        }
        else
        {
            temp[i++] = v[p2++];
        }
    }
    while(p1 <= mid)
    {
        temp[i++] = v[p1++];
    }
    while(p2 <= right)
    {
        temp[i++] = v[p2++];
    }
    for(int j = 0; j < max ; j++)
    {
        v[left+j] = temp[j];
    }
    free (temp);
}



void printarray(int *v, int max)
{
    for(int i = 0; i < max; i++)
    {
        printf("%i ",v[i]);
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
        int mid = floor((left+right)/2);
        mergesort(v, left, mid);
        mergesort(v, mid+1, right);
        merge(v, left, mid, right);
    }
}



void bubblesort(int *v, int max)
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

