#include <bits/stdc++.h>

using namespace std;

int jug[4][4][4];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int i, j, k, l, N, M, temp, run[3][3], loop[3], result[64];
	string a;
	char arr[4][4] = {{'k', 'e', 'm', '-'}, {'a', 'p', 'o', '-'}, {'r', 'b', 'g', '-'}};
	cin >> N >> M;
	for (i = 0; i < N; i++) {
		fill(loop, loop + 2, 0);
		for (j = 0; j < 3; j++) {
			cin >> a;
			for (k = 0; k < 3; k++) {
				if (a[0] == arr[j][k]) {
					loop[j] = k;
					break;
				}
			}
		}
		jug[*loop][*(loop + 1)][*(loop + 2)] += 1;
		/*본인*/
		jug[3][*(loop + 1)][*(loop + 2)] += 1;
		jug[*loop][3][*(loop + 2)] += 1;
		jug[*loop][*(loop + 1)][3] += 1;
		/*-1개*/
		jug[3][3][3] += 1;
		/*3개*/
		jug[3][3][*(loop + 2)] += 1;
		jug[3][*(loop + 1)][3] += 1;
		jug[*loop][3][3] += 1;
		/*2개*/
	}
	for (i = 0; i < M; i++) {
		for (j = 0; j < 3; j++) {
			cin >> a;
			for (k = 0; k < 4; k++) {
				if (a[0] == arr[j][k]) {
					loop[j] = k;
					break;
				}
			}
		}
		cout << jug[*loop][*(loop + 1)][*(loop + 2)] << "\n";
	}

	return 0;
}