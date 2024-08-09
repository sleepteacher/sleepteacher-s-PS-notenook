#include <bits/stdc++.h>

using namespace std;

int arr[26];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	string a;
	int i, j, k, l;
	cin >> a;
	for (i = 0; i < a.size(); i++) {
		arr[a[i] - 'a']++;
	}
	for (i = 0; i < 26; i++) {
		cout << arr[i] << " ";
	}
	return 0;
}