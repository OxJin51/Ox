//
// Created by 我的名字是Ox on 2024/5/14 014.
//
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
#define FALSE 0
#define TRUE 1

#define MAXSIZE 50     /*初始分配的顺序串长度*/
typedef char ElemType;  /*限定字符串元素值域必须为字符集*/

typedef struct string
{
    ElemType ch[MAXSIZE];      /*存储字符串的一维数组*/
    int length;           /*字符串的实际长度,不包括结束符*/
}SString;


SString *Create_SeqStr (char *s )  /* 创建一个串，用字符串s初始化它 */
{
    int i;
    SString *pstr = (SString *)malloc(sizeof(SString));	/* 申请串空间 */
    if (pstr==NULL)
        printf("Out of space!!\n");
    else {
        pstr->length=0;
        for (i=0; *s!='\0'; i++)  //把串s存储到字符串pstr中，并输出字符串
        {
            //printf("%c,",*s);
            pstr->ch[i]= *s++;
            pstr->length++;
        }
        return pstr;
    }
}

/*遍历顺序串s的所有字符*/
void Traverse_SString(SString *S)
{
    int i;
    for(i=0;i<S->length;i++)
        printf("%c",S->ch[i]);
    printf("\n");
    //	return TRUE;
}/*TraverseList*/

/*1、串插入：在串S的第pos个字符处开始，插入串T*/
int SStrInsert(SString *S, int pos, const SString *T)
{
    int i;
    if(NULL==S||NULL==S->ch||NULL==T|| pos<0 ||pos>S->length)
        return FALSE;
    if(S->length+T->length<MAXSIZE-1)//判断两个串长相加后是否溢出
    {
        for(i=S->length-1;i>=pos-1;i--) //先把S串中插入位置后的字符，移动位置
            S->ch[i+T->length] = S->ch[i];

        for(i=0;i<T->length;i++)  //把串T插入到串S的第pos位
            S->ch[pos-1+i]=T->ch[i];

        S->length+=T->length; //串S长度更新

        return  TRUE;
    }
    else
        return FALSE;
}

/*2、串删除：从串S中删除从第pos个字符开始连续len个字符后形成的子串*/
int SStrDelete(SString *S, int pos, int len)
{
    int i;
    if(NULL==S||NULL==S->ch||len<0||pos<0||pos>S->length-len)
        return FALSE;
    else
    {
        for(i=pos+len-1;i<S->length;i++) //挪动元素实现从第pos个字符开始删除len个字符
            S->ch[i-len]=S->ch[i];
        S->length-=len;//串S长度更新
        return TRUE;
    }
}

/*3、串连接：将串T的值连接在串S的后面*/
int SStrCat(SString *S, SString *T)
{
    int i;
    if(NULL==S||NULL==S->ch||NULL==T->ch)
        return FALSE;
    if(S->length+T->length<MAXSIZE-1)//判断是否符合连接条件
    {
        for(i=0;i<T->length;i++)//把T中字符依次存入S中
            S->ch[i+S->length]= T->ch[i];
        S->length+=T->length;//串长更新
        return TRUE;
    }
    else
        return FALSE;
}

/*4、求子串：截取串S中从第pos个字符开始连续len个字符形成的子串，并复制给串T*/
int SStrSub(SString *T, SString *S, int pos, int len)
{
    int i;
    if(NULL==S||NULL==S->ch||NULL==T||NULL==T->ch||len<0||len>S->length-pos+1||pos<0||pos>S->length)
        return FALSE;
    //for(i=pos-1;i<pos+len;i++)  T->ch[i-pos+1]=S->ch[i];
    for(i=0;i<len;i++)  T->ch[i]=S->ch[i+pos-1];
    T->length=len;//设置串T长度

    return TRUE;
}

/*5、串比较：比较串S和串T的大小，S等于T返回0，S>T返回1，S<T返回-1*/
int SStrCompare(SString *S, SString *T)
{
    int i;
    if(NULL==S||NULL==S->ch||NULL==T||NULL==T->ch)
        printf("串S或串T不存在，不能比较！\n");
    else{
        for(i=0;i<S->length&&i<T->length;i++) //S和T中对应位置字符依次比较
        {
            if(S->ch[i]!=T->ch[i])  //判断比较是否进行
                break;
        }

        if(i==S->length&&i==T->length)//串S和串T相等
            return 0;
        if(S->ch[i]>T->ch[i])//串S>串T
            return 1;
        if(S->ch[i]<T->ch[i])//串S<串T
            return -1;
    }
}
/* 6、串匹配：蛮力（朴素）模式匹配算法：BF算法 */
/*在串S中第pos个字符处开始查找，串T是否存在,若存在，返回查找成功位序，否则返回FASLE*/
int SStrIndex_BF(SString *S, int pos, SString *T){
    int i,j;
    if(NULL==S||NULL==S->ch||NULL==T||NULL==T->ch||pos<0||pos>S->length)
        return FALSE;
    for(i=pos-1;i<S->length;i++)//设置查找区域
    {
        for(j=0;j<T->length;j++)  //从T中取出字符依次与S中字符比较
        {
            if(S->ch[i+j]!=T->ch[j])  //判断比较是否继续
                break;
        }

        if(j==T->length)//查找成功，退出查找过程
            break;
        // return i+1;
    }
    if(i==S->length)//查找失败
        return FALSE;
    else
        return  i+1;
}

