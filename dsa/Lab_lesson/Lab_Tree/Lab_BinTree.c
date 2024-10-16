//
// Created by 我的名字是Ox on 2024/5/21 021.
//
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAXSIZE 20
#define TRUE 1
#define FALSE 0

typedef int Status;
typedef  char  ElemType ;   //定义二叉树中结点值得类型为字符型

//定义二叉树中结点类型
struct node  //struct node 用来定义二叉树中的一个结点
{
    ElemType  data;
    struct node *Lchild,*Rchild;
};
typedef  struct node  BinNode,*BinTree;

int Count=0,Depth=0;//全局变量，Count用来统计二叉树中结点个数，Depth用来统计二叉树深度

/* 扩展的先序序列递归创建二叉树 */
BinTree Create_BinTree()
{
    BinTree  pbnode; //变量名 pbnode 是 pointer to binary node 的缩写
    char ch;
    scanf("%c", &ch);

    if(ch == '^') pbnode = NULL;

    else
    {
        pbnode = (BinTree)malloc(sizeof(BinNode)); //开辟空间
        if( pbnode == NULL )
        {
            printf("Out of space!\n");
            return pbnode;
        }
        pbnode->data = ch;
        pbnode->Lchild = Create_BinTree();	/* 构造左子树 */
        pbnode->Rchild = Create_BinTree();	/* 构造右子树 */
    }
    return pbnode;
}

/* 先序序列和中序序列递归创建二叉树 */
/*In为中序字符串数组，InStart为中序首字符编号，初值为0，InEnd为中序尾字符编号*/
/*Pre为先序字符串数组，PreStart为先序首字符编号，初值为0,PreEnd为先序尾字符编号*/
void Create_BinTree_PreIn(char *In,int InStart,int InEnd,char *Pre,int PreStart,int PreEnd,BinTree *T)
{
    int i; //i是位序
    if(InStart>InEnd||PreStart>PreEnd)
        *T=NULL;
    else
    {
        *T=(BinNode *)malloc(sizeof(BinNode)); //T为二重指针 *T成为普通指针
        (*T)->data =Pre[PreStart];
        for(i=InStart;i<=InEnd;i++)
        {
            if(In[i]==Pre[PreStart]) //i是指向In数组的指针
            {   //中序定左右
                Create_BinTree_PreIn(In,InStart,i-1,Pre,PreStart+1,PreStart+i-InStart,&(*T)->Lchild);
                Create_BinTree_PreIn(In,i+1,InEnd,Pre,PreStart+1+(i-InStart),PreEnd,&(*T)->Rchild);
                break;
            }
            if(i>InEnd)
            {
                printf("输入错误!n");
                exit(1);
            }
        }
    }
}

/* 后序序列和中序序列递归创建二叉树 */
/*In为中序字符串数组，InStart为中序首字符编号，初值为0，InEnd为中序尾字符编号*/
/*Post为后序字符串数组，PostStart为后序首字符编号，初值为0,PostEnd为后序尾字符编号*/
void Create_BinTree_PostIn(char *In,int InStart,int InEnd,char Post[],int PostStart,int PostEnd,BinTree *T)
{
    int i;
    if(InStart > InEnd || PostStart > PostEnd)
        *T=NULL;    else{
        *T=(BinTree)malloc(sizeof(BinNode));
        (*T)->data = Post[PostEnd];
        for(i= InStart;i<= InEnd;i++)
        {
            if(In[i]== Post[PostEnd])
            {
                Create_BinTree_PostIn(In,InStart,i-1,Post,PostStart,PostStart+i-1-InStart,&(*T)->Lchild);
                Create_BinTree_PostIn(In,i+1,InEnd,Post, PostStart+i-InStart,PostEnd-1,&(*T)->Rchild);
                break;
            }
            if(i>InEnd)
            {
                printf("输入错误!n");
                exit(1);
            }
        }
    }
}



void Preorder(BinTree T)/* 先序遍历二叉树*/
{if(T!=NULL)
    {
        printf("%c",T->data);
        Preorder(T->Lchild);
        Preorder(T->Rchild);
    }
}

void inorder(BinTree T) /* 中序遍历二叉树*/
{if(T!=NULL)
    {
        inorder(T->Lchild);
        printf("%c",T->data);
        inorder(T->Rchild);
    }
}

