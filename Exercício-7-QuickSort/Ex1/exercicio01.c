#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct aluno
{
    char nome[100];
    char curso[4];
    int matricula;
} aluno;

void quickSort(aluno *v, int p, int r);
int particao(aluno *v, int p, int r);
void leVetor(aluno *v, char *nomeArquivo);
void imprimeVetor(aluno *v, int n);
void troca(aluno *v, int i, int j);

int main(void)
{
    int n = 0;
    FILE *f;
    aluno aux;
    aluno *v = NULL;
    char vet_arquivo[100];

    scanf("%s", vet_arquivo);

    f = fopen(vet_arquivo, "r");

    while (!feof(f))
    {
        fscanf(f, "%[^\n] %s %d", aux.nome, aux.curso, &(aux.matricula));
        n++;
    }

    v = (aluno*)malloc(n*(sizeof(aluno)));

    leVetor(v, vet_arquivo);

    quickSort(v, 0, n - 1);

    imprimeVetor(v, n);

    free(v);
    return 0;
}
void quickSort(aluno *v, int p, int r)
{
    int q;
    if (p < r)
    {
        q = particao(v, p, r);
        quickSort(v, p, q - 1);
        quickSort(v, q + 1, r);
    }
}
int particao(aluno *v, int p, int r)
{
    int i = p, j = r;
    aluno q = v[p];

    while (i < j)
    {
        while (strcmp(v[i].nome, q.nome) <= 0)
        {
            i++;
            if (i == r)
                break;
        }
        while (strcmp(v[j].nome, q.nome) > 0)
        {
            j--;
            if (j == p)
                break;
        }

        if (i < j)
            troca(v, i, j);
    }
    v[p] = v[j];
    v[j] = q;

    return j;
}
void leVetor(aluno *v, char *nomeArquivo)
{
    FILE *f;
    aluno estudante;
    int i=0;
  
    f = fopen(nomeArquivo, "r");

    fscanf(f, "%[^\t] %s %d", estudante.nome, estudante.curso, &(estudante.matricula));

    strcpy(v[i].nome, estudante.nome);
    strcpy(v[i].curso, estudante.curso);
    v[i].matricula = estudante.matricula;

    while (!feof(f))
    {
        i++;
        fscanf(f, " %[^\t] %s %d", estudante.nome, estudante.curso, &(estudante.matricula));
        strcpy(v[i].nome, estudante.nome);
        strcpy(v[i].curso, estudante.curso);
        v[i].matricula = estudante.matricula;
    }
}
void imprimeVetor(aluno *v, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%s %s %d\n", v[i].nome, v[i].curso, v[i].matricula);
    }
}
void troca(aluno *v, int i, int j)
{
    aluno aux;
    aux = v[i];
    v[i] = v[j];
    v[j] = aux;
}
