#include <iostream>
#include <stdlib.h>
#define MaxSize 100
typedef int DataType;

typedef struct
{
    DataType list[MaxSize];
    int size;
} SeqList;

void ListInitiate(SeqList *L) /*��ʼ��˳���L*/
{
    L->size = 0; /*�����ʼ����Ԫ�ظ���*/
}

int ListLength(SeqList L) /*����˳���L�ĵ�ǰ����Ԫ�ظ���*/
{
    return L.size;
}

int ListInsert(SeqList *L, int i, DataType x)
/*��˳���L��λ��i��0 �� i �� size��ǰ��������Ԫ��ֵx*/
/*����ɹ�����1������ʧ�ܷ���0*/
{
    int j;
    if (L->size >= MaxSize)
    {
        printf("˳��������޷�����! \n");
        return 0;
    }
    else if (i < 0 || i > L->size)
    {
        printf("����i���Ϸ�! \n");
        return 0;
    }
    else
    { //�˶γ�����һ������
        for (j = L->size; j > i; j--)
            L->list[j] = L->list[j - 1]; /*Ϊ������׼��*/
        L->list[i] = x;                  /*����*/
        L->size++;                       /*Ԫ�ظ�����1*/
        return 1;
    }
}

int ListDelete(SeqList *L, int i, DataType *x)
/*ɾ��˳���L��λ��i��0 �� i �� size - 1��������Ԫ��ֵ����ŵ�����x��*/
/*ɾ���ɹ�����1��ɾ��ʧ�ܷ���0*/
{
    int j;
    if (L->size <= 0)
    {
        printf("˳����ѿ�������Ԫ�ؿ�ɾ! \n");
        return 0;
    }
    else if (i < 0 || i > L->size - 1)
    {
        printf("����i���Ϸ�");
        return 0;
    }
    else
    { //�˶γ�����һ������

        *x = L->list[i]; /*����ɾ����Ԫ�ص�����x��*/
        for (j = i + 1; j <= L->size - 1; j++)
            L->list[j - 1] = L->list[j]; /*����ǰ��*/
        L->size--;                       /*����Ԫ�ظ�����1*/
        return 1;
    }
}

int ListGet(SeqList L, int i, DataType *x)
/*ȡ˳���L�е�i������Ԫ�ص�ֵ����x�У��ɹ��򷵻�1��ʧ�ܷ���0*/
{
    if (i < 0 || i > L.size - 1)
    {
        printf("����i���Ϸ�! \n");
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