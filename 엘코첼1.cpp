#include <iostream>
#include <vector>

using namespace std;

int main() {
	int i, j, k, l, N, con;
	vector<int> arr, inp(10, 0);
	cin >> N;
	for (i = N; i != 0; i /= 10)
		inp[i % 10]++;

	for (i = N + 1; i < 1000000; i++) {
		arr = vector<int>(inp);
		con = 0;
		for (j = i; j != 0; j /= 10)
			arr[j % 10]--;
		for (j = 0; j < 10; j++) {
			if (arr[j]) con = 1;
		}
		if (!con) {
			cout << i << "\n";
			break;
		}
	}

	return 0;
}
