#include<stdio.h>
#include<stdlib.h>

void leVetor(int *v, int n);
void insertionSort(int *v, int n);

int main()
{
    int n;
    int *v;
    scanf("%d", &n);
    v = malloc(n * sizeof(int) );
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
    insertionSort(v, n);
    return;
}

void bubbleSort(int *v, int n)
{
    int i, j, comp = 0, troca = 0;
    for (i = 1; i <= n - 1; i++) {
        eleito = v[i];
        j = i - 1;
        while (j >= 0 && (v[j] > eleito)) {
            comp++;
            mov++;
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = eleito;
        if(j >= 0) comp++;
    }

    printf("%d ",comp);
    printf("%d ",mov);

}
