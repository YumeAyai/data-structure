#include <stdio.h>
#include <stdlib.h>
typedef int DataType;

typedef struct Node
{
    DataType data;
    struct Node *next;
} SLNode;

void ListInitiate(SLNode **head) /*��ʼ��*/
{
    /*������ڴ�ռ䣬����ͷ���ռ䲢ʹͷָ��headָ��ͷ���*/
    if ((*head = (SLNode *)malloc(sizeof(SLNode))) == NULL)
        exit(1);
    (*head)->next = NULL; /*����β���NULL */
}

int ListLength(SLNode *head) /* ������ĳ���*/
{
    SLNode *p = head; /*pָ����Ԫ���*/
    int size = 0;     /*size��ʼΪ0*/

    while (p->next != NULL) /*ѭ������*/
    {
        p = p->next;
        size++;
    }
    return size;
}

int ListInsert(SLNode *head, int i, DataType x)
/*�ڴ�ͷ���ĵ�����head������Ԫ��ai��0 �� i �� size�����ǰ*/
/*����һ���������Ԫ��x�Ľ��*/
{
    SLNode *p, *q;
    int j;

    p = head; /*pָ����Ԫ���*/
    j = -1;   /*j��ʼΪ-1*/

    // p->next != NULL &&
    while (p->next != NULL && j < i - 1)
    /*������ָ��pָ������Ԫ��ai-1���*/
    {
        p = p->next;
        j++;
    }

    if (j != i - 1)
    {
        printf("����λ�ò�����");
        return 0;
    }

    /*�����½����ָ��qָʾ*/
    if ((q = (SLNode *)malloc(sizeof(SLNode))) == NULL)
        exit(1);
    q->data = x;

    //�˶γ�����һ������
    q->next = p->next; /*��ָ��q->next��ֵ*/
    p->next = q;       /*��ָ��p->next���¸�ֵ*/
    return 1;
}

int ListDelete(SLNode *head, int i, DataType *x)
/*ɾ����ͷ���ĵ�����head������Ԫ��ai��0 �� i �� size - 1�����*/
/*ɾ����������Ԫ����ֵ��x���ء�ɾ���ɹ�ʱ����1��ʧ�ܷ���0*/
{
    SLNode *p, *s;
    int j;

    p = head; /*pָ����Ԫ���*/
    j = -1;   /*j��ʼΪ-1*/
    while (p->next != NULL && p->next->next != NULL && j < i - 1)
    /*������ָ��pָ������Ԫ��ai-1���*/
    {
        p = p->next;
        j++;
    }

    if (j != i - 1)
    {
        printf("ɾ��λ�ò�����");
        return 0;
    }

    //�˶γ�����һ������
    s = p->next;       /*ָ��sָ������Ԫ��ai���*/
    *x = s->data;      /*��ָ��s��ָ��������Ԫ����ֵ����x*/
    p->next = s->next; /*������Ԫ��ai���ӵ�������ɾ��*/
    free(s);           /*�ͷ�ָ��s��ָ�����ڴ�ռ�*/
    return 1;
}

int ListGet(SLNode *head, int i, DataType *x)
/*ȡ����Ԫ��ai��ɾ��������ͬ��ֻ�ǲ�ɾ������Ԫ��ai���*/
{
    SLNode *p;
    int j;

    p = head;
    j = -1;
    while (p->next != NULL && j < i)
    {
        p = p->next;
        j++;
    }

    if (j != i)
    {
        printf("ȡԪ��λ�ò�����");
        return 0;
    }

    //�˶γ�����һ������
    *x = p->data;
    return 1;
}

void Destroy(SLNode *head)
{
    SLNode *p, *p1;

    p = head->next;
    head->next = NULL;
    while (p1 != NULL)
    {
        p1 = p;
        p = p->next;
        free(p1);
        p1 = NULL;
    }
    head = NULL;
    //printf("success");
}

void MergeList(SLNode *head, SLNode *head2, SLNode *head3)
{
    SLNode *p1, *p2, *p3;
    p1 = head->next, p2 = head2->next;
    p3 = head3;
    while (p1 != NULL && p2 != NULL)
    {
        if (p1->data <= p2->data)
        {
            p3->next = p1;
            p3 = p3->next;
            p1 = p1->next;
        }
        else if (p1->data > p2->data)
        {
            p3->next = p2;
            p3 = p3->next;
            p2 = p2->next;
        }
        if (p1 != NULL)
        {
            p3->next = p1;
        }
        else if (p2 != NULL)
        {
            p3->next = p2;
        }
    }
}

int main()
{
    SLNode *head;
    SLNode *head2;
    SLNode *head3;
    int i, x;
    ListInitiate(&head); /*��ʼ��*/
    ListInitiate(&head2);
    ListInitiate(&head3);
    for (i = 0; i < 10; i++)
    {
        if (ListInsert(head, i, i + 1) == 0) /*����10������Ԫ��*/
        {
            printf("����! \n");
        }
    }

    for (i = 0; i < 10; i++)
    {
        if (ListInsert(head2, i, (i + 1) * i) == 0) /*����10������Ԫ��*/
        {
            printf("����! \n");
        }
    }

    /*if (ListDelete(head, 4, &x) == 0)
    {
        printf("����! \n");
    }*/

    for (i = 0; i < ListLength(head); i++)
    {
        if (ListGet(head, i, &x) == 0) /*ȡԪ��*/
        {
            printf("����! \n");
        }
        else
            printf("%d    ", x); /*��ʾ����Ԫ��*/
    }
    printf("\n");

    for (i = 0; i < ListLength(head2); i++)
    {
        if (ListGet(head2, i, &x) == 0) /*ȡԪ��*/
        {
            printf("����! \n");
        }
        else
            printf("%d    ", x); /*��ʾ����Ԫ��*/
    }
    printf("\n");

    MergeList(head, head2, head3);

    for (i = 0; i < ListLength(head3); i++)
    {

        if (ListGet(head3, i, &x) == 0)
        {
            printf("����! \n");
        }
        else
            printf("%d    ", x);
    }

    Destroy(head);
    Destroy(head2);
    Destroy(head3);
    return 0;
}
