#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int i, j, k, l, N, P, con = 0;
	string S, result = "", buf = "";
	cin >> N >> P >> S;
	for (i = 0; i < N; i++) {
		if (S[i] == '(' || S[i] == ')') {
			result += S[i];
		} else if ('0' <= S[i] && S[i] <= '9') {
			if (i + 1 < N) {
				if (S[i + 1] == '*') {
					if (result[result.size() - 1] == '(') con = 2;
					if (!con) {
						result += '(';
						con = 1;
					}
					if (S[i + 2] != '(') {
						result += buf + S[i];
						i++;
						result += S[i];
						buf = "";
					} else {
						result += buf + S[i];
						con = 3;
						i++;
						result += S[i];
						buf = "";
					}

				} else if (S[i + 1] == ')') {
					result += buf + S[i];
					i++;
					result += S[i];
					if (con == 1 || con == 3) {
						result += ')';
						con = 0;
					}
					buf = "";
				} else if (S[i + 1] == '+') {
					result += buf + S[i];
					if (con == 1) {
						result += ')';
						con = 0;
					}
					buf = "";
				} else {
					buf += S[i];
				}
			} else {
				result += buf + S[i];
				if (con == 1) {
					result += ')';
					con = 0;
				}
			}
		} else {
			if (S[i] == '*') {
				buf = result;
				result = "(";
				result += buf;
				result += S[i];
				buf = "";
				con = 1;
			} else
				result += S[i];
		}
	}
	cout << result.size() << "\n";
	cout << result << "\n";

	return 0;
}