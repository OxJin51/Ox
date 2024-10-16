//
// Created by 我的名字是Ox on 2023/12/14 014.
//
/*
由于雾霾红色预警，车辆将限号出行，规定如下：
（1）尾号是0,2,4,6,8，双日出行，例如AZ7Y68,WJ-2126；
（2）尾号是其他数字、字母或符号的，单日出行，例如AZ7Y69,WJ-2127,B3300B；
请完善下面的程序以实现上线描述的功能。要求根据输入的车牌号分别输出“双日出行”或“单日出行”。
 #include<stdio.h>
void main()
{
char s[10];     //用于存储车牌号
int I;
printf(“Input s:”);
scanf(“%s”,s);  //输入车牌号
//请在下面继续完成程序
*/
#include<stdio.h>
#include <string.h>

int main()
{
char s[10]; //用于存储车牌号
int i,j;
printf("Input s:");
    scanf("%s",s);  //输入车牌号
    i=strlen(s);
   if(s[i-1]=='0'||s[i-1]=='2'||s[i-1]=='4'||s[i-1]=='6'||s[i-1]=='8')
    {
       printf("双日出行\n");
    }
   else
       printf("单日出行\n");
    return 0;
}