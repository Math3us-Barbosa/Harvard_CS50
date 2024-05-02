#include<stdio.h>
#include<cs50.h>

 int main(void){
    //declaraçao de variaveis
    int n, c = 1;
    int x = 0;
    //perguntando ao usuario o tamanho da piramide e garantindo que esse seja entre 1 e 8
    do{
        printf("type the pyramid height between 1 and 8\n");
        scanf("%i",&n);
        if(n>=1 && n<=8)
            x=1;
        }
        while(x! = 1);
    while(c <= n){
        //printando o espaço entre o começo da linha e os # da respectiva linha
        for (int j = 0; j < (n - c); j++){
            printf(" ");
        }
    //printando os # da primeira piramide
        for (int i = 0; i < c; i++){
            printf("#");
        }
    //espaço entre as piramides
        printf("  ");
    //loop para printar os # da segunda piramide
        for (int k = 0; k < c; k++){
            printf("#");
        }
     // somando um no contador
        c++;
        printf("\n");
    }
 }
