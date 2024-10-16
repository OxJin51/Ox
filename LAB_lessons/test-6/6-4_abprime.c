//
// Created by 我的名字是Ox on 2023/12/14 014.
//
/*一个素数，当它的数字位置对换后仍为素数，这样的数称为绝对素数。
编程输出所有的两位绝对素数。（输出格式%5d ）
（如：17是素数，数字位对换后为71也是素数，所以17为绝对素数）*/
#include<stdio.h>

// 判断一个数是否为素数的函数
int isPrime(int num)
{
    if (num <= 1)
    {
        return 0; // 0和1不是素数
    }

    for (int i = 2; i * i <= num; i++)
    {
        if (num % i == 0) {
            return 0; // 如果num能被2到sqrt(num)之间的任何数整除，那么它不是素数
        }
    }

    return 1; // 如果没有找到除数，它是素数
}

int reverseNumber(int num) {
    int reversed = 0;

    while (num != 0) {
        int digit = num % 10;
        reversed = reversed * 10 + digit;
        num /= 10;
    }

    return reversed;
}

int main(){
    for (int abprime = 10; abprime < 100; abprime++) {
        int reversed = reverseNumber(abprime);

        if (isPrime(abprime) && isPrime(reversed)) {
            printf("%5d", abprime);
        }
    }

    return 0;
}