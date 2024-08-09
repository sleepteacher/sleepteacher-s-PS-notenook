#include <bits/stdc++.h>

#define ARR_SIZE 26
#define MOD 1000000007LL

using namespace std;

int dp[200001];

int get_index(char a) {
	// 인덱스 불러오기,
	// mod 1 대문자 0 소문자
	return a - 'a';
}

struct Trie {
	bool is_string_end;
	long long has_cnt;
	Trie *children[ARR_SIZE];
	// 생성자
	Trie() : is_string_end(0), has_cnt(0) {
		memset(children, 0, sizeof(children));
	}
	// 소멸자
	~Trie() {
		for (int i = 0; i < ARR_SIZE; i++) {
			if (children[i]) delete children[i];
		}
	}
	void insert(const char *str) {
		has_cnt++;
		if (*str == 0) {
			is_string_end = 1;
		} else {
			int next_index = get_index(*str);
			if (children[next_index] == 0) children[next_index] = new Trie;
			children[next_index]->insert(str + 1);
		}
	}
	Trie *find(const char *str, int start_idx, int now_idx) {
		if (start_idx <= now_idx) {
			dp[now_idx + 1] = (dp[now_idx + 1] + dp[start_idx] * has_cnt) % MOD;
			// cout << now_idx << " " << has_cnt << "\n";
		}
		if (*str == 0) {
			return this;
		}
		int next_index = get_index(*str);
		if (children[next_index] == 0) return NULL;
		return children[next_index]->find(str + 1, start_idx, now_idx + 1);
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
	Trie *root = new Trie();
	string in;
	vector<string> arr;
	int i, j, k, l, N;
	fill(dp, dp + 200001, 0);
	dp[0] = 1;
	cin >> N;
	arr.resize(N);
	for (i = 0; i < N; i++) {
		cin >> in;
		root->insert(in.c_str());
	}
	cin >> in;
	for (i = 1; i <= in.size(); i++) {
		root->find(in.c_str() + i - 1, i - 1, i - 2);
	}
	cout << dp[in.size()] << "\n";

	delete root;

	return 0;
}
