#include <stdio.h>
#include <stdlib.h>
#include <vector>
using namespace std;

void combSort(int *v, int n, int *comp, int *mov);

int main()
{
    FILE *f;
    int *v = NULL;
    vector<int> vet;
    char arq_valores[30];
    int n, item, comp = 0, mov = 0;
    scanf("%s", arq_valores);
    f = fopen(arq_valores, "r");
    fscanf(f, "%d", &item);

    while (!feof(f))
    {
        vet.push_back(item);
        fscanf(f, "%d", &item);
    }

    n = vet.size();

    v = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
        v[i] = vet[i];

    combSort(v, n, &comp, &mov);

    fclose(f);

    printf("%d %d", comp, mov);

    return 0;
}

void combSort(int *v, int n, int *comp, int *mov)
{
    int step = n, i, j, k, again = 1, aux;

    while ((step = int(step / 1.3)) > 1)
        for (j = 0; j < (n)-step; j++)
        {
            k = step + j;
            (*comp)++;

            if (v[j] > v[k])
            {
                (*mov)++;

                aux = v[j];
                v[j] = v[k];
                v[k] = aux;

                printf("%d %d\n", j, k);
            }
        }

    for (i = 0; i < n - 1 && again; i++)
    {
        for (j = n - 1, again = 0; j > i; j--)
        {
            (*comp)++;
            if (v[j] < v[j - 1])
            {
                aux = v[j];
                v[j] = v[j - 1];
                v[j - 1] = aux;

                printf("%d %d\n", j - 1, j);

                (*mov)++;
                again = 1;
            }
        }
    }
}
