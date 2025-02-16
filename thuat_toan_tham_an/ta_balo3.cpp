#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct
{
    char TenDV[20];
    float TL, GT, DG;
    int PA;
} DoVat;

DoVat *ReadFromFile(float *W, int *n)
{
    FILE *f;
    f = fopen("caibalo3.txt", "r");
    fscanf(f, "%f", W); // Xac dinh trong luong Ba lo
    DoVat *dsdv;
    dsdv = (DoVat *)malloc(sizeof(DoVat)); // Lúc đầu cấp phát bộ nhớ cho 1 phần tử
    int i = 0;
    while (fscanf(f, "%f%f%[^\n]", &dsdv[i].TL, &dsdv[i].GT, dsdv[i].TenDV) == 3) // Đọc từng dòng 3 phần
    {
        if (dsdv[i].TL == 0)
            continue; // Kiểm tra trường hợp TL bằng 0 tránh chia cho 0
        dsdv[i].DG = dsdv[i].GT / dsdv[i].TL;
        dsdv[i].PA = 0;
        i++;
        dsdv = (DoVat *)realloc(dsdv, sizeof(DoVat) * (i + 1)); // Cấp phát lại bộ nhớ khi cần thêm phần tử
    }
    *n = i;
    fclose(f);
    return dsdv;
}

void swap(DoVat *x, DoVat *y)
{
    DoVat Temp;
    Temp = *x;
    *x = *y;
    *y = Temp;
}

void BubbleSort(DoVat *dsdv, int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = n - 1; j > i; j--)
        {
            if (dsdv[j].DG > dsdv[j - 1].DG)
                swap(&dsdv[j], &dsdv[j - 1]);
        }
}

void InDSDV(DoVat *dsdv, int n, float W)
{
    int i;
    float TongTL = 0.0, TongGT = 0.0;
    printf("\nPhuong an Cai Ba lo 2 dung thuat toan NHANH CAN nhu sau:\n");
    printf("\nTrong luong cua ba lo = %-9.2f\n", W);
    printf("|---|--------------------|---------|---------|---------|-----------|\n");
    printf("|STT|     Ten Do Vat     |T. Luong | Gia Tri | Don gia | Phuong an |\n");
    printf("|---|--------------------|---------|---------|---------|-----------|\n");
    for (i = 0; i < n; i++)
    {
        printf("|%2d |%-20s|%9.2f|%9.2f|%9.2f|%6d     |\n", // In DG với %9.2f thay cho %5d
               i + 1, dsdv[i].TenDV, dsdv[i].TL, dsdv[i].GT, dsdv[i].DG, dsdv[i].PA);
        TongTL = TongTL + dsdv[i].PA * dsdv[i].TL;
        TongGT = TongGT + dsdv[i].PA * dsdv[i].GT;
    }
    printf("|---|--------------------|---------|---------|---------|-----------|\n");
    printf("Trong luong cua ba lo = %-9.2f\n", W);
    printf("Tong trong luong = %-9.2f\n", TongTL);
    printf("Tong gia tri = %-9.2f\n", TongGT);
}

int min(int a, int b)
{
    return a < b ? a : b;
}

void Greedy(DoVat *dsdv, int n, float W)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (dsdv[i].TL <= W) // Nếu trọng lượng đồ vật nhỏ hơn ba lô, chọn hết
        {
            dsdv[i].PA = 1;
            W -= dsdv[i].TL; // Trừ trọng lượng đã chọn
        }
        else
        {
            dsdv[i].PA = 0; // Nếu không còn đủ trọng lượng, không chọn đồ vật đó
        }
    }
}

int main()
{
    int n;
    float W;
    DoVat *dsdv;

    dsdv = ReadFromFile(&W, &n);
    BubbleSort(dsdv, n);
    Greedy(dsdv, n, W);
    InDSDV(dsdv, n, W);

    free(dsdv);
    return 0;
}
