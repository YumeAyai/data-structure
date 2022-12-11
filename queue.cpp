#include <stdio.h>
#include<stdlib.h>
typedef struct{
   int arrive;
   int treat;//客户的信息结构
}QNODE;

typedef struct node{
QNODE data;
struct node *next;//队列中的元素信息
}LNODE,*LNODEPtr;

LNODE *front,*rear;// 队头指针和队尾指针

//========================================

//入队
void EnQueue(QNODE e)
{
	LNODEPtr s=(LNODEPtr)malloc(sizeof(LNODE));
	if(!s) // 存储分配失败
		exit(0);
	s->data=e;
	s->next=NULL;
	rear->next=s;	// 把拥有元素e的新结点s赋值给原队尾结点的后继
	rear=s;		// 把当前的s设置为队尾结点，rear指向s
}

//=========================================

//出队
int DeQueue(QNODE *e)
{
	LNODEPtr p;
	if(front==rear)
		return 0;
    *e=front->next->data; // 将欲删除的队头结点的值赋值给e
    p=front->next;				// 将欲删除的队头结点暂存给p
	front->next=front->next->next;
	if(rear==p)		// 若队头就是队尾，则删除后将rear指向头结点
		rear=front;
	free(p);
	return 1;
}


//==========================================
int main()
{
    int waitsum1=0,waitsum2=0;//一为业务员等待时间。二为客户等待时间
    int clock=0;
    int nubk=0;//用于积累客户人数
    int have=0;//have用于判断是否有未处理的客户 非0为存在 0为不存在

    QNODE temp,e;

    //建造空队列
    front=rear=(LNODEPtr)malloc(sizeof(LNODE));
    front->next=NULL;//防止指针乱指

    FILE *fp=fopen("./test.txt","r");//创建一个TXT文件并打入‘10 20 23 10 45 5 55 10 58 15 65 10’。
                   /*"要打开的文件路径以及文件命名","r" */
    if(fp==NULL){
            printf("文件打开失败");
            return 0;
    }

    have= fscanf(fp,"%d %d",&temp.arrive,&temp.treat);

    do{
        if( have==2 && front==rear )//等待队列为空并且还有客户
        {
            waitsum1+=(temp.arrive-clock);//累计业务员总等待时间
            clock=temp.arrive;// 时钟推进到暂存变量中的客户的到达时间

            //入队
            EnQueue(temp);

            have= fscanf(fp,"%d %d",&temp.arrive,&temp.treat);
        }

        nubk++;//积累客户人数+1

        //出队
        DeQueue(&e);

        waitsum2+=(clock-e.arrive);

        clock+=e.treat;//时间推进到客户结束时间

        while(temp.arrive<=clock && have==2) //在上一个客户结束结束之前，若有到达的客户就入队
        {
            //入队
            EnQueue(temp);
            have= fscanf(fp,"%d %d",&temp.arrive,&temp.treat);
        }
    }while(have==2||front!=rear);//还有未处理的客户
    printf("业务员等待时间为%d\n客户平均等待时间为%f",waitsum1,(float)waitsum2/(float)nubk);

    return 0;
}