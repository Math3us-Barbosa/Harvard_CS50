nt main(int argc, string argv[])
{
    //verificando quantidade de argumentos
    if (argc != 2)
    {
        printf("Uso: ./chave de substituição");
        return 1;
    }
    //verificando tamanho da chave
    if (strlen(argv[1]) != 26)
    {
        printf("A chave deve conter 26 caracteres");
        return 1;
    }
    // verificando caracteres da chave
    for (int i=0,n=strlen(argv[1]); i<n; i++)
    {
        if (!isalpha(argv[1][i]))
        {
        printf("Uso: ./chave de substituição");
        return 1;
        }
    }
    int x;
    int a=0;
    int n=strlen(argv[1]);
    //verificando se ha letras repitidas na string usando 2 loops
    for (x=0; x<n; x++)
    {
        a=argv[1][x];
        for (int j = n; j>x;j--)
        {
            if(argv[1][j] == a)
            {
                printf("a chave não pode conter letras repitidas");
                return 1;
            }
        }
    }
    string p = get_string("plaintext: ");
    int k = strlen(p);
    int p2[k];
    printf("ciphertext: ");

    for (int c = 0; c < k; c++)
    {
        if(isupper(p[c]))
        {
            p2[c] = p[c] - 65;
        }
        else
        {
            p2[c] = p[c] - 97;
        }
    }


    for (int i = 0; i < k; i++)
    {
        if (isupper(p[i]))
        {
            printf("%c",toupper(argv[1][p2[i]]));
        }
        else if (islower(p[i]))
        {
            printf("%c",tolower(argv[1][p2[i]]));
        }
        else
        {
            printf("%c",p[i]);
        }
    }
    printf("\n");
}


