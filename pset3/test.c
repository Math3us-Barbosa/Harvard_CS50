#include <time.h>
#include <stdio.h>
#include <stdlib.h>


//void mergesort(int*v,int max);
int number(int x);
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
        printf("%i",v[i]);
    }
    printf("\n");
    printf("array ordenado: ");

}

int number(int x)
{
    x = 4;
    return x;
}




/*void mergesort(int*v)
{
    if(max == 1)
    {
        return
    }
    int v1;
    int v2;
    for int(int i = 0; i < max; i++)
    {
        if(i < max/2)
        {
            v1[i] = v[i]
        }
        else
        {
            v2[i] = v[i]
        }
    }


}
*/
