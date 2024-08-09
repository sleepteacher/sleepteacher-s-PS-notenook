#include <bits/stdc++.h>

#define ARR_SIZE 26

using namespace std;

bool color_start_idx[1001];

int get_index(char a) {
	// 인덱스 불러오기,
	// mod 1 대문자 0 소문자
	return a - 'a';
}

struct Trie {
	int is_string_end;
	Trie *children[ARR_SIZE];
	// 생성자
	Trie() : is_string_end(-1) {
		memset(children, 0, sizeof(children));
	}
	// 소멸자
	~Trie() {
		for (int i = 0; i < ARR_SIZE; i++) {
			if (children[i]) delete children[i];
		}
	}
	void insert(const char *str, int mode) {
		if (*str == 0) {
			is_string_end = mode;
			return;
		} else {
			int next_index = get_index(*str);
			if (children[next_index] == 0) children[next_index] = new Trie;
			children[next_index]->insert(str + 1, mode);
		}
	}
	Trie *find(const char *str) {
		if (*str == 0 && is_string_end == 1) {
			return this;
		}
		int next_index = get_index(*str);
		if (children[next_index] == 0) return NULL;
		return children[next_index]->find(str + 1);
	}
	bool string_has(const char *str, int now_idx) {
		if (now_idx >= 0) color_start_idx[now_idx] = (is_string_end == 0);
		if (*str == 0) return is_string_end;
		int next_index = get_index(*str);
		if (children[next_index] == 0) return 0;
		return children[next_index]->string_has(str + 1, now_idx + 1);
	}
};

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int i, j, k, l, color, name, N;
	string in;
	Trie *CL = new Trie();
	unordered_map<string, int> NL;
	cin >> color >> name;
	for (i = 0; i < color; i++) {
		cin >> in;
		CL->insert(in.c_str(), 0);
	}
	for (i = 0; i < name; i++) {
		cin >> in;
		NL[in] = 1;
	}
	cin >> N;
	for (i = 0; i < N; i++) {
		fill(color_start_idx, color_start_idx + 1001, 0);
		cin >> in;
		CL->string_has(in.c_str(), -1);
		for (j = 0; j < 1000; j++) {
			if (color_start_idx[j]) {
				if (NL[in.c_str() + 1 + j]) {
					cout << "Yes" << "\n";
					break;
				}
			}
		}
		if (j == 1000) cout << "No" << "\n";
	}
	delete CL;

	return 0;
}
