//
// Created by 我的名字是Ox on 2023/12/14 014.
//
/*
使用循环语句设计程序，删除字符串”0010110100100111”中所有字符‟0‟后并输出。
要求：
(1) 程序应输出11111111
(2)字符数组s最后的储存状态为: “1111111\0‟
程序基本框架如下:
#include<stdio.h>
void main()
{char s[]=”00101101100100111”;        本题只有一个数组*/
#include<stdio.h>
int main()
{
    char str[]="00101101100100111";
    int i,j;
    for(i=0;str[i]!='\0';i++)

    {
        if(str[i]=='0')
        {
            for(j=i+1;str[j]!='\0';j++)
            {
                str[j-1]=str[j];
            }
            str[j-1]='\0';
            i--;
        }

    }
//输出字符串
    puts(str);
    return 0;
}

