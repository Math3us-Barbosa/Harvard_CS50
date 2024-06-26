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
//global counter for how many words are in the hash table
int size = 0;
int loaded = 1;
// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    int i = hash(word);
    for(node *tmp = table[i]; tmp != NULL; tmp = tmp->next)
    {
        if(strcmp((tmp->word),s) == 0)
        {
            return true;
        }
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO
    int number = ((word[0]-96) * (word[1]-96)) - 1;
    return number;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    int index;
    node *n = malloc(sizeof(node));
    if(n == NULL)
    {
        return false;
    }
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

    while(fgets(s,20,f) != NULL)
    {
        bool word_loaded = false;
        node *n = malloc(sizeof(node));
        if(n == NULL)
        {
            return false;
        }
        n-> word = s;
        n-> next = NULL;
        index = hash(s);
        for(node *tmp = table[index], int i = 0;i < 1;tmp = tmp->next)
        {
            if(tmp == NULL)
            {
                tmp = n;
                i++;
                size++;
                word_loaded = true;
            }
        }
        if(word_loaded == false)
        {
            return false
        }
    }
    loaded = 0;
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    if(loaded = 0)
    {
        return size;
    }
    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    return false;
}
