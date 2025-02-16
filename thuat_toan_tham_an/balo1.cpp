#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct
{
    char TenDV[20];
    float TL, GT, DG;
    int So_DV_Duoc_Chon;
} DoVat;

DoVat *ReadFromFile(float *w, int *n)
{
    FILE *f;
    f = fopen("caibalo1.txt", "r");
    fscanf(f, "%f", w);
    DoVat *dsdv;
    dsdv = (DoVat *)malloc(sizeof(DoVat));
    int i = 0;
    while (!feof(f))
    {
        fscanf(f, "%f%f%[^\n]", &dsdv[i].TL, &dsdv[i].GT, &dsdv[i].TenDV);
        dsdv[i].DG = dsdv[i].GT / dsdv[i].TL;
        dsdv[i].So_DV_Duoc_Chon = 0;
        i++;
        dsdv = (DoVat *)realloc(dsdv, sizeof(DoVat) * (i + 1));
    }
    *n = i;
    fclose(f);
    return dsdv;
}
void InDSDV(DoVat *dsdv, int n, float w)
{
    int i;
    float TongTL = 0.0, TongGT = 0.0;
    printf("%f", w);
    printf("\nPhuong an thu duoc tu ky thuat THAM AN nhu sau:\n");
    printf("|---|-------------------|----------|----------|------------|------------------|\n");
    printf("|STT|    Ten Do Vat     | T.Luong  | Gia Tri  | Don Gia    | So DV duoc chon  |\n");
    for (i = 0; i < n; i++)
    {
        printf("|%-3d|%-20d|%10.2f|%10.2f|%10.2f|%8d    |\n", i + 1, dsdv[i].TL, dsdv[i].GT, dsdv[i].DG, dsdv[i].So_DV_Duoc_Chon);
        TongTL = TongTL + dsdv[i].So_DV_Duoc_Chon * dsdv[i].TL;
        TongGT = TongGT + dsdv[i].So_DV_Duoc_Chon * dsdv[i].GT;
    }
    printf("|---|-------------------|----------|----------|------------|-------------------|\n");
    printf("\nTrong luong cua ba lo - %-9.2f\n", w);
    printf("\nTong trong luong cac vat duoc chon= %-9.2f\n\nTong gia tri = %-9.2f\n", TongTL, TongGT);
}
void Swap(DoVat *x, DoVat *y)
{
    DoVat temp = *x;
    *x = *y;
    *y = temp;
}

void Bubble_Sort(DoVat *dsdv, int n)
{
    int i, j;
    for (i = 0; i <= n - 2; i++)
    {
        for (j = n - 1; j >= i + 1; j--)
        {
            if (dsdv[j].DG > dsdv[j - 1].DG)
                Swap(&dsdv[j], &dsdv[j - 1]);
        }
    }
}
void Greedy(DoVat *dsdv, int n, float w)
{
    int i;
    for (i = 0; i < n; i++)
    {
        dsdv[i].So_DV_Duoc_Chon = (w / dsdv[i].TL);
        w = w - dsdv[i].So_DV_Duoc_Chon * dsdv[i].TL;
    }
}

int main()
{
    int n;
    float w;
    DoVat *dsdv;
    dsdv = ReadFromFile(&w, &n);
    Bubble_Sort(dsdv, n);
    Greedy(dsdv, n, w);
    InDSDV(dsdv, n, w);
    free(dsdv);
    return 0;
}