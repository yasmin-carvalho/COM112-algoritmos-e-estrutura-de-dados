#include<stdio.h>
#include<stdlib.h>

void leVetor(int *v, int n);
void selectionSort(int *v, int n, int *comp, int *trocar);
void trocaVet(int *v, int i, int min, int *trocar);

int main()
{
    int n;
    int *v;
    int comp = 0;
    int trocar = 0;
    scanf("%d", &n);
    v = (int *)malloc(n * (sizeof(int)));
    leVetor(v, n);
    selectionSort(v, n, &comp, &trocar);
    printf("%d %d", comp, trocar);
    free(v);
    return 0;
}

void leVetor(int *v, int n)
{
    int i;
    for(i=0; i<n; i++){
        scanf("%d", &v[i]);
    }
}

void selectionSort(int *v, int n, int *comp, int *trocar)
{
    int min, i, j;
    for(i = 0; i < n - 1; i++)
    {
        min = i;
        for(j = i + 1; j<n; j++)
        {
            (*comp)++;
            if(v[j] < v[min])
            {
                min = j;
            }
        }
        trocaVet(v, i, min, trocar);
    }

}

void trocaVet(int *v, int i, int min, int *trocar)
{
    int aux;
    aux = v[i];
    v[i] = v[min];
    v[min] = aux;
    (*trocar)++;
}
