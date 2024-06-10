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
    int cont = 0;
      while(fread(&buffer,sizeof(BYTE),512,f) == 512)
    {
        if(startjpeg(buffer) && cont == 0)
        {
            FILE *d = fopen(destination.jpeg,"w");
            sprint(d,"03i.jpeg",cont);
            fwrite(&buffer, sizeof(BYTE), 512, d);
        }
        else if(!startjpeg(buffer))
        {
            fwrite(&buffer, sizeof(BYTE), 512, d);
        }
        else if(startjpeg(buffer) && cont != 0)
        {
            fclose(d);
            cont++;
            FILE *d = fopen(destination,"w");
            sprintf(d,"03i.jpeg",cont);
            fwrite(&buffer, size(BYTE), 512, d);
        }
    }

    fclose(f);
    fclose(d);
}

bool startjpeg(Byte *buffer)
{
    if(buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        return true;
    return false;
}
/*   do{
        fread(buffer,sizeof(BYTE),512,f);

    }while(!startjpeg(buffer));
    while(!f.eof)
    {

        do
        {
            fwrite(buffer,sizeof(BYTE),512,d);
            fread(buffer,sizeof(BYTE),512,f);
        }while(!startjpeg(buffer))
        cont++;
    }
*/
