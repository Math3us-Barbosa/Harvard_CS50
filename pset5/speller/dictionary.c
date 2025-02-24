// Implements a dictionary's functionality
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "dictionary.h"
#define N 17576
// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table

//global counter for how many words are in the hash table
int word_length;
int siz = 0;
//global variable that defines if the dictionary is stored(0 for loaded 1 for unloaded)
int loaded = 1;
// Hash table
node *table[N];
// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    int max = strlen(word);
    char *s = malloc(max+1);

    if(s == NULL)
    {
        printf("out of memory\n");
        return false;
    }
    for(int i = 0; i < max; i++)
    {
        if(isalpha(word[i]))
            s[i] = tolower(word[i]);
        else if(word[i] == '\'' && isalpha(word[i-1]) && isalpha(word[i+1]) && (i + 1) < max)
            {
            s[i] = word[i];
            }
        else
        {
            free(s);
            return false;
        }
    }
    s[max] = '\0';
    word_length = max;
    int j = hash(s);
    for(node *tmp = table[j]; tmp != NULL; tmp = tmp->next)
    {
        if(strcmp((tmp->word),s) == 0)
        {
            free(s);
            return true;
        }
    }
    free(s);
    return false;
}
void initialize_table(void)
{
    // Initialize the table to NULL using memset
    memset(table, 0, sizeof(table));
}


// Hashes word to a number
unsigned int hash(const char *word)
{
    int number = 0;
    if(isalpha(word[2]) && word[1] != 39 && word_length > 2)
    {
        number = ((word[2] - 97) * 26 * 26) + ((word[1] - 97) * 26) + (word[0] - 97);
    }
    else if(isalpha(word[2]) && word[1] == 39 && word_length > 2)
    {
        number =((word[2] - 97) * 26 * 26) + (word[0] - 97);
    }
    else if(isalpha(word[1]) && word_length == 2)
    {
        number = ((word[1] - 97) * 26 *26) + ((word[0] - 97) * 26);
    }
    else if (isalpha(word[0]) && word_length == 1)
    {
        number = (word[0] - 97) * 26 * 26;
    }
    return number;
}


// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    initialize_table();
    int i = 0;
    char ch;
    int index;
    char *s = malloc(LENGTH +1);
    if(s == NULL)
    {
        printf("out of memory");
        return false;
    }
    FILE *f = fopen(dictionary,"r");
    if(f == NULL)
    {
        printf("file %s not found",dictionary);
        free(s);
        return false;
    }
    while((ch = fgetc(f)) != EOF )
    {
        loaded = 1;
        if(isalpha(ch) || ch == 39)
        {
            s[i] = ch;
            i++;
        }
        else if(ch == '\n')
        {
            s[i] = '\0';
            node *n = malloc(sizeof(node));
            if(n == NULL)
            {
                printf("out of memory \n");
                free(s);
                fclose(f);
                return false;
            }
            n -> next = NULL;
            strcpy(n->word,s);
            word_length = i;
            index = hash(n->word);
            i = 0;
            n->next = table[index];
            table[index] = n;
            siz++;
        }

    }
    loaded = 0;
    free(s);
    fclose(f);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    if(loaded == 0)
    {
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
    return true;
}
