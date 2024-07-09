// Implements a dictionary's functionality
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "dictionary.h"
#define N 676
// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table

//global counter for how many words are in the hash table
int siz = 0;
//global variable that defines if the dictionary is stored(0 for loaded 1 for unloaded)
int loaded = 1;
// Hash table
node *table[N];
// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    int  max = strlen(word);
    char *s = malloc(max+1);
    if(s == NULL)
    {
        printf("out of memory\n");
        return false;
    }
    for(int i = 0; i < max; i++)
    {
        s[i] = tolower(word[i]);
    }
    int i = hash(s);
    for(node *tmp = table[i]; tmp != NULL; tmp = tmp->next)
    {
        if(strcmp((tmp->word),s) == 0)
        {
            free(s);
            return true;
        }
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO
    int number;
    if(isalpha(word[1]))
    {
        number = ((word[0] - 96) * (word[0] - 97)) + (word[1] - 96) - 1;
    }
    else{
        number = (word[0] - 96) * (word[0] - 97);
    }
    printf("%i\n",number);
    return number;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    int i = 0;
    char ch;
    int index;
    //char* s = malloc(46);
    FILE *f = fopen(dictionary,"r");
    if(f == NULL)
    {
        printf("file %s not found",dictionary);
        return false;
    }
    node*n = malloc(sizeof(node));
    for(node*n = malloc(sizeof(node);(n->word[i] = fgetc(f)) != EOF);)
    {
        bool word_loaded = false;
        if(isalpha(ch))
        {
            n->word[i] = ch;
            i++;
        }
        else if(ch == '\n')
        {
            node *n1 = malloc(sizeof(node));
            if(n1 == NULL)
            {
                printf("out of memory \n");
                return false;
            }
            int j = 0;
            n->word[i] = '\0';
            i = 0;
            n-> next = NULL;
            index = hash(n->word);
            for(node *tmp = table[index];j < 1;tmp = tmp->next)
            {
                if(tmp == NULL)
                {
                    if(siz == 0)
                        tmp = n;
                    else
                        tmp = n1;
                    siz++;
                    j++;
                    word_loaded = true;
                    printf("%s",tmp->word);
                }
            }
            if(word_loaded == false)
            {
                return false;
            }
        }

    }
    free(s);
    loaded = 0;
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    if(loaded == 0)
    {
        printf("\n%i\n",siz);
        return siz;
    }
    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for(int i = 0; i < N;i++)
    {
        while(table[i] != NULL)
        {
            node *tmp = table[i];
            table[i]= tmp->next;
            free(tmp);
        }
    }
    return false;
}
