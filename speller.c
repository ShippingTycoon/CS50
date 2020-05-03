https://cs50.harvard.edu/x/2020/psets/5/speller/


// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <strings.h>
#include <string.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

unsigned int counter = 0;
bool loaded = false;

// Number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N]; //not using malloc to assign space, could use malloc?

// Returns true if word is in dictionary else false
bool check(const char *word)
{

    char wordlower[LENGTH + 1];

    for (int i = 0; i <= LENGTH; i++)
    {
        wordlower[i] = '\0';
    }

    if (word[0] == '\0')
    {
        return false;
    }

    for (int i = 0; word[i] != '\0'; i++)
    {
        wordlower[i] = tolower(word[i]);
    }

    int index = hash(word);

    node *tmp = NULL;

    tmp = table[index];

    if (table[index]->word[0] == '\0')
    {
        return false;
    }

    while (strcasecmp(wordlower, tmp->word) != 0)
    {
        if (tmp->next == NULL)
        {
            return false;
        }

        tmp = tmp->next;
    }
    if (strcasecmp(wordlower, tmp->word) == 0)
    {
        return true;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    return (tolower(word[0]) - 97) % 25;

}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    for (int i = 0; i < N; i++)
    {
        table[i] = NULL;
    }
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        return false;
    }

    char buffer[LENGTH + 1];

    while (fscanf(file, "%s", buffer) != EOF)
    {
        node *n = malloc(sizeof(node));

        if (n == NULL)
        {
            return false;
        }

        strcpy(n->word, buffer);

        n->next = NULL;

        int index = hash(n->word);



        n->next = table[index];
        table[index] = n;

        counter++;
    }
    loaded = true;
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    if (loaded == true)
    {
        return counter;
    }
    else
    {
        return 0;
    }
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    node *cursor = NULL;
    for (int j = 0; j <= 25; j++)
    {
        cursor = table[j];
        if (cursor != NULL)
        {
            while (cursor != NULL)
            {
                node *tmp = NULL;
                tmp = cursor;
                cursor = cursor->next;
                free(tmp);
            }
        }
        table[j] = NULL;
    }
    free(cursor);
    return true;
}
