#include<stdio.h>
#include<cs50.h>

int main(void)
{
    //declarando variaveis
    long n;
    int p, c = 0, x = 0, y;
    n = get_long("n: ");
    //loop para checar validade do numero
    while (n > 0)
    {
        if (c % 2 != 0)//se impar
        {
            y = 2 * (n % 10);
            if (y >= 10)
            {
                x = x + (y % 10) + (y / 10);
            }
            if (y < 10)
            {
                x = x + y;
            }


            n = n / 10;
        }
        else if ((c % 2) == 0)//se par
        {
            x = x + (n % 10);
            n = n / 10;
        }
        //declarando os dois primeiros digitos como p
        if ((n < 100) && (n > 10))
        {
            p = n;
        }
        c++;
    }
    //condicionais para ver a qual banco o cartão pertence
    if ((x % 10) != 0)
    {
        printf("INVALID\n");
    }
    else if ((c == 15) && ((p / 10) == 3) && ((p % 10) == 4 || (p % 10) == 7))
    {
        printf("AMEX\n");
    }
    else if ((c == 16 || c == 13) && ((p / 10) == 4))
    {
        printf("VISA\n");
    }
    else if ((c == 16) && ((p / 10) == 5) && ((p % 10) <= 5) && ((p % 10) >= 1))
    {
        printf("MASTERCARD\n");
    }
    else
    {
        printf("INVALID\n");
    }
}
