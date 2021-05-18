#include<stdio.h>

void combSort(int v[], int n)
{
    int step = n, i, j, k, again = 1;

    // Fase 1
    while( (step = int(step / 1.3)) > 1)
        for(j = n -1; j >= step; j--)
    {
        k = j - step;
        if(v[j] < v[k])
            //trocar v[j] com v[k]
    }

    //Fase 2
    for(i = 0; i < n - 1 && again; i++)
        for(j = n - 1, again = 0; j > i; j--)
            if(v[j] < v[j - 1])
            {
              //trocar v[j] com v[j-1]
              again = 1;
            }
} // Fim combSort
