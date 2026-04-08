#include <bits/stdc++.h>

using namespace std;

/*
1 제외
2 이상일 경우
소수 -> 무조건 닫
소수의 짝수 제곱 상태
4 9 16 1

*/

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	long long i, j, k, l, N, result = 0, con;
	cin >> N;
	vector<long long> prime;
	for (i = 1; i * i <= N; i++) {
		result++;
	}
	cout << result;

	return 0;
}