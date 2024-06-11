#include <stdio.h>
#include <stdlib.h>
#include<stdint.h>
#include <cs50.h>

typedef uint8_t BYTE;
void jpg(FILE *f);
bool startjpeg(BYTE *buffer);
int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        return 1;
    }
    FILE *f = fopen(argv[1], "r");
    if (f == NULL)
    {
        return 1;
    }

    BYTE buffer[512];
    char *s = malloc(11);
    int cont = 0;
      while(fread(buffer,sizeof(BYTE),512,f) == 512)
    {
        if(startjpeg(buffer))
        {
            sprintf(s,"%03i.jpeg", cont);
            FILE *d1 = fopen(s,"w");
            fwrite(buffer, sizeof(BYTE), 512, d1);
            cont++;
            fclose(d1);
        }
        else if(!startjpeg(buffer) && cont != 0)
        {
            FILE *d2 = fopen(s,"a");
            fwrite(buffer, sizeof(BYTE), 512, destination);
            fclose(d2);
        }
    }
    free(s);
    fclose(f);
    fclose(d);
}

bool startjpeg(Byte *buffer)
{
    if(buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        return true;
    return false;
}

