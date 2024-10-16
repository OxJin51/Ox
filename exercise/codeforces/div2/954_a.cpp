//
// Created by 我的名字是Ox on 2024/5/17 017.
//
#include<iostream>
#include<vector>
#include<algorithm>
#define endl "\n"
typedef long long ll;
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);std::cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int p1, p2, p3;
        cin >> p1 >> p2 >> p3;

        if ((p1 + p2 + p3) % 2 != 0)
        {
            cout << -1 << endl;
            continue;
        }

        int total_points = p1 + p2 + p3;
        int max_possible_draws = total_points / 2;
        bool valid = false;

        for (int d = max_possible_draws; d >= 0; --d)
        {
            int remaining_points = total_points - d;
            int wins = remaining_points / 2;

            int a = d; // Player 1 score from draws
            int b = d; // Player 2 score from draws
            int c = d; // Player 3 score from draws

            // Distribute the remaining win points
            int remaining_wins = wins;
            if (remaining_wins > 0 && a + 2 <= p1) {
                a += 2;
                remaining_wins--;
            }
            if (remaining_wins > 0 && b + 2 <= p2) {
                b += 2;
                remaining_wins--;
            }
            if (remaining_wins > 0 && c + 2 <= p3) {
                c += 2;
                remaining_wins--;
            }

            // Check if the final distribution is valid
            if (a == p1 && b == p2 && c == p3)
            {
                valid = true;
                cout << d << endl;
                break;
            }
        }

        if (!valid) {
            cout << -1 << endl;
        }
    }

    return 0;
}