#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    string text = get_string("Text: ");

    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    float L = ((float) letters / (float) words) * 100;
    float S = ((float) sentences / (float) words) * 100;

    float index = 0.0588 * L - 0.296 * S - 15.8;
    int index_int = round(index);

    if (index_int > 16)
    {
        printf("Grade 16+\n");
    }
    else if (index_int < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %d\n", index_int);
    }
}

int count_sentences(string text)
{
    int sentences = 0;

    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }
    }

    return sentences;
}

int count_words(string text)
{
    int words = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == ' ' || text[i] == '\n' || text[i] == '\t')
        {
            if (text[i] != '.')
            {
                words++;
            }
        }
    }
    return words + 1;
}

int count_letters(string text)
{
    int letters = 0;

    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] != ' ' && text[i] != '\n')
        {
            if (!ispunct(text[i]))
            {
                letters += 1;
            }
        }
    }
    return letters;
}