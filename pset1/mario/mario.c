#include<stdio.h>


 int main(void){
    //declaraçao de variaveis
    int n,c=1;
    int x=0;
    //perguntando ao usuario o tamanho da piramide e garantindo que esse seja entre 1 e 8
    do{
        printf("type the pyramid height between 1 and 8\n");
        scanf("%i",&n);
        if(n>=1 && n<=8)
            x=1;
        }
        while(x!=1);
    while(c<=n){
        //printando o espaço entre o começo da linha e os # da respectiva linha
        for (int j=0;j<(n-c);j++){
            printf(" ");
        }
    //loop 2 to print the # of the pyramids
        for (int i=0;i<c;i++){
            printf("#");
        }
    //doing the space between the pyramids
        printf("  ");
    //loop 3 to do print the # of the second pyramide
        for (int k=0;k<c;k++){
            printf("#");
        }
     // counter used to limit the amount of # in each line of the pyramide
        c++;
     // skipping line
        printf("\n");
    }
 }
