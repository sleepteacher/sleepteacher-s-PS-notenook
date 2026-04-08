#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int i, j, k, l, a, b, c, A, B, C, result = 0, am, bm, cm, get_each;
	cin >> a >> b >> c >> A >> B >> C;
	if (a < A) {
		am = A - a;
		a += am;
		b -= (am * 11);
		result += am;
	}
	// cout << a << " " << b << " " << c << "\n";
	if (b < B) {
		bm = B - b;
		if (0 < a - A) {
			get_each = min((a - A), (bm + 8) / 9);
			a -= get_each;
			result += get_each;
			bm -= get_each * 9;
			b += get_each * 9;
		}
		if (bm > 0 && 0 < c - C) {
			get_each = bm;
			b += get_each;
			result += get_each;
			bm -= get_each * 11;
			c -= get_each * 11;
		}
	}
	// cout << a << " " << b << " " << c << "\n";
	// 11 + 9 + 1
	if (c < C) {
		cm = C - c;
		get_each = (cm + 8) / 9;
		c += get_each * 9;
		b -= get_each;
		result += get_each;

		bm = B - b;
		if (bm > 0 && 0 < a - A) {
			get_each = min((a - A), (bm + 8) / 9);
			a -= get_each;
			result += get_each;
			bm -= get_each * 9;
			b += get_each * 9;
		}
	}
	// cout << a << " " << b << " " << c << "\n";
	if (a >= A && b >= B && c >= C)
		cout << result;
	else
		cout << -1;

	return 0;
}