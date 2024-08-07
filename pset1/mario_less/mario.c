int main(void){
    //declaring variables
    int n, c = 1;
    int x = 0;
    //getting from de user a height between 1 and 8
    do{
        printf("type the pyramid height between 1 and 8\n");
        scanf("%i",&n);
    } while(n < 1 || n > 8);
    while(c <= n){
        //printing the space between the start of the line and the # of that line
        for (int j = 0; j < (n - c); j++){
            printf(" ");
        }
    //printing the # of the pyramides
        for (int i = 0; i < c; i++){
            printf("#");
        }
        c++;
    }
}
