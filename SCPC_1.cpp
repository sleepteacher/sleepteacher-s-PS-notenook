#include <bits/stdc++.h>

/*
대문자 A와 B로 구성된 문자열이 주어진다. 철수는 문자열의 연속인 부분에 A가 B보다 더 많은 것을 싫어한다. 부분의 길이가 1인 경우에도 A가 더 많지 않아야 한다면 문자열에 A가 하나도 없어야 한다. 그래서 철수는 길이가 1인 경우는 고려하지 않기로 하였다. 즉, 철수는 문자열에서 연속이고 길이가 2 이상인 어떤 부분에서도 A의 개수가 B의 개수보다 많지 않기를 원한다. 철수가 할 수 있는 일은 주어진 문자열에 B를 끼워 넣는 것이다. 철수가 목적을 달성하기 위해 끼워 넣어야 하는 B의 최소 개수를 계산하는 프로그램을 작성하라.

문자열이 “ABAA”인 경우를 생각해 보자. 연속이고 길이가 2 이상인 부분들 중 A가 더 많은 경우는 “ABA”, “BAA”, “ABAA”, "AA"의 4가지가 있다. B를 3개 추가하여 문자열을 “ABBABBA”로 바꾸면 연속이고 길이가 2 이상인 모든 부분에서 A가 더 많지 않음을 알 수 있다. B를 2개 이하로 추가하는 방법들을 다 따져 보면 모두 조건을 만족시킬 수 없음을 알 수 있다.

조건 TC 50, N 30만
*/

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int TC, N, i, j, k, l, con, result;
	char input;
	cin >> TC;
	for (int iter = 1; iter <= TC; iter++) {
		cin >> N;
		result = 0, con = 2;
		for (i = 0; i < N; i++) {
			cin >> input;
			if (input == 'A') {
				if (con < 2) {
					result += 2 - con;
				}
				con = 0;
			} else {
				con++;
			}
		}
		cout << "Case #" << iter << "\n";
		cout << result << "\n";
	}

	return 0;
}