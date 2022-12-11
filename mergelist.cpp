#include <iostream>
#include <stdlib.h>
#define MaxSize 100
typedef int DataType;

typedef struct
{
    DataType list[MaxSize];
    int size;
} SeqList;

void ListInitiate(SeqList *L) /*初始化顺序表L*/
{
    L->size = 0; /*定义初始数据元素个数*/
}

int ListLength(SeqList L) /*返回顺序表L的当前数据元素个数*/
{
    return L.size;
}

int ListInsert(SeqList *L, int i, DataType x)
/*在顺序表L的位置i（0 ≤ i ≤ size）前插入数据元素值x*/
/*插入成功返回1，插入失败返回0*/
{
    int j;
    if (L->size >= MaxSize)
    {
        printf("顺序表已满无法插入! \n");
        return 0;
    }
    else if (i < 0 || i > L->size)
    {
        printf("参数i不合法! \n");
        return 0;
    }
    else
    { //此段程序有一处错误
        for (j = L->size; j > i; j--)
            L->list[j] = L->list[j - 1]; /*为插入做准备*/
        L->list[i] = x;                  /*插入*/
        L->size++;                       /*元素个数加1*/
        return 1;
    }
}

int ListDelete(SeqList *L, int i, DataType *x)
/*删除顺序表L中位置i（0 ≤ i ≤ size - 1）的数据元素值并存放到参数x中*/
/*删除成功返回1，删除失败返回0*/
{
    int j;
    if (L->size <= 0)
    {
        printf("顺序表已空无数据元素可删! \n");
        return 0;
    }
    else if (i < 0 || i > L->size - 1)
    {
        printf("参数i不合法");
        return 0;
    }
    else
    { //此段程序有一处错误

        *x = L->list[i]; /*保存删除的元素到参数x中*/
        for (j = i + 1; j <= L->size - 1; j++)
            L->list[j - 1] = L->list[j]; /*依次前移*/
        L->size--;                       /*数据元素个数减1*/
        return 1;
    }
}

int ListGet(SeqList L, int i, DataType *x)
/*取顺序表L中第i个数据元素的值存于x中，成功则返回1，失败返回0*/
{
    if (i < 0 || i > L.size - 1)
    {
        printf("参数i不合法! \n");
        return 0;
    }
    else
    {
        *x = L.list[i];
        return 1;
    }
}

void MergeList(SeqList LA, SeqList LB, SeqList *LC)
{
    DataType *pa;
    DataType *pb;
    DataType *pa_last;
    DataType *pb_last;
    pa = LA.list;
    pb = LB.list;
    //pc = LC.list;
    LC->size = LA.size + LB.size;
    if (!LC->list)
        exit(-1);
    pa_last = LA.list + LA.size - 1;
    pb_last = LB.list + LB.size - 1;
    int i = 0;
    while (pa <= pa_last && pb < pb_last)
    {
        if (*pa <= *pb)
        {
            LC->list[i] = *pa++;
        }
        else
        {
            LC->list[i] = *pb++;
        }
        i++;
    }
    while (pa <= pa_last)
    {
        LC->list[i] = *pa++;
        i++;
    }
    while (pb <= pb_last)
    {
        LC->list[i] = *pb++;
        i++;
    }
    // for(int i = 0,x=0; i < ListLength(LC); i++)
    //{
    //     ListGet(LC,i,&x);
    //     printf("%d ", x);
    // }
    printf("\n");
}

int main(void)
{
    SeqList myList1;
    SeqList myList2;
    SeqList myList3;
    int i, x;

    ListInitiate(&myList1);
    for (i = 0; i < 10; i++)
        ListInsert(&myList1, i, i + 1);

    ListInitiate(&myList2);
    for (i = 0; i < 10; i++)
        ListInsert(&myList2, i, i + 1);

    ListDelete(&myList2, 4, &x);

    for (i = 0; i < ListLength(myList1); i++)
    {
        ListGet(myList1, i, &x);
        printf("%d", x);
    }
    printf("\n");
    for (i = 0; i < ListLength(myList2); i++)
    {
        ListGet(myList2, i, &x);
        printf("%d", x);
    }
    printf("\n");

    ListInitiate(&myList3);
    MergeList(myList1, myList2, &myList3);

    for (i = 0; i < ListLength(myList3); i++)
    {
        ListGet(myList3, i, &x);
        printf("%d", x);
    }
}