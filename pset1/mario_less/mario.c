int main(void){
    //declaring variables
    int n, c = 1;
    int x = 0;
    //getting from de user a height between 1 and 8
    do{
        printf("type the pyramid height between 1 and 8\n");
        scanf("%i",&n);

        while(n < 1 || n > 8);
    while(c <= n){
        //printando o espaço entre o começo da linha e os # da respectiva linha
        for (int j = 0; j < (n - c); j++){
            printf(" ");
        }
    //printando os # da primeira piramide
        for (int i = 0; i < c; i++){
            printf("#");
        }
        c++;
    }
}
