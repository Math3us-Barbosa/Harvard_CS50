// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;
typedef uint8_t BYTE;
typedef uint8_t BYTES2;
int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }
    float factor = atof(argv[3]);
    BYTE buffer1[44];
    BYTES2 buffer2;
    fread(buffer1,sizeof[BYTE],44,input);
    fwrite(buffer1,sizeof[BYTE],44,output);
    while(fread(buffer2,sizeof[BYTES2],1,input))
    {
        fwrite(buffer2 * factor,sizeof[BYTES2],1,output);
    }

    // Close files
    fclose(input);
    fclose(output);
}
