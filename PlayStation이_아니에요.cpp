#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int i, j, k, l;
	string inp, buf, result;
	cin >> inp;
	cin >> inp;
	for (i = 0; i < inp.size(); i++) {
		if (buf.size() == 2) {
			if (buf == "PS" && (inp[i] == '4' || inp[i] == '5')) {
			} else {
				buf[0] = buf[1], buf[1] = inp[i], result += inp[i];
			}
		} else {
			result += inp[i], buf += inp[i];
		}
	}
	cout << result << "\n";
	return 0;
}