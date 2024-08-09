#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int N, i, j, k, l;
	char tmp;
	string a, b;
	cin >> N;
	for (i = 0; i < N; i++) {
		cin >> a >> b;
		tmp = a[0];
		a[0] = b[0];
		b[0] = tmp;
		cout << a << " " << b << "\n";
	}
	return 0;
}