void postorder(BinTree T) /* 后序遍历二叉树*/
{if(T!=NULL)
    {
        postorder(T->Lchild);
        postorder(T->Rchild);
        printf("%c",T->data);
    }
}

Status BinTreeEmpty(BinTree T) /* 判断二叉树是否为空*/
{ /* 初始条件: 二叉树T存在 */
    /* 操作结果: 若T为空二叉树,则返回TRUE,否则FALSE */
    if(T)
        return FALSE;
    else
        return TRUE;
}

int BinTreeDepth(BinTree T)/*求二叉树深度，或者求二叉树高度*/
{ /* 初始条件: 二叉树T存在。操作结果: 返回T的高度 */
    int hl,hr;
    if(!T) return 0;
    if(T->Lchild)
        hl=BinTreeDepth(T->Lchild);
    else
        hl=0;
    if(T->Rchild)
        hr=BinTreeDepth(T->Rchild);
    else
        hr=0;
    return (hl>hr? hl: hr)+1;
}

/* 初始条件: 二叉树T存在。操作结果: 返回T的根结点的值 */
ElemType Root(BinTree T)

{
    if(BinTreeEmpty (T))
        return ' ';
    else
        return T->data;
}

int Size(BinTree T) /* 统计二叉树中结点数 */
{
    if (T==NULL) return 0;

        if(T->Lchild==NULL&&T->Rchild==NULL)
        return 1;
    else
        return 1+ Size(T->Lchild)+ Size(T->Rchild);
}

void Size_Preorder(BinTree T)  /* 使用全局变量Count ，统计二叉树中结点数 */
{
    if(T!=NULL)
    {
        Count++;
        Size_Preorder(T->Lchild);
        Size_Preorder(T->Rchild);
    }
}

void Leaves_inorder(BinTree T) /* 输出二叉树中所有叶子结点 */
/*输出度为1的值*/
{
    if(T!=NULL)
    {
        Leaves_inorder (T->Lchild);
        if (T->Lchild==NULL && T->Rchild == NULL)
            printf("%c ",T->data);
        Leaves_inorder (T->Rchild);
    }
}

int CLeaves_postorder(BinTree T) /* 统计二叉树中叶子结点数目 */
{int nl,nr;
    if(T==NULL) return 0;
    if (T->Lchild == NULL && T->Rchild == NULL) return 1;
    nl= CLeaves_postorder(T->Lchild);
    nr= CLeaves_postorder(T->Rchild);
    return nl+nr;
}

void Tree_Height(BinTree T,int h)  /* 全局变量法求二叉树高度 */
{if(T)
    {
        if(h>Depth) Depth=h;
        Tree_Height (T->Lchild,h+1);
        Tree_Height (T->Rchild,h+1);
    }
}

BinTree Parent(BinTree T, BinTree Current)  /* 寻找双亲结点，Current为待求结点的地址 */
{
    BinTree p;
    if(!T) return NULL;
    if(p->Lchild == NULL || p->Rchild == NULL)
        return T;
    p= Parent(T->Lchild,Current);
    if(p!=NULL) return p;

    return Parent(T->Rchild,Current);
}


BinTree Parent1(BinTree T, ElemType ch)/* 按输入的结点名寻找双亲结点 */
{
    BinTree p;
    if(!T) return NULL;
    if((T->Lchild!=NULL && T->Lchild->data == ch) || (T->Rchild && T->Rchild->data)) return T;
    p= Parent1(T->Lchild,ch);
    if(p!=NULL) return p;
    else return(Parent1(T->Rchild,ch));
}

void Ancestors(BinTree T, ElemType ch)/* 按输入的节点名寻找双亲结点 */
{
    BinTree p;
    if(Parent1(T,ch)!=NULL)
    {
        p= Parent1(T,ch);
        printf("%c ",p->data);
    }
}


/*void PrintTree(BinTree T, int h)*//* 按树状（层次）打印二叉树 *//*
{
    int i;
    if(!T) return;
    PrintTree(T->Rchild,h+1);
    for (i=1;i<h;i++) printf("   ");
    printf("%c\n",T->data);
    PrintTree(T->Lchild,h+1);
}*/
void PrintTree(BinTree T, int level) {
    if (T == NULL) return;

    PrintTree(T->Rchild, level + 1);

    for (int i = 0; i < level; i++) {
        printf("   ");
    }
    printf("%c\n", T->data);

    PrintTree(T->Lchild, level + 1);
}

