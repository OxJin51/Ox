#include <iostream>
#include <cmath>
#define endl "\n"
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int x, y;
        cin >> x >> y;

        int totalScreens = 0;

        // Calculate the screens needed for 2x2 icons
        totalScreens += (4 * y + 14) / 15;

        // Calculate remaining 1x1 icons
        int usedCellsFor2x2 = 4 * y;
        int remainingCellsAfter2x2 = totalScreens * 15 - usedCellsFor2x2;

        if (remainingCellsAfter2x2 >= x) {
            // Remaining cells are enough to fit all 1x1 icons
        } else {
            // Additional screens needed for 1x1 icons
            x -= remainingCellsAfter2x2;
            totalScreens += (x + 14) / 15;
        }

        cout << totalScreens << endl;
    }

    return 0;
}