/*7、串替换：在主串S中查找子串T，若找到并把子串T替换为子串V */
int SStrReplace(SString *S, SString *T, SString *V) {
    int i, j;
    if (NULL == S || NULL == S->ch || NULL == T || NULL == T->ch || NULL == V || NULL == V->ch)
        return FALSE;
    else {
        i = 0;
        while (i <= S->length - T->length) {
            j = SStrIndex_BF(S, i, T); // j用来存储在串S中子串T的位置
            if (j == 0) {
                i++;
            } else {
                SStrDelete(S, j, T->length); // 在串S中删除子串T
                SStrInsert(S, j, V); // 在串S中第j个位置开始插入子串V
                i = j + V->length; // 更新索引位置，跳过刚插入的子串V
            }
        }
        return TRUE;
    }
}


int main(){
    int i,j;
    char str1[MAXSIZE];//=(char *)malloc(sizeof(char)*MAXSIZE) ;
    char *str2=(char *)malloc(sizeof(char)*MAXSIZE) ;
    char *str3=(char *)malloc(sizeof(char)*MAXSIZE) ;

    SString *StrS=(SString *)malloc(sizeof(SString));
    SString *StrT=(SString *)malloc(sizeof(SString));
    SString *StrV=(SString *)malloc(sizeof(SString));


    printf("\n   ******************************************************************\n");
    printf("\n   *********************** 顺 序 串 常 用 算 法 *********************\n");
    printf("\n   ******************************************************************\n");

    printf("\n1、串插入：在串S的第pos个字符处插入串T\n");
    printf("请输入串S:");
    scanf("%s",str1);
    StrS =Create_SeqStr(str1);
    printf("请输入串T:");
    scanf("%s",str2);
    StrT =Create_SeqStr(str2);
    printf("请输入pos值:");
    scanf("%d",&i);
    if(SStrInsert(StrS,i,StrT))
    {printf("插入成功！\n遍历串S:");
        Traverse_SString(StrS);
    }
    else
        printf("插入失败！\n");


    printf("\n\n2、串删除：从串S中删除从第pos个字符开始连续len个字符后形成的子串\n");
    printf("请输入串S:");
    scanf("%s",str1);
    StrS =Create_SeqStr(str1);
    printf("请输入pos值:");
    scanf("%d",&i);
    printf("请输入len值:");
    scanf("%d",&j);
    if(SStrDelete(StrS,i,j))
    {
        printf("删除成功！\n遍历串S:");
        Traverse_SString(StrS);}
    else
        printf("删除失败！\n");



    printf("\n\n3、串连接：将串T的值连接在串S的后面\n");
    printf("请输入串S:");
    scanf("%s",str1);
    StrS =Create_SeqStr(str1);
    printf("请输入串T:");
    scanf("%s",str2);
    StrT =Create_SeqStr(str2);
    if(SStrCat(StrS,StrT))
    {
        printf("连接成功！\n遍历串S:");
        Traverse_SString(StrS);}
    else
        printf("连接失败！\n");



    printf("\n\n4、求子串：截取串S中从第pos个字符开始连续len个字符形成的子串，并复制给串T\n");
    printf("请输入串S:");
    scanf("%s",str1);
    StrS =Create_SeqStr(str1);
    StrT->length=0;
    printf("请输入pos值:");
    scanf("%d",&i);
    printf("请输入len值:");
    scanf("%d",&j);

    if(SStrSub(StrT,StrS,i,j))
    {
        printf("求子串成功！\n遍历串T:");
        Traverse_SString(StrT);}
    else
        printf("求子串失败！\n");


    printf("\n\n5、串比较：比较串S和串T的大小，S等于T返回0，S>T返回1，S<T返回-1\n");
    printf("请输入串S:");
    scanf("%s",str1);
    StrS =Create_SeqStr(str1);
    printf("请输入串T:");
    scanf("%s",str2);
    StrT =Create_SeqStr(str2);

    if(SStrCompare(StrS,StrT)==0)
    {
        printf("串S等于串T\n");
        /*Traverse_SString(StrS);
        printf("等于");
        printf("串T：");
        Traverse_SString(StrT);*/
    }
    else
    if(SStrCompare(StrS,StrT)==1)
    {
        printf("串S大于串T\n");
        /*Traverse_SString(StrS);
        printf("");
        printf("：");
        Traverse_SString(StrT);*/
    }
    else
    {
        printf("串S小于串T\n");
        /*Traverse_SString(StrS);
        printf("小于");
        printf("串T：");
        Traverse_SString(StrT);*/
    }


    printf("\n\n6、串匹配：蛮力(BF)模式匹配算法:\n");
    printf("在串S中第pos个字符处开始查找，串T是否存在,若存在，返回查找成功位序，否则返回FALSE\n");
    printf("请输入串S:");
    scanf("%s",str1);
    StrS =Create_SeqStr(str1);
    printf("请输入串T:");
    scanf("%s",str2);
    StrT =Create_SeqStr(str2);
    printf("请输入pos值:");
    scanf("%d",&i);
    if(SStrIndex_BF(StrS, i, StrT))
    {printf("匹配成功！\n返回串T在串S中位序:");
        printf("   %d\n",SStrIndex_BF(StrS, i, StrT));
    }
    else
        printf("匹配失败！\n");



    printf("\n\n7、串替换：在主串S中查找子串T，若找到并把子串T替换为子串V\n");
    printf("请输入串S:");
    scanf("%s",str1);
    StrS =Create_SeqStr(str1);
    printf("请输入串T:");
    scanf("%s",str2);
    StrT =Create_SeqStr(str2);
    printf("请输入串V:");
    scanf("%s",str3);
    StrV =Create_SeqStr(str3);

    if(SStrReplace(StrS,StrT,StrV))
    {printf("替换成功！\n遍历串S:");
        Traverse_SString(StrS);
    }
    else
        printf("插入失败！\n");


}


