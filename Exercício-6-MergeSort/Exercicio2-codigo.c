#include <stdlib.h>
#include <stdio.h>
//Função para merge sort
void mergeSort(int *v, int p, int r, int *comp, int *mov);
//Função para a intercalação
void intercala(int *v, int p, int q, int r, int *comp, int *mov);
//Função para ler vetor
void leVetor(int *v, int n);
int main()
{
  int *v = NULL;
  int n;
  int comp = 0, mov = 0;
  scanf("%d", &n);
  v = (int*)malloc(n*(sizeof(int)));
  //Chamada da função para ler o vetor
  leVetor(v, n);
  //Chamada da função para fazer o merge
  mergeSort(v, 0, n, &comp, &mov);
  printf("%d %d", comp, mov);
  free(v);
  return 0;
}

void mergeSort(int *v, int p, int r, int *comp, int *mov)
{
  if (p < r - 1)
  {
    int q = (p + r) / 2; //metade
    mergeSort(v, p, q, comp, mov);
    mergeSort(v, q, r, comp, mov);
    intercala(v, p, q, r, comp, mov);
  }
}
void intercala(int *v, int p, int q, int r, int *comp, int *mov)
{
  int i, j, k; //contadores
  int *w;      //vetor auxiliar
  w = (int *)malloc((r - p) * sizeof(int));
  i = p;
  j = q;
  k = 0;
  while (i < q && j < r)
  {
    (*mov)++;
    (*comp)++;
  
    if (v[i] <= v[j])
    {
      w[k++] = v[i++];
    }
    else
    {
      w[k++] = v[j++];
    }
    
  }

  while (i < q)
  {
    w[k++] = v[i++];
    (*mov)++;

  }
  while (j < r)
  {
    w[k++] = v[j++];
    (*mov)++;

  }

  for (i = p; i < r; i++)
  {
    v[i] = w[i - p];
    (*mov)++;

  }

  free(w);
}
void leVetor(int *v, int n)
{
  for (int i = 0; i < n; i++)
    scanf("%d", &v[i]);
}