#include <stdio.h>

int main()
{
    int num;
    int fib[799];

    for (int i = 0; i <= 800; i++)
    {
        switch (i)
        {
        case 0:
            fib[0] = 0;
            break;
        case 1:
            fib[1] = 1;
            break;
        case 2:
            fib[2] = 1;
            break;
        default:
            break;
        }
        if (i > 2)
        {
            fib[i] = fib[i - 1] + fib[i - 2];
        }
    }
    int conf=1;
    
    while (num>=0 && num<=800)
    {
        scanf("%d", &num);       
        if (num>=0 && num<=800)
            printf("%d\n", fib[num]); 
            else break;
    }
    return 0;
}