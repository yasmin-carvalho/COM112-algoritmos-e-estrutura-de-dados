#include <stdlib.h>
#include <stdio.h>

int hoareComp = 0, hoareMov = 0, lomutoComp = 0, lomutoMov = 0, sedgewickComp = 0, sedgewickMov = 0;

void quickSortHoare(int *v, int p, int r, int *hoareComp, int *hoareMov);
void quickSortLomuto(int *v, int p, int r, int *lomutoComp, int *lomutoMov);
void quickSortSedgewick(int *v, int p, int r, int *sedgewickComp, int *sedgewickMov);
int hoareParticao(int *v, int p, int r, int *hoareComp, int *hoareMov);
int lomutoParticao(int *v, int p, int r, int *lomutoComp, int *lomutoMov);
int sedgewickParticao(int *v, int p, int r, int *sedgewickComp, int *sedgewickMov);
void troca(int *v, int i, int j, int *mov);

int main(void)
{
  int n = 0;

  scanf("%d", &n);

  int v[n];

  int y[n];

  int z[n];

  for (int i = 0; i < n; i++)
    scanf("%d", &v[i]);

  int add = 0;
  int i = 0;
  while (add <= 2)
  {
    if (add == 0)
    {
      while (i < n)
      {
        y[i] = v[i];
        i++;
      }
      quickSortHoare(v, 0, n - 1, &hoareComp, &hoareMov);
      printf("%d %d\n", hoareComp, hoareMov);
    }
    else if (add == 1)
    {
      i = 0;
      while (i < n)
      {
        z[i] = y[i];
        i++;
      }
      quickSortLomuto(y, 0, n - 1, &lomutoComp, &lomutoMov);
      printf("%d %d\n", lomutoComp, lomutoMov);
    }
    else
    {
      quickSortSedgewick(z, 0, n - 1, &sedgewickComp, &sedgewickMov);
      printf("%d %d\n", sedgewickComp, sedgewickMov);
    }
    add++;
  }
}

void quickSortHoare(int *v, int p, int r, int *hoareComp, int *hoareMov)
{
  int q = 0;
  if (p < r)
  {
    q = hoareParticao(v, p, r, hoareComp, hoareMov);
    quickSortHoare(v, p, q, hoareComp, hoareMov);
    quickSortHoare(v, q + 1, r, hoareComp, hoareMov);
  }
}

void quickSortLomuto(int *v, int p, int r, int *lomutoComp, int *lomutoMov)
{
  int q = 0;
  if (p < r)
  {
    q = lomutoParticao(v, p, r, lomutoComp, lomutoMov);
    quickSortLomuto(v, p, q - 1, lomutoComp, lomutoMov);
    quickSortLomuto(v, q + 1, r, lomutoComp, lomutoMov);
  }
}

void quickSortSedgewick(int *v, int p, int r, int *sedgewickComp, int *sedgewickMov)
{
  int q = 0;
  if (p < r)
  {
    q = sedgewickParticao(v, p, r, sedgewickComp, sedgewickMov);
    quickSortSedgewick(v, p, q - 1, sedgewickComp, sedgewickMov);
    quickSortSedgewick(v, q + 1, r, sedgewickComp, sedgewickMov);
  }
}

int hoareParticao(int *v, int p, int r, int *hoareComp, int *hoareMov)
{
  int q = v[p];
  int i = p - 1, j = r + 1;

  while (1)
  {
    do
    {
      (*hoareComp)++;

      i++;

    } while (v[i] < q);
    do
    {
      (*hoareComp)++;

      j--;

    } while (v[j] > q);

    if (i >= j)
      return j;

    troca(v, i, j, hoareMov);
  }
}

int lomutoParticao(int *v, int p, int r, int *lomutoComp, int *lomutoMov)
{
  int q = v[r], i = p - 1;

  for (int j = p; j < r; j++)
  {
    if (v[j] <= q)
    {
      i++;

      troca(v, i, j, lomutoMov);
    }
    (*lomutoComp)++;
  }

  troca(v, i + 1, r, lomutoMov);

  return i + 1;
}

int sedgewickParticao(int *v, int p, int r, int *sedgewickComp, int *sedgewickMov)
{
  int i = p, j = r + 1, piv = v[p];

  while (1)
  {
    while (v[++i] < piv)
    {
      if (i == r)
        break;

      (*sedgewickComp)++;
    }

    (*sedgewickComp)++;

    while (piv < v[--j])
    {
      if (j == p)
        break;

      (*sedgewickComp)++;
    }

    (*sedgewickComp)++;

    if (i >= j)
      break;

    troca(v, i, j, sedgewickMov);
  }

  troca(v, p, j, sedgewickMov);

  return j;
}

void troca(int *v, int i, int j, int *mov)
{
  int aux;
  aux = v[i];
  v[i] = v[j];
  v[j] = aux;
  (*mov)++;
}
