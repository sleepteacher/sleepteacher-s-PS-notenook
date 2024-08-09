#include <bits/stdc++.h>

using namespace std;

vector<int> idx[256];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int i, j, k, l, result = 0, iter;
	string a, b;
	cin >> a >> b;
	for (i = 0; i < a.size(); i++) {
		idx[a[i]].push_back(i);
	}
	for (i = 0; i < b.size(); i++, result++) {
		iter = 0;
		for (j = 0; j < idx[b[i]].size(); j++) {
			for (k = 1; k < a.size(); k++) {
				if (b[i + k] == a[idx[b[i]][j] + k]) {
					iter = max(k, iter);
				} else
					break;
			}
		}
		i += iter;
	}
	cout << result << "\n";
	return 0;
}