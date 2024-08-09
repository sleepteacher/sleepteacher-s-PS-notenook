#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int i, j, k, l, con = 0, start_val, end_val;
	string input, result, start_iter;
	cin >> input;
	// 시작이 10 미만 일때
	// 시작이 10이상 100 미만 일 때
	// 시작이 100이상 일 떄
	while (con < 4) {
		start_iter = "", result = "", con++;
		for (i = 0; i < con; i++) {
			start_iter += input[i];
		}
		start_val = atoi(start_iter.c_str()), end_val = start_val;
		result = start_iter;
		for (i = start_val + 1; result.size() < input.size(); i++) {
			result += to_string(i);
			end_val = i;
		}
		if (result.size() == input.size()) {
			if (result == input) {
				cout << start_val << " " << end_val;
				return 0;
			}
		}
	}

	return 0;
}