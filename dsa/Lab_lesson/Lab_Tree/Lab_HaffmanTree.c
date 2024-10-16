//
// Created by 我的名字是Ox on 2024/5/28 028.
//
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N 30  //设哈夫曼树中结点编码长度最大值
#define MAXVALUE  1000 //设权值最大值范围

//huffman树中结点类型建立
typedef struct node
{
    char ch;     //每个结点权值对应的字符内容
    int weight;         //假设权值为int型
    int parent,lchild,rchild;
}HTNode;

//结点huffman编码类型建立
typedef struct code
{
    char code[N];   //haffman编码为字符数组
    char leaf;   //对leaf字符编码
    int length;   //编码长度
}HCode;   //huffman编码类型

/* Huftree[]数组用来存放所有结点的权值，x1,x2用来存放在数组中最小的两个数的下标。
   每次调用Select算法则可以求出一组（两个最小值）的下标。*/
//*x1,*x2 用于保存权值最小的两个结点的下标，n表示从[1..n]中查找
void Select(HTNode Huftree[],int n,int *x1,int *x2)
{
    int i;
    int m1,m2;

    m1=m2=MAXVALUE;    //m1,m2分别保存当前最小和次小的权值 ，初始将其设为一个非常大的数，
    *x1=*x2=0;

    //查找根结点权值最小的两棵树的根结点
    for(i=1;i<=n;i++)
    {
        if(Huftree[i].weight<m1 && Huftree[i].parent==0)  //若比最小值m1还小，则当前权值为最小值，原来的权值为次小的值
        {
            m2=m1;
            *x2=*x1;
            m1=Huftree[i].weight;
            *x1=i;
        }
        else                //否则再跟m2比较
        if(Huftree[i].weight<m2&&Huftree[i].parent==0) //双亲编号为0，保证未被使用过
        {
            m2=Huftree[i].weight;
            *x2=i;
        }
    }

}


void HuffmanTree(HTNode Huftree[],int n)  //huffman树构造算法。
{

    int i,s1,s2;

    //输入叶子结点权值
    printf("\n输入各叶子结点的字符和权值：\n");
    getchar();    //输入时，用到%c，注意清除输入流

    //为huffman树中的叶子结点初始化,数组下标从1开始使用，0不用。
    for(i=1;i<=n;i++)
    {
        printf("输入第%d个结点的字符和权值,格式：(字符，权值): ",i);
        scanf("%c,%d",&Huftree[i].ch,&Huftree[i].weight);
        getchar();        //清除输入流中的回车字符，为下一次%c读入做准备
        //fflush(stdin);  用该函数也可起到清除输入流的作用。

        //初始化每个节点的双亲、左孩子、右孩子编号均为0
        Huftree[i].parent=0;
        Huftree[i].lchild=0;
        Huftree[i].rchild=0;
    }

//haffman树中的分支结点存储空间初始化
    for(i=n+1;i<=2*n-1;i++)
    {
        Huftree[i].weight=0;
        Huftree[i].parent=0;
        Huftree[i].lchild=0;
        Huftree[i].rchild=0;
    }

//循环生成 n-1个非叶子结点 ,即将两棵树合为一棵树的过程
    for(i=1;i<=n-1;i++)
    {
        Select(Huftree,n+i-1,&s1,&s2);  //从前n+i-1个结点中查找权值最小的两棵树，生成第 i个非叶子结点 ,将最小下标放在s1中，次小下标放在s2中

        Huftree[s1].parent=n+i;
        Huftree[s2].parent=n+i;
        Huftree[n+i].lchild=s1;   //权值较小的放在左分支上，较大的放在右分支上
        Huftree[n+i].rchild=s2;
        Huftree[n+i].weight=Huftree[s1].weight+Huftree[s2].weight;
    }

}

//根据huffman树获取对应的huffman编码
void HuffmanCode(HTNode Huftree[],int n,HCode cd[]) //n个叶子结点的huffman树的编码 ,将编码放在数组cd中
//生成huffman编码
{ char temp[N];
    int i,c,k,f;
    for(i=1;i<=n;i++)
    {
        c=0;
        for(k=i,f=Huftree[k].parent;f!=0;k=f,f=Huftree[k].parent)//为第i个叶子结点进行编码，
        {
            if(Huftree[f].lchild==k)       //若该结点在左分支上，则记'0'，否则记'1'
                temp[c++]='0';
            else
                temp[c++]='1';
        }
        //将temp数组中的数据转置到cd[i]的code成员中去
        //  cd[i].code=(char *)malloc(sizeof (c+1));
        // cd[i].code[k]='\0';
        cd[i].length=c;
       for(k=0,c--;c>=0;c--,k++)  cd[i].code[k]=temp[c];
        cd[i].code[k]='\0';
    }
}

int main()
{
    int n,i,j,k,l;
    HTNode ht[N*20];
    char hl[100];
    char sstr[100],dstr[300];
    HCode cd[N];
    FILE *fhtmTree;
    printf("       ***************************************************************\n");
    printf("       *********************** 哈夫曼树建立***************************\n");
    printf("       ************************哈夫曼树编码***************************\n");

    //初始化哈夫曼树
    printf("\n输入叶子结点个数(不大于10)：");
    scanf("%d",&n);
    HuffmanTree(ht,n);
    printf("\n");
    printf("哈夫曼树的结点状态：\n");
    for(i=1;i<=2*n-1;i++)
    {if(i<=n)
            printf("下标%d的结点:字符%c ,权值%d ,双亲编号%d ,左孩子编号%d ,右孩子编号%d\n",i,ht[i].ch,ht[i].weight,ht[i].parent,ht[i].lchild,ht[i].rchild);
        else
            printf("下标%d的结点:        权值%d ,双亲编号%d ,左孩子编号%d ,右孩子编号%d\n",i,ht[i].weight,ht[i].parent,ht[i].lchild,ht[i].rchild);
    }
    printf("\n");
    HuffmanCode(ht,n,cd);
    for(i=1;i<=n;i++)
    { printf("\n字符%c的huffman编码是：",ht[i].ch);
        printf("%s",cd[i].code);
    }
    printf("\n");

    //用户创建文件，存储内容
    fhtmTree=fopen("hfmTree.txt","w");
    if(!fhtmTree)
    {
        printf("Error to create htmTree.txt!\n");
        return 1;
    }
    for(i=1;i<=n;i++)
        fprintf(fhtmTree,"%c: %s\n",cd[i].leaf,cd[i].code);
    fclose(fhtmTree);
    printf("哈夫曼树已经创建完毕，并且已经放入hfmTree.txt文件中!\n");

    return 0;
}


