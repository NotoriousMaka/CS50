// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 1000;

unsigned int count = 0;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    int i = hash(word);

    node *cursor = table[i];

    while (cursor != NULL)
    {
        if (strcasecmp(cursor->word, word) == 0)
        {
            return true;
        }
        cursor = cursor->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    int value = 0;

    for (int i = 0; i < strlen(word); i++)
    {
        value = value + 37 * tolower(word[i]);
    }
    value = value % N;
    return value;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    FILE *file = fopen(dictionary, "r");

    if (file == NULL)
    {
        return false;
    }
    char newWord[LENGTH + 1];

    while (fscanf(file, "%s", newWord) != EOF)
    {
        node *newNode = malloc(sizeof(node));

        if (newNode == NULL)
        {
            return false;
        }

        strcpy(newNode->word, newWord);
        newNode->next = NULL;
        int index = hash(newWord);

        if (table[index] == NULL)
        {
            table[index] = newNode;
        }
        else
        {
            newNode->next = table[index];
            table[index] = newNode;
        }
        count++;
    }
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for (int i = 0; i < N; i++)
    {
        while (table[i] != NULL)
        {
            node *temp = table[i]->next;
            free(table[i]);
            table[i] = temp;
        }
    }
    return true;
}
