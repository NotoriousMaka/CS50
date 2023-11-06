#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    do
    {
        height = get_int("Enter the height: ");
    }
    while (height < 1 || height > 8);

    int space, hash;

    for (int i = 0; i < height; i++)
    {
        for (space = 0; space < height; space++)
        {
            if (i + space < height - 1)
            {
                printf(" ");
            }
            else
            {
                printf("#");
            }
        }
        printf("  ");
        for (space = 0; space < height; space++)
        {
            if (height - i < space + 2)
            {
                printf("#");
            }
        }
        printf("\n");
    }
}