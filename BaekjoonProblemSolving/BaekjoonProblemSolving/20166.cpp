// https://www.acmicpc.net/problem/20166

/*
#include <iostream>
#include <cstring>
using namespace std;

#define ALPHABETS 26

int char_to_index(char c) {
	return c - 'a';
}

struct Trie {

	int kind;
	Trie* children[ALPHABETS];

	Trie() : kind(0) {
		memset(children, 0, sizeof(children));
	}


	~Trie() {
		for (int i = 0; i < ALPHABETS; ++i) {
			if (children[i])
				delete children[i];
		}
	}

	void insert(const char* key, int kind) {
		if (*key == '\0') {
			this->kind = kind;
		}
		else {
			int index = char_to_index(*key);

			if (children[index] == 0)
				children[index] = new Trie();
			children[index]->insert(key + 1, kind);
		}
	}

	int find(const char* key) {
		if (*key == 0) {
			return this->kind;
		}

		int index = char_to_index(*key);
		if (children[index] == 0) {
			return 0;
		}

		return children[index]->find(key + 1);
	}
};

int n, m, k, res[1001], target[1001]; // 세로, 가로, 단어수
string table[10];
string word;
Trie* root;
const int dx[8] = { -1, 0, 1, -1, 1, -1, 0, 1 }, dy[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };

void dfs(int y, int x, Trie* trie) {
	
	char c = table[y][x];
	
	int index = char_to_index(c);
	if (trie->children[index] == 0) return;
	Trie* t_trie = trie->children[index];

	if (t_trie->kind) {
		res[t_trie->kind]++;
	}

	for (int dir = 0; dir < 8; dir++) {
		int ty = (y + dy[dir] + n) % n, tx = (x + dx[dir] + m) % m;
		if (t_trie->children[char_to_index(table[ty][tx])] == 0) continue;
		dfs(ty, tx, t_trie);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	root = new Trie();

	cin >> n >> m >> k;

	for (int i = 0; i < n; i++)
		cin >> table[i];
	for (int i = 0; i < k; i++) {
		cin >> word;
		int temp = 0;
		if (temp = root->find(word.c_str())) {
			target[i + 1] = temp;
		}
		else {
			target[i + 1] = i + 1;
			root->insert(word.c_str(), i + 1);
		}
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			dfs(i, j, root);
		}
	}

	for (int i = 1; i <= k; i++)
		cout << res[target[i]] << "\n";
}

*/