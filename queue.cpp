#include <stdio.h>
#include<stdlib.h>
typedef struct{
   int arrive;
   int treat;//�ͻ�����Ϣ�ṹ
}QNODE;

typedef struct node{
QNODE data;
struct node *next;//�����е�Ԫ����Ϣ
}LNODE,*LNODEPtr;

LNODE *front,*rear;// ��ͷָ��Ͷ�βָ��

//========================================

//���
void EnQueue(QNODE e)
{
	LNODEPtr s=(LNODEPtr)malloc(sizeof(LNODE));
	if(!s) // �洢����ʧ��
		exit(0);
	s->data=e;
	s->next=NULL;
	rear->next=s;	// ��ӵ��Ԫ��e���½��s��ֵ��ԭ��β���ĺ��
	rear=s;		// �ѵ�ǰ��s����Ϊ��β��㣬rearָ��s
}

//=========================================

//����
int DeQueue(QNODE *e)
{
	LNODEPtr p;
	if(front==rear)
		return 0;
    *e=front->next->data; // ����ɾ���Ķ�ͷ����ֵ��ֵ��e
    p=front->next;				// ����ɾ���Ķ�ͷ����ݴ��p
	front->next=front->next->next;
	if(rear==p)		// ����ͷ���Ƕ�β����ɾ����rearָ��ͷ���
		rear=front;
	free(p);
	return 1;
}


//==========================================
int main()
{
    int waitsum1=0,waitsum2=0;//һΪҵ��Ա�ȴ�ʱ�䡣��Ϊ�ͻ��ȴ�ʱ��
    int clock=0;
    int nubk=0;//���ڻ��ۿͻ�����
    int have=0;//have�����ж��Ƿ���δ����Ŀͻ� ��0Ϊ���� 0Ϊ������

    QNODE temp,e;

    //����ն���
    front=rear=(LNODEPtr)malloc(sizeof(LNODE));
    front->next=NULL;//��ָֹ����ָ

    FILE *fp=fopen("./test.txt","r");//����һ��TXT�ļ������롮10 20 23 10 45 5 55 10 58 15 65 10����
                   /*"Ҫ�򿪵��ļ�·���Լ��ļ�����","r" */
    if(fp==NULL){
            printf("�ļ���ʧ��");
            return 0;
    }

    have= fscanf(fp,"%d %d",&temp.arrive,&temp.treat);

    do{
        if( have==2 && front==rear )//�ȴ�����Ϊ�ղ��һ��пͻ�
        {
            waitsum1+=(temp.arrive-clock);//�ۼ�ҵ��Ա�ܵȴ�ʱ��
            clock=temp.arrive;// ʱ���ƽ����ݴ�����еĿͻ��ĵ���ʱ��

            //���
            EnQueue(temp);

            have= fscanf(fp,"%d %d",&temp.arrive,&temp.treat);
        }

        nubk++;//���ۿͻ�����+1

        //����
        DeQueue(&e);

        waitsum2+=(clock-e.arrive);

        clock+=e.treat;//ʱ���ƽ����ͻ�����ʱ��

        while(temp.arrive<=clock && have==2) //����һ���ͻ���������֮ǰ�����е���Ŀͻ������
        {
            //���
            EnQueue(temp);
            have= fscanf(fp,"%d %d",&temp.arrive,&temp.treat);
        }
    }while(have==2||front!=rear);//����δ����Ŀͻ�
    printf("ҵ��Ա�ȴ�ʱ��Ϊ%d\n�ͻ�ƽ���ȴ�ʱ��Ϊ%f",waitsum1,(float)waitsum2/(float)nubk);

    return 0;
}