#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	string input;
	stack<pair<int, char>> S;
	// 인덱스, 배열
	int i, j, k, l, op = 0, cnt = 0;
	cin >> input;
	for (i = 0; i < input.size(); i++) {
		if (input[i] == '(') {
			S.push({i, '('});

		} else {
			cnt++;
			if (S.size() && S.top().second == '(') {
				S.pop();
			} else {
				cout << cnt << "\n";
				return 0;
			}
		}
	}
	// 마지막에 ( 남은 경우
	// 시작 인덱스부터 선탐
	// ) 남은 경우 cnt 아무값 불러와서
	//
	for (i = S.top().first; i < input.size(); i++)
		if (input[i] == '(') op++;
	cout << op << "\n";

	return 0;
}