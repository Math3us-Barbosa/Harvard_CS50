// Modifies the volume of an audio file
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;
typedef uint8_t BYTE;
typedef int16_t BYTES2;
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
    uint8_t header[HEADER_SIZE];
    int16_t buffer;
    int temp;
    //copy the header from the innput to the output file
    fread(header, sizeof(BYTE), HEADER_SIZE, input);
    fwrite(header, sizeof(BYTE), HEADER_SIZE, output);
    while(fread(&buffer,sizeof(BYTES2),1,input) == 1)
    {
        //result from the multiplication of the 2bytes segment of the audio with the float value
        float result = (float)buffer * factor;
        if (result > 32767.0) {
        buffer = 32767; // Clip to maximum value
        }
        else if (result < -32768.0) {
        buffer = -32768; // Clip to minimum value
        }
        else {
        buffer = (BYTES2)result; // Convert back to 16-bit and assign
        }
        fwrite(&buffer, sizeof(BYTES2), 1, output);
    }

    // Close files
    fclose(input);
    fclose(output);
}
