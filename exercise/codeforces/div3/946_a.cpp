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
        if(y==0)
        {
            //处理x
            int remain = x - 7 * total;

            if (remain > 0)
            {
                if(remain%15==0)
                {
                    total+=remain/15;
                }
                else total+=remain/15+1;
            }

            cout<<total<<endl;
            continue;

        }
        if(y==1)
        {
            //处理x
            int remain = x ;

            if (remain >= 11)
            {
                if(remain%11==0)
                {
                    total+=remain/11;
                }
                else total+=remain/11+1;
            }
            else ;

            cout<<total<<endl;
            continue;

        }
        /*if(x==0)
        {
            continue;
        }*/
        //处理x
        int remain = x - 7 * total;

        if (remain > 0)
        {
            total += (remain + 6) / 7;
        }

        cout << total << endl;
    }

    return 0;
}