int main()
{
    BinTree BT=NULL,temp;
    ElemType  e;
    int j=1,k;
    char choice,ch;
    char PRE[MAXSIZE],IN[MAXSIZE],POST[MAXSIZE];//三个数组用来存放先序序列、中序序列和后序序列

    while(choice!='Q' && choice!='q')                //当choice的值不为q且不为Q时循环
    {
        printf("\n       ********************* 二 叉 树 常 用 算 法 *********************\n");
        printf("            C. Create         T. Traverse      A. Attributes\n");
        printf("            D. Display        P. Parents       Q. Exit\n\n");

        if(j==1) {printf("注意：请先执行C(Create)一次\n\n");  j++;}
        printf("请选择您要执行的二叉树操作：");
        scanf("%c",&choice);
        while((ch = getchar()) != '\n' && ch != EOF);

        if(choice=='C'||choice=='c')
        {
            printf("  1、扩展的先序遍历序列\n");
            printf("  2、后序序列和中序序列\n");
            printf("  3、先序序列和中序序列\n");
            printf("请您选择创建二叉树的方式(1~3)：");
            scanf("%d",&k);
            while(k!=1 && k!=2 && k!=3)
            {printf("输入错误! 请您重新输入(1~3)：");
                scanf("%d",&k);}
            while((ch = getchar()) != '\n' && ch != EOF);
            if (k==1)
            {
                printf("提示：以^作为空子树的标识：");
                BT=Create_BinTree();
                while((ch = getchar()) != '\n' && ch != EOF);
            }
            else if(k==2)
            {printf("请输入后序序列:");
                gets(POST);
                printf("请输入中序序列:");
                gets(IN);
                Create_BinTree_PostIn(IN,0,strlen(IN)-1,POST,0,strlen(POST)-1,&BT);
            }
            else
            {printf("请输入先序序列:");
                gets(PRE);
                printf("请输入中序序列:");
                gets(IN);
                Create_BinTree_PreIn(IN,0,strlen(IN)-1,PRE,0,strlen(PRE)-1,&BT);
            }
            if (!BinTreeEmpty(BT))
                printf("二叉树创建成功!\n");
        }

        else if(choice=='T'||choice=='t')
        {
            printf("递归遍历结果:\n    先序遍历二叉树：");
            Preorder(BT);
            printf("\n");
            printf("    中序遍历二叉树：");
            inorder(BT);
            printf("\n");
            printf("    后序遍历二叉树：");
            postorder(BT);
            printf("\n");
            printf("层次遍历结果:\n    层次遍历二叉树：\n");
            PrintTree(BT,BinTreeDepth(BT));
            printf("\n");
        }

        else if(choice=='A'||choice=='a')
        {
            Count=0;
            Size_Preorder(BT);
            printf("二叉树的度：2，高度：%d\n",BinTreeDepth(BT));
            printf("    根结点：%c，结点数：%d，边数：%d\n",Root(BT),Count,Size(BT)-1);
            printf("    叶结点数：%d，分别为：", CLeaves_postorder(BT));
            Leaves_inorder(BT);
            printf("\n");
        }

        else if(choice=='D'||choice=='d')
        {
            printf("树状打印：\n");
            PrintTree(BT, 1);
        }

        else if(choice=='P'||choice=='p')
        {
            printf("请输入待查结点：");
            scanf("%c",&e);
            while((ch = getchar()) != '\n' && ch != EOF);
            printf("待查结点%c", e);
            temp=Parent1(BT, e);
            if(temp!=NULL)
            {printf("的双亲结点为%c，祖先结点为：", temp->data);
                Ancestors(BT,e);
                printf("\n");}
            else
                printf("无双亲结点\n");

        }

        else if(choice=='Q'||choice=='q')
            exit(0);

        else               //如果选了选项之外的就让用户重新选择
            printf("您没有输入正确的操作指令，请重新输入！\n");
        printf("\n");
    }
    return 0;
}






