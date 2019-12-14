/*
https://www.acmicpc.net/problem/9202

&Title
9202번 - Boggle

&Question
상근이는 보드 게임 "Boggle"을 엄청나게 좋아한다. Boggle은 글자가 
쓰여 있는 주사위로 이루어진 4×4 크기의 그리드에서 최대한 많은 
단어를 찾는 게임이다. 상근이는 한 번도 부인을 Boggle로 이겨본 
적이 없다. 이렇게 질 때마다 상근이는 쓰레기 버리기, 설거지와 
같은 일을 해야 한다. 이제 상근이는 프로그램을 작성해서 부인을 
이겨보려고 한다.Boggle에서 단어는 인접한 글자(가로, 세로, 대각선)를 이용해서 만들 
수 있다. 하지만, 한 주사위는 단어에 한 번만 사용할 
수 있다. 단어는 게임 사전에 등재되어 있는 단어만 올바른 
단어이다.1글자, 2글자로 이루어진 단어는 0점, 3글자, 4글자는 1점, 5글자는 
2점, 6글자는 3점, 7글자는 5점, 8글자는 11점이다. 점수는 자신이 
찾은 단어에 해당하는 점수의 총 합이다.단어 사전에 등재되어 있는 
단어의 목록과 Boggle 게임 보드가 주어졌을 때, 얻을 수 
있는 최대 점수, 가장 긴 단어, 찾은 단어의 수를 
구하는 프로그램을 작성하시오. 

&Input
첫째 줄에 단어 사전에 들어있는 단어의 수 w가 
주어진다. (1 < w < 300,000) 다음 w개 줄에는 
단어가 주어진다. 단어는 최대 8글자이고, 알파벳 대문자로만 이루어져 있다. 
단어 사전에 대한 정보가 모두 주어진 이후에는 빈 줄이 
하나 주어진다.그 다음에는 Boggle 보드의 개수 b가 주어진다. (1 
< b < 30) 모든 Boggle은 알파벳 대문자로 이루어져 
있고, 4줄에 걸쳐 주어진다. 각 Boggle의 사이에는 빈 줄이 
하나 있다. 

&Output
각각의 Boggle에 대해, 얻을 수 있는 최대 점수, 
가장 긴 단어, 찾은 단어의 개수를 출력한다. 한 Boggle에서 
같은 단어를 여러 번 찾은 경우에는 한 번만 찾은 
것으로 센다. 가장 긴 단어가 여러 개인 경우에는 사전 
순으로 앞서는 것을 출력한다. 각 Boggle에 대해서 찾을 수 
있는 단어가 적어도 한 개인 경우만 입력으로 주어진다. 

&Example
-input
5
ICPC
ACM
CONTEST
GCPC
PROGRAMM

3
ACMA
APCA
TOGI
NEST

PCMM
RXAI
ORCN
GPCG

ICPC
GCPC
ICPC
GCPC

-output
8 CONTEST 4
14 PROGRAMM 4
2 GCPC 2


*/

/*
#include <iostream>
#include <cstring>
#include <unordered_set>
using namespace std;

int w, b;
bool visited[4][4];
string map[4];
unordered_set<string> res;
int dy[8] = { -1, -1, -1, 0, 0, 1, 1, 1 }, dx[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };
int score[9] = { 0, 0, 0, 1, 1, 2, 3, 5, 11 };

struct trie {
	trie* next[26];
	bool isFinish;

	trie() {
		memset(this->next, NULL, sizeof(this->next));
		this->isFinish = false;
	}

	~trie() {
		for (int i = 0; i < 26; ++i)
			if (this->next[i])
				delete this->next[i];
	}

	void insert(string key) {
		trie* pNode = this;
		for (int i = 0; i < key.length(); ++i) {
			int index = key[i] - 'A';
			if (!pNode->next[index])
				pNode->next[index] = new trie();
			pNode = pNode->next[index];
		}
		pNode->isFinish = true;
	}

	void search(int y, int x, string key) {
		// 기저조건 : 문자열은 8글자를 넘지 않음
		if (key.length() > 8)return;
		visited[y][x] = true;
		key += map[y][x];

		trie* pNode = this->next[map[y][x] - 'A'];
		if (pNode == NULL) {
			visited[y][x] = false;
			return;
		}
		if (pNode->isFinish) {
			res.insert(key);
		}

		for (int dir = 0; dir < 8; ++dir) {
			int ny = y + dy[dir], nx = x + dx[dir];
			if (ny < 0 || ny >= 4 || nx < 0 || nx >= 4)continue;
			if (visited[ny][nx])continue;
			pNode->search(ny, nx, key);
		}
		visited[y][x] = false;
	}
};

int main() {

	trie* root = new trie();
	cin >> w;
	for (int i = 0; i < w; ++i) {
		string s;
		cin >> s;
		root->insert(s);
	}
	cin >> b;
	for (int i = 0; i < b; ++i) {
		for (int j = 0; j < 4; ++j) {
			cin >> map[j];
		}
		res.clear();
		for (int y = 0; y < 4; ++y)
			for (int x = 0; x < 4; ++x)
				root->search(y, x, "");

		string longest = "";
		int Max = 0, match = res.size(), scoreSum = 0;
		for (string item : res) {
			if (Max == item.length()) {
				longest = longest < item ? longest : item;
			}
			else if (Max < item.length()) {
				Max = item.length();
				longest = item;
			}
			scoreSum += score[item.length()];
		}
		cout << scoreSum << " " << longest << " " << match << "\n";
	}
	return 0;
}
*/