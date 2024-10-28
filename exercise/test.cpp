#include<iostream>
using namespace std;

int main() {
    std::ios::sync_with_stdio(false); std::cin.tie(0);
    int t = 12;         // 月数
    int total = 0;     // 总钱数
    int save = 0;      // 存到妈妈那里去的钱

    for (int month = 0; month < 12; month++)
    {
        int budget;
        cin >> budget;  // 读取每个月的预算
        total += 300;   // 每个月初获得300元

        // 检查是否满足预算
        if (total < budget) {
            cout << '-' << (month + 1); // 输出不足的月份
            return 0;
        }

        // 检查能否存钱
        int remaining = total - budget; // 扣除预算后的剩余钱数
        if (remaining >= 100) {
            int amount_to_save = remaining / 100 * 100; // 存整百的钱
            save += amount_to_save; // 增加存钱的总额
            total -= amount_to_save; // 从总钱数中扣除存入的钱
        }

        // 扣除当月的预算
        total -= budget;
    }

    // 年末将存的钱加上20%
    int final_amount = total + save * 1.2;
    cout << final_amount; // 输出年末的钱数
    return 0;
}
