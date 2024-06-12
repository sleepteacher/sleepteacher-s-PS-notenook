#include <bits/stdc++.h>

using namespace std;

int arr[26];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	string a, b;
	int i, j, k, l, N, A, B;
	cin >> a >> N;
	for (i = 0; i < N; i++) {
		cin >> A >> B;
		b = a;
		b[B] = a[A];
		b[A] = a[B];
		a = b;
	}
	cout << a << "\n";

	return 0;
}