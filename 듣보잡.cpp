#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int N, M, i, j, k, l, p = 0;
	map<string, int> d;
	string input;
	cin >> N >> M;
	for (i = 0; i < N; i++) {
		cin >> input;
		d[input]++;
	}
	for (i = 0; i < M; i++) {
		cin >> input;
		d[input]++;
		if (d[input] == 2) p++;
	}
	cout << p << "\n";
	for (auto iter = d.begin(); iter != d.end(); iter++) {
		if ((*iter).second - 2 == 0) {
			cout << (*iter).first << "\n";
		}
	}

	return 0;
}
/*
첫째 줄에 듣도 못한 사람의 수 N, 보도 못한 사람의 수 M이 주어진다. 이어서 둘째 줄부터 N개의 줄에 걸쳐 듣도 못한 사람의 이름과, N+2째 줄부터 보도 못한 사람의 이름이 순서대로 주어진다. 이름은 띄어쓰기 없이 알파벳 소문자로만 이루어지며, 그 길이는 20 이하이다. N, M은 500,000 이하의 자연수이다.

듣도 못한 사람의 명단에는 중복되는 이름이 없으며, 보도 못한 사람의 명단도 마찬가지이다.
듣보잡의 수와 그 명단을 사전순으로 출력한다.
*/