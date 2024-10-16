//
// Created by 我的名字是Ox on 2024/5/8 008.
//
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 6    /* 循环队列中最大元素个数，应根据需要定义 */

#define TRUE 1
#define FALSE 0
typedef  int  ElemType; /* 循环队列中元素类型，应根据需要定义 */

typedef struct queue{	  /*/循环队列类型定义 */
    ElemType  elem[MAXSIZE];  /*队列中的元素，存储在elem数组中，队列最大存储容量是MAXSIZE*/
    int front,rear; 		  /* 循环队列 队头、队尾 位置指示器 整型 */
}CSeqQueue;

/* 循环队列初始化，置空队列 */
CSeqQueue *Init_CSeqQueue()
{
    CSeqQueue *q=(CSeqQueue *) malloc(sizeof (CSeqQueue));   //申请分配循环队列存储空间
    if (q==NULL)
        printf("Out of space!! \n");
    else
        q->front=-1,q->rear=-1;   //初始化队头、队尾位置为-1,也是对空标志
    return q;
}

/* 统计循环队列中元素个数，即求队列长度 */
int length_CSeqQueue(CSeqQueue *q)
{
    int n;
    n=(q->rear-q->front+MAXSIZE+1)%MAXSIZE;//计算循环队列中元素个数
    return n;
}

/* 判断q指向的循环队列是否为空队列 */
int isEmpty_CSeqQueue(CSeqQueue *q)
{
    if(q->front==-1&&q->rear==-1) /*队列空判断*/
        return TRUE;
    else
        return FALSE;
}

/* 入队操作：在队尾位置压入元素x */
int In_CSeqQueue(CSeqQueue *q, ElemType x )
{
    if((q->rear+1)%MAXSIZE==q->front)   //队满不能入队
    {
        printf( "front值：%d，rear值：%d，入队失败，上溢！循环队列满！\n", q->front,q->rear );
        printf( "队列已满!  元素%d入队失败，队满上溢！\n",x );
        return FALSE;}
    else
    {
        printf("\nrear由%d",q->rear);

        if(q->front==-1&&q->rear==-1)/*队列空*/
        {
            q->front++;
            q->rear++;     /* 队头指针和队尾指针变化*/
        }
        else
            q->rear=(q->rear+1)%MAXSIZE;/*非满、非空队列入队*/

        q->elem[q->rear] = x;

        printf("变为%d，元素%d入队成功\n", q->rear,x);

        return TRUE;
    }
}

/* 出队操作：删除队头元素 */
int  Out_CSeqQueue (CSeqQueue *q, ElemType *x) {
    if (q->front==-1&&q->rear==-1)  /*队空判断*/
    {
        printf( "Underflow!  出队失败，队空下溢！\n" );
        return FALSE;}
    else     /*队列非空，可以执行出队操作*/
    {
        if((q->rear-q->front+MAXSIZE)%MAXSIZE==1)//队列中仅有一个元素
        {
            printf("队列中仅有一个元素，front、rear由%d",q->front);
            *x=q->front;
            q->front= q->rear;//队列置空
            q->rear=0;
            printf("变为%d，元素%d出队成功\n",q->front, *x);
        }
        else       //队列中有多个元素
        {
            printf("\nfront由%d",q->front);
            *x=q->elem[q->front];
            q->front= (q->front+1)%MAXSIZE;
            printf("变为%d，队头元素%d出队成功\n",q->front, *x);
        }
        return TRUE;
    }
}

/*队列遍历*/
void  Traverse_CSeqQueue (CSeqQueue *q)
{
    int i;
    if(isEmpty_CSeqQueue(q))   /*队空判断*/
        printf("空循环队列！长度为0！\n\n");
    else
    {
        printf("\nfront=%d，队头位序%d，队头元素%d\n", q->front,1,q->elem[q->front]);
        printf("rear=%d，队尾位序%d，队尾元素%d\n\n", q->rear, length_CSeqQueue(q), q->elem[q->rear]);
        printf("循环队列长度为%d\n",length_CSeqQueue(q));
        printf( "队头-->" );
        for(i=1; i<= length_CSeqQueue(q); i++)//从队头到队尾依次打印元素
        {
            printf("%d   ", q->elem[(q->front+i-1)%MAXSIZE]);
        }
        printf( "<--队尾\n" );
    }
}

int main()
{
    CSeqQueue *q;
    int n,m,i=1,j=1,v;
    char choice=0,ch;

    printf( " \n" );
    while(choice!='Q' && choice!='q')                //当choice的值不为q且不为Q时循环
    {
        printf("       ********************* 循 环 队 列 常 用 算 法 *********************\n");
        printf("            I.Init    E.Push    P.Pop    T.Traverse    Q.Exit\n");
        if(j==1) {printf("\n注意：请先执行I(Init)一次\n");  j++;}
        printf("请输入您要操作的步骤：");
        scanf("%c",&choice);
        while(choice=='\n') scanf("%c",&choice);   //若输入对象为回车，重新输入操作符号
        if(choice=='I'||choice=='i')               //初始化循环队列
        { q=Init_CSeqQueue();
            printf("循环队列初始化成功……\n");}
        else if(choice=='E'||choice=='e') {
            printf("请输入要入队的元素个数: ");
            printf("N=");
            scanf("%d",&n);
            printf("请输入要入队的元素: ") ;
            for(i=1;i<=n;i++)
            {	scanf("%d",&m);
                In_CSeqQueue(q, m);
            }
            while((ch = getchar()) != '\n' && ch != EOF);  //
            Traverse_CSeqQueue (q);
        }
        else if(choice=='P'||choice=='p'){
            printf("请输入要出队的元素个数: ");
            printf("N=");
            scanf("%d",&n);
            for(i=1;i<=n;i++)
                Out_CSeqQueue (q,&v);
            while((ch = getchar()) != '\n' && ch != EOF);
            Traverse_CSeqQueue (q);
        }

        else if(choice=='T'||choice=='t')
            Traverse_CSeqQueue (q);
        else if(choice=='Q'||choice=='q')            //退出程序
        {
            exit(0);
        }
        else               //如果选了选项之外的就让用户重新选择
        {
            printf("您没有输入正确的操作指令，请重新输入！\n");
        }
        printf("\n\n");
    }
    return 0;
}

