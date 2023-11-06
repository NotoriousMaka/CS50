#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    int start_size = 0;
    do
    {
        start_size = get_int("Enter the start size of the population: ");
    }
    while (start_size < 9);

    // TODO: Prompt for end size
    int end_size = 0;
    do
    {
        end_size = get_int("Enter the end size of the population: ");
    }
    while (end_size < start_size);

    // TODO: Calculate number of years until we reach threshold
    int years = 0;
    while (end_size > start_size)
    {
        start_size = start_size + (start_size / 3) - (start_size / 4);
        years++;
    }
    // TODO: Print number of years
    printf("Years: %i\n", years);
}
