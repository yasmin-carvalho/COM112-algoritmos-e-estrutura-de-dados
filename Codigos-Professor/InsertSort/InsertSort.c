#include<stdio.h>
#include<stdlib.h>

/* ALGORITMO DE ORDENAÇÃO SELECTIONSORT */
void insertionSort(int v[], int n);
int menor(int a, int b);
void troca(int v[], int i, int j);

int t = 0;//troca
int c = 0; // comparçoes

int main()
{
    int v[10] = {1, 2, 3, 6, 5, 4, 3, 2, 1, 0};
    int n = 10, i;

    insertionSort(v, n);

    // imprime
    for(i=0; i<n; i++)
        printf("%d", v[i]);

        printf("\nTrocas = %d\n", t);
        printf("\nComparacoes = %d\n", c);


    return 0;
}

void insertionSort(int v[], int n)
{
    int i, j, aux;

    // insertion sort
    for(i=1; i < n; i++)
        for(j=i; j > 0 && menor(v[j], v[j-1]); j--)
            troca(v, j, j - 1);

}

//(USE NO DECORRER DA DISCIPLINA)
int menor(int a, int b)
{
    c++;
    return (a < b); // 0 ou 1 = falso ou verdadeiro
}

void troca(int v[], int i, int j)
{
    int aux;
    aux = v[i];
    v[i] = v[j];
    v[j] = aux;
    t++;
}
