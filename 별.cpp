#include <bits/stdc++.h>

using namespace std;

/*
****************
* * * * * * * *
**  **  **  **
*   *   *   *
****    ****
* *     * *
**      **
*       *
********
* * * *
**  **
*   *
****
* *
**
*
위의 삼각형은 입력값 4 정답인 케이스임.
********
* * * *
**  **
*   *
****
* *
**
*
위의 삼각형은 입력값 3이 정답인 케이스임.
해당 부위에 공란을 채운 밑 예제와 같은 곳에 우측, 하단에 배치하면 입력값 4와 같아짐.
이전 테스트 케이스도 같음.

********\\
* * * * \\
**  **  \\
*   *   \\
****    \\
* *     \\
**      \\
*       \\

해당 문제 풀이법
1. 삼각형 복사 후, 복사한 곳에 공란 채우기
2. 복사 한 배열의 우측과 하단에 삼각형 원본 붙이기
3. 만약 추가로 반복 해야한다면 현재 삼각형 넘기고 반복 아니면 그대로 출력
*/
vector<string> recur(vector<string> R, int iter) {
	if (!iter) return R;
	int i, j, k, l;
	vector<string> tmp = R;
	for (i = 0; i < tmp.size(); i++) {
		for (j = 0; j < i; j++) {
			tmp[i] += " ";
		}
	}
	for (i = 0; i < R.size(); i++) {
		tmp[i] += R[i];
		tmp.push_back(R[i]);
	}
	return recur(tmp, iter - 1);
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int i, j, k, l, N;
	vector<string> result;
	cin >> N;
	result = recur({"*"}, N);
	for (i = 0; i < result.size(); i++) {
		cout << result[i] << "\n";
	}
	return 0;
}