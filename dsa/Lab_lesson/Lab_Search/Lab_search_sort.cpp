//
// Created by 我的名字是Ox on 2024/6/12 012.
//
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

#define MAXSIZE 100
#define INF 9999

typedef int ElemType;

typedef struct list{
    ElemType elem[MAXSIZE];
    int length; } SeqList;


int Find1_List(SeqList *L,ElemType x);//按关键字值顺序表查找
int Find2_List(SeqList *L,int i);//按位序顺序表查找
void Insert_Sort(SeqList *L);
void Bubble_Sort(SeqList *L);//冒泡排序
void Selection_Sort(SeqList *L);//选择排序
void Quick_sort(SeqList *L,int low,int high);//快速排序
void Shell_Sort(SeqList *L);//希尔排序
int Binary_Search(SeqList *L,ElemType x);//折半查找
int Hash_Search(SeqList *L,ElemType x);//哈希查找


/*1.顺序表查找*/
// 在顺表中从前向后查找值为x元素，查找成功返回第一个x的位序，查找失败返回0
int Find1_List(SeqList *L, ElemType x)
{
    for(int i = 0; i < L->length; i++) {
        if(L->elem[i] == x) return i + 1;
    }
    return 0;
}

// 在顺表中从前向后查找第i个元素的值，查找失败返回元素的值，查找失败返回INF9999
int Find2_List(SeqList *L, int i)
{
    if(i > L->length || i <= 0) return INF; // 修改条件i <= 0
    else return L->elem[i - 1];
}

//直接插入排序：对顺序表L中数据元素采用直接插入排序的方法进行排序
void Insert_Sort(SeqList *L)
{
    int i,j;
    ElemType temp;
    //边查找边插入 需要n-1轮
    for(i=1;i<L->length;i++) //外循环i从0开始
    {
        temp=L->elem[i];
        j=i-1;
        while(j>=0 && L->elem[j]>temp)
        {
            L->elem[j+1]=L->elem[j];
            j--;
        }
        L->elem[j+1]=temp;
    }

}


//冒泡排序：对顺序表中的元素采用冒泡排序的方法进行排序
void Bubble_Sort(SeqList *L)
{
    int i,j;
    ElemType temp;
    for(i=0;i<L->length-1;i++)
    {
        for(j=0;j<L->length-1-i;j++)
        {
            if(L->elem[j+1]<L->elem[j])
            {
                //swap(L->elem[i],L->elem[j])
                temp = L->elem[j];
                L->elem[j]=L->elem[j+1];
                L->elem[j+1]=temp;
            }
        }
    }

}

//选择排序：对顺序表中的元素采用选择排序的方法进行排序
void Selection_Sort(SeqList *L)
{
    int i,j;
    ElemType temp;
    for(i=0;i<L->length-1;i++)
    {
        for(j=i+1;j<L->length;j++)
        {
            if(L->elem[i]>L->elem[j])
            {
                //swap
                temp = L->elem[j];
                L->elem[j] =L->elem[i];
                L->elem[i] = temp;
            }
        }
    }


}

//快速排序：对顺序表中的元素采用快速排序的方法进行排序
void Quick_Sort(SeqList *L,int low,int high)  //low为当前待查区域的起始地址，high为待查区域的终止地址
{
    int i=low,j=high;
    ElemType key,temp;
    key=L->elem[i];//设置第一个数据元素为哨兵
    while(i<j)
    {
        while(i<j && key<=L->elem[j])
            j--;
        temp=L->elem[i];
        L->elem[i]=L->elem[j];
        L->elem[j]=temp;

        while(i<j && key>=L->elem[i])
            i++;
        temp=L->elem[i];
        L->elem[i]=L->elem[j];
        L->elem[j]=temp;
    }

    if(i-1>low)  //缩小待查区域
        Quick_Sort(L,low,i-1);
    if(i+1<high)
        Quick_Sort(L,i+1,high);
}



//对顺序表中的元素采用希尔排序的方法进行排序，缩小增量为5、3、1：  选做
/* void Shell_Sort(SeqList *L)
{



}*/

//折半查找：对已经排好序的顺序表，采用折半查找方法，查找值为X的元素，查找成功返回第一个x的位置，查找失败返回-1
int Binary_Search(SeqList *L,ElemType x)
{
    int low=0,high=L->length-1,mid;
    while(low<=high)
    {
        mid=low+high>>1;
        if(L->elem[mid]<x)
            low=mid+1;
        else high=mid-1;

        if(L->elem[mid]==x) return mid+1;

    }
    return -1;
}


