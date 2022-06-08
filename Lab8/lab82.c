#include <stdio.h>
#include <stdlib.h>

int ehprimo(int m)
{
    long int ehprimo;
    switch (m)
        {
        case 0:
            ehprimo = 0;
            break;
        case 1:
            ehprimo = 0;
            break;

        case 2:
            ehprimo = 1;
            break;

        default:
            ehprimo = 1;
            break;
        }
        for (long int i = 2; ehprimo && i * i <= m; i++)
        {
            if (m % i == 0)
            {
                ehprimo = 0;
            }
        }
        return ehprimo;
}

void primos(int m, int *p1, int *p2)
{
    for (int i = m-1; i >= 2; i--)
    {
        if(ehprimo(i))
        {
            *p1 = i;
            break;  
        }  
    }
    int i;
    for (i = m+1; !ehprimo(i) ; i++)
    {
    }
    *p2 = i;
}

int main()
{
    int m, p1, p2;
    scanf("%d", &m);
    primos(m, &p1, &p2);
    printf("%d\n%d", p1, p2);
}