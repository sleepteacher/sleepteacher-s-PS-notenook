#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	long long a, b, c, d, e, f, i;
	cin >> a >> b >> c >> d >> e;
	cout << c * e + d << "\n";
	b *= abs(c);
	f = __gcd(a, b);
	if (f == 0) {
		cout << "0 0";
	} else {
		a /= f;
		b /= f;
		if ((a <= 1e8 && b <= 1e8) && !(a == 0 || b == 0))
			cout << a << " " << b;
		else
			cout << "0 0";
	}

	return 0;
}