//哈希查找：在已经按照hash函数存储好的顺序表L中，查找值为x的元素，查找成功返回其位序，失败返回0
int Hash_Search(SeqList *L,ElemType x)
{
    int n=0;
    int i,j;
    for(i=0;i<L->length;i++)
    {
        if(L->elem[i]==x)
        {
            printf("查找成功！  ");
            for(j=x%13; ;j=(j+1)%L->length)
            {
                n++;
                if(L->elem[j]==x)
                {	printf("查找次数是 %d \n",n);
                    break;}
            }
            break;

        }
    }
    if(n==0)
        return -1;
    else
        return j;

}


int main()
{
    SeqList *L;
    int a[12]={82,32,1,100,77,12,62,95,75,45,9,3},hash[12];
    int i,j,x,n;

    L=(SeqList *)malloc(sizeof(SeqList));
    for(i=0;i<12;i++)
        L->elem[i]=a[i];
    L->length=12;


    printf("\n****************************************************************************\n");
    printf("*********************************查找与排序*********************************\n");
    printf("****************************************************************************\n");
    printf("\n打印初始化后的顺序表:\n");
    for(i=0;i<L->length;i++)
        printf("%-4d",L->elem[i]);
    printf("\n\n");
    printf("\n1.顺序表查找：\n");
    printf("按值查找：请输入待查找的关键字：");
    scanf("%d",&x);
    if(Find1_List(L,x))
        printf(" %d 的位序是 %d \n",x,Find1_List(L,x));
    else
        printf("顺序表中没有值为 %d 的元素\n",x);
    printf("按位序查找：请输入待查找的位序：");
    scanf("%d",&n);
    if(Find2_List(L,n)!=INF)
        printf("位序是 %d 的元素值为：%d\n",n,Find2_List(L,n));
    else
        printf("顺序表中没有位序为 %d 的元素\n",n);


    printf("\n2.顺序表排序：\n");
    printf("可选择的排序方式有：直接插入排序(1) 冒泡排序(2)  选择排序(3)   快速排序(4)   希尔排序(5)   \n");
    printf("请输入排序算法的代号(1~5)：");
    scanf("%d",&x);
    while(!(x==1||x==2||x==3||x==4||x==5))
    {   printf("输入排序算法错误！请重新输入：");
        scanf("%d",&x);}

    if(x==1)
        Insert_Sort(L),printf("你选择是的直接插入排序，排序结果如下：\n");
    if(x==2)
        Bubble_Sort(L),printf("你选择是的冒泡排序，排序结果如下：\n");
    if(x==3)
        Selection_Sort(L),printf("你选择是的选择排序，排序结果如下：\n");
    if(x==4)
        Quick_Sort(L,0,L->length-1),printf("你选择是的快速排序，排序结果如下：\n");
    /*if(x==5)  //选做
         Shell_Sort(L),printf("你选择是的希尔排序，排序结果如下：\n");*/

    for(i=0;i<L->length;i++)
        printf("%-4d",L->elem[i]);

    printf("\n\n3.折半查找 \n");
    printf("输入一个折半查找的关键字：");
    scanf("%d",&x);
    printf("查找结果是：%d\n",Binary_Search(L,x));
    if(Binary_Search(L,x))
        printf("有序顺序表中 %d 的位序是 %d\n",x,Binary_Search(L,x));
    else
        printf("有序顺序表中没有值为 %d 的元素\n",x);


//对数组a[12]={82,32,1,100,77,12,62,95,75,45,9,3}采用hash函数loc(i)=key13存入顺序表L，使用线性探测法解决冲突。
    printf("\n\n4.哈希(散列)表查找");
    for(i=0;i<13;i++)
        L->elem[i]=INF;
    L->length=13;
    printf("对数组a[12]={82,32,1,100,77,12,62,95,75,45,9,3}\n");
    printf("采用hash函数loc(i)=key13存入顺序表L，使用线性探测法解决冲突.\n");

    for(i=0;i<12;i++)
    {
        if(L->elem[a[i]%13]==INF)
            L->elem[a[i]%13]=a[i]%13;
        else
        {
            for(j=a[i]%13+1;L->elem[j]!=INF;j=(j+1)%13);
            L->elem[j]=a[i];
        }
    }
    printf("\n哈希表建立成功，初始状态如下：\n");
    printf("  地址: ");
    for(i=0;i<13;i++)
        printf("%6d",i);
    printf("\n关键字：");
    for(i=0;i<13;i++)
        printf("%6d",L->elem[i]);
    printf("\n请输入一个哈希查找的关键字：");
    scanf("%d",&x);
    if( Hash_Search(L, x)==-1)
        printf("\n查找失败，散列表中没有值为 %d 的关键字!\n",x);
    else
        printf("\n查找成功，关键字 %d 在散列中的位置是 %d \n",x,Hash_Search(L, x));



    return 0;
}