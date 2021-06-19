


void mergeSort(int *v, int p, int r)
{
    if(p < r - 1)
    {
        int q = (p + r) / 2; //metade

        mergeSort(v, p, q);
        mergeSort(v, q, r);
        intercala(v, p, q, r);
    }
}

void intercala(int *v, int p, int q, int r)
{
    int i, j, k; //contadores
    int *w; //vetor auxiliar

    w = (int *)malloc((r - p) * sizeof(int));
    i = p;
    j = q;
    k = 0;

    while(i < q && j < r)
    {
        if(v[i] <= v[j])
            w[k++] = v[i++];
        else
            w[k++] = v[j++];
    }
    while(i < q)
        w[k++] = v[i++];
    while(j < r)
        w[k++] = v[j++];

    for(i = p; i < r; i++)
        v[i] = w[i - p];

    free(w);
} // fim intercala()
