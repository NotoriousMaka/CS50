#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "wav.h"

int check_format(WAVHEADER header);
int get_block_size(WAVHEADER header);

int main(int argc, char *argv[])
{
    // Ensure proper usage
    if (argc != 3)
    {
        printf("You need to have two command-line arguments.\n");
        return 1;
    }

    // Open input file for reading
    char *inputfile = argv[1];
    char *outputfile = argv[2];

    FILE *input = fopen(inputfile, "r");
    if (input == NULL)
    {
        printf("Wrong input.\n");
        fclose(input);
        return 1;
    }

    // Read header
    WAVHEADER fileheader;

    fread(&fileheader, sizeof(WAVHEADER), 1, input);

    // Use check_format to ensure WAV format
    if (check_format(fileheader) != 0)
    {
        printf("Incorrect file format.\n");
        return 2;
    }

    // Open output file for writing
    FILE *output = fopen(outputfile, "w");

    if (output == NULL)
    {
        printf("Could not output file.\n");
        fclose(output);
        fclose(input);
        return 1;
    }

    // Write header to file
    fwrite(&fileheader, sizeof(WAVHEADER), 1, output);

    // Use get_block_size to calculate size of block
    int sizeBlock = get_block_size(fileheader);

    // Write reversed audio to file
    BYTE buffer[sizeBlock];
    for (fseek(input, 0 - sizeBlock, SEEK_END); ftell(input) > sizeof(fileheader) - sizeBlock;
         fseek(input, 0 - (sizeBlock * 2), SEEK_CUR))
    {
        fread(&buffer, sizeBlock, 1, input);
        fwrite(&buffer, sizeBlock, 1, output);
    }

    fclose(input);
    fclose(output);
    return 0;
}

int check_format(WAVHEADER header)
{
    if (header.format[0] == 'W' && header.format[1] == 'A' && header.format[2] == 'V' && header.format[3] == 'E')
    {
        return 0;
    }
    return 1;
}

int get_block_size(WAVHEADER header)
{
    int blockSize = header.numChannels * (header.bitsPerSample / 8);

    return blockSize;
}