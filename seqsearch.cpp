#include <stdio.h>
#include <stdlib.h>

int SeqSearch(int R[], int n, int k)
{
    int i = 0;
    while (i < n && R[i] != k)
    {
        printf("%d", R[i]);
        i++;
    }
    if (i >= n)
        return -1;
    else
    {
        printf("%d", R[i]);
        return i;
    }
}

int main()
{
    int a[10] = {9, 13, 15, 7, 45, 32, 56, 89, 60, 36};
    int k, loc;
    printf("Please input your number: \n");
    scanf("%d", &k);
    loc = SeqSearch(a, 10, k);
    printf("\n");
    printf("The number's location is %d\n ", loc);
    return 0;
}
