#include<stdio.h>
#include<cs50.h>

 int main(void){
    //declaring variables
    int n, c = 1;
    int x = 0;
    //getting a height between 1 and 8 from the user
    do{
        printf("type the pyramid height between 1 and 8\n");
        scanf("%i",&n);
        if(n>=1 && n<=8)
            x=1;
        }
        while(x! = 1);
    while(c <= n){
        //printing the space between the start of the line and the # of that line
        for (int j = 0; j < (n - c); j++){
            printf(" ");
        }
    //printing the # of the first pyramides
        for (int i = 0; i < c; i++){
            printf("#");
        }
    //space between the pyramides
        printf("  ");
    //printing the # of the second pyramide
        for (int k = 0; k < c; k++){
            printf("#");
        }
        c++;
        printf("\n");
    }
 }
