#include <bits/stdc++.h>

#define ARR_SIZE 10

using namespace std;

int con;

int get_index(char a) {
	// 인덱스 불러오기,
	// mod 1 대문자 0 소문자
	return a - '0';
}

struct Trie {
	bool is_string_end;
	Trie *children[ARR_SIZE];
	// 생성자
	Trie() : is_string_end(0) {
		memset(children, 0, sizeof(children));
	}
	// 소멸자
	~Trie() {
		for (int i = 0; i < ARR_SIZE; i++) {
			if (children[i]) delete children[i];
		}
	}
	void insert(const char *str) {
		if (*str == 0) {
			is_string_end = 1;
		} else {
			int next_index = get_index(*str);
			if ((children[next_index] != 0 && *(str + 1) == 0) || is_string_end) {
				con = 1;
				return;
			}
			if (children[next_index] == 0) children[next_index] = new Trie;
			children[next_index]->insert(str + 1);
		}
	}
	Trie *find(const char *str) {
		if (*str == 0) {
			return this;
		}
		int next_index = get_index(*str);
		if (children[next_index] == 0) return NULL;
		return children[next_index]->find(str + 1);
	}
	bool string_has(const char *str) {
		if (*str == 0 && is_string_end) {
			return 1;
		}
		int next_index = get_index(*str);
		if (children[next_index] == 0) return 0;
		return children[next_index]->string_has(str + 1);
	}
};

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int TC;
	cin >> TC;
	while (TC--) {
		Trie *root = new Trie();
		string in;
		con = 0;
		int i, j, k, l, N;
		cin >> N;
		for (i = 0; i < N; i++) {
			cin >> in;
			root->insert(in.c_str());
		}
		if (con) {
			cout << "NO" << "\n";
		} else {
			cout << "YES" << "\n";
		}
		delete root;
	}

	return 0;
}
