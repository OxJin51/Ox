//
// Created by 我的名字是Ox on 2024/10/18 018.
//
#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#define endl "\n"
typedef long long ll;
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);std::cin.tie(0);
    string isbn;
    cin >> isbn; // 读取整个 ISBN，包括短横线

    int nums[9]; // 存储前 9 个数字
    int j = 0;

    for (char c : isbn) {
        if (c != '-') {
            nums[j++] = c - '0'; // 转换为整数
        }
    }
    int sum=0,id;

    for(int i=0;i<9;i++)
    {
        sum+=nums[i]*(i+1);
    }
    char res ;
    if(sum%11!=10) res= (sum%11)+'0';
    else res = 'X';

    if (isbn.back() == res) {
        cout << "Right";
    } else {
        isbn.erase(isbn.end() - 1);
        isbn += res;
        cout << isbn;
    }




    return 0;
}