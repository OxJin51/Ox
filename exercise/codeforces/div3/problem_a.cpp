#include <iostream>
#include <cmath>
#define endl "\n"
typedef long long ll;
using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int x, y;
        cin >> x >> y;

        int total = 0;

        if (y != 0)
        {
            total += (y + 1) / 2;
        }

        int use = y * 4;
        int remain = total * 15 - use;

        if (remain>= x)
        {

            cout << total << endl;
            continue;
        }
        else
        {

            x -= remain;
            total += (x + 14) / 15;
        }

        cout << total << endl;
    }

    return 0;
}
