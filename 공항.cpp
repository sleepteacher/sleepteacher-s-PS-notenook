#include <bits/stdc++.h>

using namespace std;

bool flag[100001];
int UF[100001];
int UF_find(int a) {
	if (UF[a] == a) {
		return a;
	}
	return UF[a] = UF_find(UF[a]);
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int i, j, k, l, max_size, N, input, con, result = 0;
	cin >> max_size >> N;
	flag[0] = 1;
	for (i = 1; i <= max_size; i++) UF[i] = i;
	for (i = 0; i < N; i++) {
		cin >> input;
		con = 1;
		if (!flag[UF[UF_find(input)]]) {
			flag[UF[UF_find(input)]] = 1;
			UF[UF_find(input)]--;
			con = 0;
		}
		if (con) break;
		result++;
	}
	cout << result << "\n";

	return 0;
}