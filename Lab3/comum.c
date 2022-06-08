#include <stdio.h>

int main()
{
    int imae;
    scanf("%d", &imae);
    int maeds[imae];
    for (int i = 0; i < imae; i++)
    {
        scanf("%d", &maeds[i]);
    }
    

    int ical;
    scanf("%d", &ical);
    int mcal[ical];
    for (int i = 0; i < ical; i++)
    {
        scanf("%d", &mcal[i]);
    }



    for(int i=0; i < imae; i++){
        for(int j=0; j < ical; j++){
            if(maeds[i]==mcal[j]) printf("%i\n",maeds[i]);
        }
    }
return 0;
}