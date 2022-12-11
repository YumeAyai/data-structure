#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define ERROR 0
#define MAXSIZE 100 // 存储空间初始分配量
typedef int Status;
typedef struct
{
        int data[MAXSIZE];
        int top; // 用于栈顶指针
}opndStack;

typedef struct
{
        char data[MAXSIZE];
        int top; // 用于栈顶指针
}opterStack;

//====================================================================
int getIndex(char theta)   //获取theta所对应的索引
{
    int index = 0;
    switch (theta)
    {
	    case '+':
	        index = 0;
	        break;
	    case '-':
	        index = 1;
	        break;
	    case '*':
	        index = 2;
	        break;
	    case '/':
	        index = 3;
	        break;
	    case '(':
	        index = 4;
	        break;
	    case ')':
	        index = 5;
	        break;
	    case '#':
	        index = 6;
	    default:break;
    }
    return index;
}

//====================================================================

char getPriority(char theta1, char theta2)   //获取theta1与theta2之间的优先级
{
    const char priority[][7] =     //算符间的优先级关系
    {
        { '>','>','<','<','<','>','>' },
        { '>','>','<','<','<','>','>' },
        { '>','>','>','>','<','>','>' },
        { '>','>','>','>','<','>','>' },
        { '<','<','<','<','<','=','0' },
        { '>','>','>','>','0','>','>' },
        { '<','<','<','<','<','0','=' },
    };

    int index1 = getIndex(theta1);
    int index2 = getIndex(theta2);
    return priority[index1][index2];
}

//====================================================================

Status InitopndStack(opndStack *S)//建立opnd空栈
{
    S->top=-1;
    return OK;
}

Status InitopterStack(opterStack *S)//建立opter空栈
{
    S->top=-1;
    return OK;
}

//====================================================================

Status Pushnd(opndStack *S,int n)//入栈
{
    if(S->top== MAXSIZE-1)
    {
        return ERROR;
    }
    S->top++;//
    S->data[S->top]=n;
    return OK;
}

Status Pushter(opterStack *S,char n)
{
    if(S->top== MAXSIZE-1)
    {
        return ERROR;
    }
    S->top++;//
    S->data[S->top]=n;
    return OK;
}

//=========================================================

Status Popnd(opndStack *S,int *n)//出栈 并返回到 n 中
{
    if(S->top==-1)
        return ERROR;
    *n=S->data[S->top];
    (S->top)--;
    return OK;
}

Status Popter(opterStack *S,char *n)
{
    if(S->top==-1)
        return ERROR;
    *n=S->data[S->top];
    S->top--;
    return OK;
}

//=======================================================

signed int calculate(int x1,int x2,char c)
{
    switch(c)
    {
    case '+':
        return (x1+x2);
    case '-':
        return (x1-x2);
    case '*':
        return (x1)*(x2);
    case '/':
        return (x1)/(x2);
    default:
        return 0;
    }
    return 0;
}

//======================================================

int isdigit(char c)//判断是否为操作数
{
    if(c<='9'&& c>='0')
        return 1;
    else
        return 0;
}

int ischar(char c)//判断是否为运算符
{
    switch(c)
    {
    case '+':
    case '-':
    case '*':
    case '/':
    case '(':
    case ')':
    case '#':
        return 1;
    default:
        return 0;
    }
    return 0;

}
//=========================================================

void input(char s[])  //输入表达式 存入s[]数组中。
{
    char c;
    int i = 0;
    while(c!='#')
    {
        while((c=getchar())==' ');//跳过所有空格进行c的输入
        s[i++]=c;
    }
    return ;
}

//==========================================================

int calculateall()
{
    char c,s[100]={0},k;
    int x1,x2,i=0;
    int n=0;
    opndStack opnd;
    opterStack opter;
    InitopndStack(&opnd); //空栈
    InitopterStack(&opter);
    Pushter(&opter,'#');

    input(s);

    while(s[i]!='\0')
    {
        c=s[i];
            if(ischar(c))
            {
                 switch(getPriority(opter.data[opter.top],c))
                    {
                    case '<':
                        Pushter(&opter,c);
                        break;
                    case '=':
                        Popter(&opter,&k);//k没有用处 用来满足函数关系而已
                        break;
                    case '>':
                        while(getPriority(opter.data[opter.top],c)=='>')
                        {
                            Popnd(&opnd,&x1);
                            Popnd(&opnd,&x2);
                            Popter(&opter,&k);
                            x1=calculate(x2,x1,k);
                            Pushnd(&opnd,x1);
                        }
                        if(getPriority(opter.data[opter.top],c)=='<')
                            Pushter(&opter,c);
                        else
                            Popter(&opter,&k);
                        break;
                    default:
                        printf("INPUT ERROR");
                    }
            }
            else
            {
                Pushnd(&opnd,c-'0');
            }
        ++i;
    }
    Popnd(&opnd,&n);
    return n;
}

//=========================================================
int main()
{
   int k;
   k=calculateall();
   printf("%d",k);
   return 0;
}

