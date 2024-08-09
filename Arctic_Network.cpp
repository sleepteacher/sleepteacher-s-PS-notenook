#include <bits/stdc++.h>


using namespace std;

int UF[100000];

struct cmp {
	bool operator()(tuple<int, int, int> a, tuple<int, int, int> b) {
		return (get<0>(a) < get<0>(b));
	}
};

int UF_find(int a) {
	if (UF[a] < 0) {
		return a;
	}
	return UF[a] = UF_find(UF[a]);
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    return 0;
}