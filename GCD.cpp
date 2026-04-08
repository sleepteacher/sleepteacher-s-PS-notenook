#include <bits/stdc++.h>

using namespace std;
long long prime_table[80001];

typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, k;
	while (!cin.eof() && cin >> n >> k) {
		ll res = 1;

		// 에라토스테네스의 체를 생각해서 루트까지만 돈다
		for (int i = 2; i <= sqrt(k); i++) {
			int primeK = 0;	 // k에 대한 i 지수의 갯수 예를들어 i=3 일 때 primeK=4 이라면 3^4가 약수
			while (k % i == 0) {
				k /= i;
				primeK++;
			}
			int primeN = 0;	 // k와 마찬가지로 n에 대한
			if (primeK > 0) {
				for (int j = i; j <= n; j *= i)	 // 이 부분은 다른 코드를 그대로 참고했는데 참신했다
					primeN += n / j;
			}
			res *= pow(i, min(primeK, primeN));
			if (k < i)
				break;
		}

		// k가 n보다 클 때 n!을 소인수분해 한다면 k가 무조건 존재한다
		if (k > 1 && k < n)
			res *= k;
		cout << res << "\n";
	}
	return 0;
}