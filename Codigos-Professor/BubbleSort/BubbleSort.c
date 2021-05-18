#include<stdio.h>
#include<stdlib.h>

void bubbleSort(int *v, int n);
void troca(int *v, int a, int b)

int main()
{
    int n = 20;
    int *v = NULL;
    int i;

    //Alocação
    v = (int *)malloc(n * sizeof(int) );

    //Preenchendo o vetor
    for(i = 0; i < n; i++)
        v[i] = (n - i);

    //bubbleSort
    bubbleSort(v, n);

    //imprimindo
    for(i=0; i < n; i++)
        printf("%d ", v[i]);


    //liberar memoria
    free(v);

    return 0;

}

void bubbleSort(int *v, int n)
{
    int i, j;
    int comp = 0, t = 0;

    for(i=0; i < n - 1; i++)
        for(j = n - 1; j > i; j--)
        {
            comp++;
            if(v[j] < v[j-1])
            {
                troca(v, j, j - 1);
                t++;
            }

        }
        printf("Comp = %d\nTroca = %d\n", comp, t);
}

void troca(int *v, int a, int b)
{
    int aux;
    aux = v[a];
    v[a] = v[b];
    v[b] = aux;
}
