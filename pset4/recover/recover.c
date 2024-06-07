#include <stdio.h>
#include <stdlib.h>


typedef uint8_t BYTE;
void jpg(FILE *f);
bool startjpeg(BYTE *buffer);
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

    }while();
    fclose(f);
    fclose(d);
    free(d);
}

bool startjpeg(Byte *buffer)
{
    for in
}
