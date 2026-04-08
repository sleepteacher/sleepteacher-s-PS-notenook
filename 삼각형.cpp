#include <bits/stdc++.h>

using namespace std;

double length(pair<int, int> a, pair<int, int> b) {
	return sqrtl((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
}

int vector_atob_x(pair<int, int> a, pair<int, int> b) {
	return b.first - a.first;
}

int vector_atob_y(pair<int, int> a, pair<int, int> b) {
	return b.second - a.second;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	pair<int, int> a, b, c;
	int i, j, k, l;
	double AB, BC, AC, angle_arr[3], length_arr[3];
	cin >> a.first >> a.second;
	cin >> b.first >> b.second;
	cin >> c.first >> c.second;

	length_arr[0] = length(a, b);
	length_arr[1] = length(b, c);
	length_arr[2] = length(a, c);

	angle_arr[0] = ((vector_atob_x(a, b) * vector_atob_x(a, c)) + (vector_atob_y(a, b) * vector_atob_y(a, c))) / (length_arr[0] * length_arr[2]);
	angle_arr[1] = ((vector_atob_x(b, a) * vector_atob_x(b, c)) + (vector_atob_y(b, a) * vector_atob_y(b, c))) / (length_arr[0] * length_arr[1]);
	angle_arr[2] = ((vector_atob_x(c, b) * vector_atob_x(c, a)) + (vector_atob_y(c, b) * vector_atob_y(c, a))) / (length_arr[1] * length_arr[2]);

	sort(angle_arr, angle_arr + 3);
	sort(length_arr, length_arr + 3);

	//cout << length_arr[0] << " " << length_arr[1] << " " << length_arr[2] << "\n";
	//cout << angle_arr[0] << " " << angle_arr[1] << " " << angle_arr[2] << "\n";

	if (angle_arr[0] == -1 && angle_arr[1] == 1 && angle_arr[1] == 1)
		cout
			<< "X";
	else if (angle_arr[0] < 0) {
		if (length_arr[0] == length_arr[1] || length_arr[0] == length_arr[2] || length_arr[1] == length_arr[2]) {
			cout << "Dunkak2Triangle";
		} else {
			cout << "DunkakTriangle";
		}
	} else if (angle_arr[0] == 0) {
		if (length_arr[0] == length_arr[1] || length_arr[0] == length_arr[2] || length_arr[1] == length_arr[2]) {
			cout << "Jikkak2Triangle";
		} else {
			cout << "JikkakTriangle";
		}
	} else {
		if (length_arr[0] == length_arr[1] || length_arr[0] == length_arr[2] || length_arr[1] == length_arr[2]) {
			if (length_arr[0] == length_arr[1] && length_arr[0] == length_arr[2]) {
				cout << "JungTriangle";
			} else {
				cout << "Yeahkak2Triangle";
			}
		} else {
			cout << "YeahkakTriangle";
		}
	}

	return 0;
}