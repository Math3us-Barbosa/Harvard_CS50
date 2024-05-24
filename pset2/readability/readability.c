#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<cs50.h>
#include<string.h>

int main(void)
{
    //declairing variables
    int letters = 0, sentences = 0;
    float words = 1;


    string T = get_string("text: ");
    //loop to analyse each character of the string until it's over
    for (int i = 0, n = strlen(T); i < n; i++)
    {
        if (isalpha(T[i]))
        {
            letters++;
        }
        else if (isspace(T[i]))
        {
            words++;
        }
        else if (T[i] == '.' || T[i] == '!' || T[i] == '?')
        {
            sentences++;
        }


    }
    //calculating the  average number of Letters(L) and Sentences(S) per 100 words
    float L = (letters / words) * 100;
    float S = (sentences / words) * 100;
    //calculating the index by the formula
    int index = round(0.0588 * L - 0.296 * S - 15.8);
    // showing the results
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}
