#include<stdio.h>
#include<stdlib.h>


void leVetor(int *v, int n);
void bubbleSort(int *v, int n);

int main()
{
    int n;
    int *v;
    scanf("%d", &n);
    v = (int *)malloc(n * sizeof(int) );
    leVetor(v, n);
    free(v);
    return 0;
}

void leVetor(int *v, int n)
{
    int i;
    for(i=0; i<n; i++){
        scanf("%d", &v[i]);
    }
    bubbleSort(v, n);
    return;
}

void bubbleSort(int *v, int n)
{
    int i, j;
    long long int comp = 0, t = 0, verifica=1;

    for(i=0; i < n - 1 && verifica; i++)
        for(j = n - 1, verifica = 0; j > i; j--)
        {
            comp++;
            if(v[j] > v[j-1])
            {
                int aux;
                aux = v[j];
                v[j] = v[j-1];
                v[j-1] = aux;
                t++;
                verifica = 1;
            }
        }
        for (int i = 0; i < n; i++)
            printf("%d ", v[i]);

        printf("\n%lli %lli", comp, t);
}


