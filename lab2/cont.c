#include <stdio.h>

int main()
{
    int inicio = 233;

    do {
        if (inicio >= 300 && inicio <= 400) {
            inicio += 3;
        }
        else {
            inicio += 5;
        }
        printf("%d"\n, inicio);
    } while (inicio < 457);
    return 0;
}