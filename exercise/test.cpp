#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int log(int n) {
    int power = 1;
    while (power <= n)
    {
        power <<= 1;
    }
    return power >> 1;
}

int main()
{
    std::ios::sync_with_stdio(false);std::cin.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        int l, r;
        cin >> l >> r;
        //x取最大，p取最小
        int maxPower = log(r);
        // 如果最大的 2 的幂小于 l，就选择最大不小于 l 的 2 的幂
        if (maxPower < l)
        {
            maxPower = log(r / 2);
        }

        int score = 0;

        while (maxPower != 1)
        {
            maxPower /= 2;
            score++;
        }

        cout << score << endl;
    }

    return 0;
}
