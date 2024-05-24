#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <cs50.h>



int main(int argc, string argv[])
{
    int key;
    //if the user deos not type 2 arguments the program will stop and show the following message:"Usage: ./caesar key\n"
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    //turning the key from an charecter to an int value
    key = atoi(argv[1]);
    //if the user types a negative vallue the program will stop and show the following message:"Usage: ./caesar key\n"
    if (key < 0)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    //if the user doesnt type digits as the key the program will stop and show the following message:"Usage: ./caesar key\n"
    for (int i = 0, x = strlen(argv[1]); i < x; i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./caeser key\n");
            return 1;
        }
    }
    //getting plaintext
    string p = get_string("plaintext: ");
    int n = strlen(p);
    printf("ciphertext: ");
    //loop to calculate the cyphertext charecter by charecter
    for (int i = 0; i < n; i++)
    {
        if (islower(p[i]))
        {
            printf("%c", (p[i] + key) % 26 + 97);
        }
        else if (isupper(p[i]))
        {
            printf("%c", (p[i]  + key) % 26 + 65);
        }
        else
        {
            printf("%c", p[i]);
        }
    }


    printf("\n");
}
