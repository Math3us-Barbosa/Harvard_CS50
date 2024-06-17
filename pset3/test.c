#include <time.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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
    bool end1 = false, end2 = false;
    int* temp = malloc(max*sizeof(int));
    for(int i =0; i < max; i++)
    {
        if(!end1 && !end2)
        {
            if(v[p1] < v[p2])
            {
                temp[i] = v[p1];
                p1++;
            }
            else
            {
                temp[i] = v[p2];
                p2++;
            }
            if(p1>mid)
                end1 = true;
            if(p2 > right)
                end2 = true;
        }
        else{
            if(end1)
            {
                temp[i] = v[p2];
                p2++;
            }
            if(end2)
            {
                temp[i] = v[p1];
                p1++;
            }
        }

    }

    for(int i = 0, k = left; i < max; i++,k++)
    {
        v[k] = temp[i];
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
