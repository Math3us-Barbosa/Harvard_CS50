#include <stdio.h>
#include <stdlib.h>


typedef uint8_t BYTE;
void jpg(FILE *f);
int main(int argc, char *argv[])
{
    int cont = 0;
    if(argc != 2)
    {
        return 1;
    }
    FILE *f = fopen(argv[1], "r");
    if (file == NULL)
    {
        return 1;
    }
    BYTE buffer[512];
    char *d filename = malloc(4);
    do{
        fread(buffer,sizeof(BYTE),512,f);
        if(buffer[0] == 0Xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {

        }
    }while(!f.eof);
    fclose(f);
    fclose(d);
    free(d);
}
