// Implements a dictionary's functionality

#include <stdbool.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 676;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO
    return 0;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    node n = NULL;
    int i = 0;
    char* s = malloc(20);
    char* temp =malloc(4);
    FILE *f = fopen(dictionary,"r");
    if(f == NULL)
    {
        printf("file %s not found",dictionary);
        return false;
    }
    fgets(temp,4,f);
    table[i] = 
    while(fgets(s,20,f) != NULL)
    {
        if(s[0] == temp[0] && s[1] == temp[1])
        {

        }

    }



    return false;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    return false;
}
