/*
 * Created by LixWorth on 2024/03/13 20:42
 * Github: https://github.com/lixworth/
 * Website: https://blog.lix.moe/
 * Contact: lixworth@outlook.com
**/
//#include <bits/stdc++.h>
#include <iostream>
//#include <algorithm>
#define FAST_IO std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);

using namespace std;

using ll = long long;

int isPrime(ll n) {
    ll i;
    for (i = 2; i * i < n; i++) {
        if (n % i == 0)
            return 0;
    }
    return 1;
}

void solve() {
    ll n;
    cin >> n;
    if (isPrime(n)) {
        cout << 1 << endl << n << endl;
        return;
    }
    int max = 0, start = 0;
    for (int i = 2; i * i < n; ++i) {
        if (n % i != 0) continue;
        int sum = 1;
        int count = 0;
        for (int j = i; n % j == 0; ++j) {
            sum *= j;
            if (n % sum != 0) break;
            count++;
        }
        if (count > max) {
            max = count;
            start = i;
        }
    }
    cout << max << endl;
    for (int i = start; i < start + max; ++i) {
        cout << i;
        if (i != start + max - 1) cout << "*";
    }
    cout << endl;
}

int main() {
    FAST_IO;
    int T = 1;
//    cin >> T;
    while (T--) solve();
    return 0;
}