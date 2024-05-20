#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    int x[3], y[3], i, j, k, l, a, b, c, d;
    for (i = 0; i < 3; i++) {
        cin >> x[i] >> y[i];
    }
    a = (x[0] - x[1]);
    b = (y[0] - y[1]);
    c = (x[0] - x[2]);
    d = (y[0] - y[2]);
    j = (a * d - b * c == 0) ? 0 : (a * d - b * c) < 0 ? -1 : 1;
    cout << j;

    return 0;
}