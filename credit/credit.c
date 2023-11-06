#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long card_no;
    string str[256];
    sprintf(str, "%ld", card_no);
    int sum = 0, card_no_length = str.length();
    bool secondChar = false;

    card_no = get_long("Enter the card number: ");

    while (card_no > 0)
    {
        for (int i = card_no_length - 1; i >= 0; i--)
        {
            int d = card_no[i] - '0';

            if(secondChar == true)
            {
                d = d * 2;
            }

            sum = d / 10;
            sum = d % 10;

            secondChar = !secondChar;
        }
    }

    if (sum % 10 == 0)
    {
        printf("%s, %s", str[0], str[1]);
    }
    else
    {
        printf("INVALID\n");
    }
}