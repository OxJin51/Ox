//
// Created by 我的名字是Ox on 2023/12/13 013.
//
#include <cstdio>

int main() {
    // 读取整数值
    int N;
    std::scanf("%d", &N);

    // 钞票面值数组
    int values[] = {100, 50, 20, 10, 5, 2, 1};

    // 输出读取值
    std::printf("%d\n", N);

    // 遍历每种面值的钞票
    for (int i = 0; i < 7; ++i) {
        // 计算当前面值的钞票数量
        int count = N / values[i];

        // 输出当前面值的钞票数量
        std::printf("%d nota(s) de R$ %d,00\n", count, values[i]);

        // 更新剩余值
        N %= values[i];
    }

    return 0;
}
