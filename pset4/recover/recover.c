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
    while(fread(buffer,size(BYTE),512,f) == 512)
    {
        
    }
    fclose(f);
    fclose(d);
    free(d);
}
/*   if(buffer[0] == 0xff && bytes[1] == 0xd8 && bytes[2] && (bytes[3] & 0xf0) == 0xe0 && cont == 0);
        {
            cont ++;
            FILE *d = fopen(destination,"w");
            sprint(d,"03i.jpeg",cont);
            fwrite(&buffer, size(BYTE), 512, d);
        }
        else if(buffer[0] != 0xff && bytes[1] != 0xd8 && bytes[2] && (bytes[3] & 0xf0) != 0xe0)
        {
            fwrite(&buffer, size(BYTE), 512, d);
        }
        else if(buffer[0] == 0xff && bytes[1] == 0xd8 && bytes[2] && (bytes[3] & 0xf0) == 0xe0 && cont != 0)
        {
            fclose(d);
            FILE *d= fopen(destination,"w");
            sprintf(d,"03i.jpeg",cont);
            fwrite(&buffer, size(BYTE), 512, d)
        }*/
