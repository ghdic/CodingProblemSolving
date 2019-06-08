/*
https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWqU0zh6rssDFARG&categoryId=AWqU0zh6rssDFARG&categoryType=CODE

7701. 염라대왕의 이름 정렬 D4
※ SW Expert 아카데미의 문제를 무단 복제하는 것을 금지합니다.

염라대왕은 이승의 사람들의 모든 이름을 가지고 있다.

어느날 저승에 일어난 진도 8.0 지진에 항상 정리되어 있던 이승 명부가 흐트러졌다.

이승 명부는 이름의 길이가 짧을수록 이 앞에 있었고, 같은 길이면 사전 순으로 앞에 있었다.

이왕 이렇게 된 김에 모든 이름을 다시 정리하고 같은 이름은 하나만 남겨놓기로 한 염라대왕을 도와주자.

[입력]

첫 번째 줄에 테스트 케이스의 수 T(1 ≤ T ≤ 50)가 주어진다.

각 테스트 케이스의 첫 번째 줄에는 이승 명부의 이름 개수 N(1 ≤ N ≤ 20,000)이 주어진다.

각 테스트 케이스의 두 번째 줄부터 N개의 줄에 걸쳐서 알파벳 소문자로 이루어진 이름들이 주어진다.

이름에는 공백이 포함되지 않으며 최소 1개, 최대 50개의 알파벳으로 이루어져 있다.

[출력]

각 테스트 케이스마다 ‘#x’(x는 테스트케이스 번호를 의미하며 1부터 시작한다)를 출력하고,

정리된 이름을 한 줄에 하나씩 출력하라. 같은 이름은 한 번만 출력해야 하는 것을 주의하라.
입력
2
5
my
name
is
ho
seok
12
s
a
m
s
u
n
g
j
j
a
n
g // 테스트 케이스 개수
// 첫 번째 테스트 케이스, N = 5

// 두 번째 테스트 케이스, N = 12

  s_input.txt
출력
#1
ho
is
my
name
seok
#2
a
g
j
m
n
s
u // 첫 번째 테스트 케이스 결과

// 두 번째 테스트 케이스 결과

  s_output.txt
*/
/*
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <unordered_set>
using namespace std;

bool comparision(const string& s1, const string& s2) {
	return s1 < s2;
}

vector<string> account[50];
int main() {
	int T, N;
	setbuf(stdout, NULL);
	scanf("%d", &T);
	for (int t = 0; t < T; t++) {
		char c[50];
		unordered_set<string> hs[50];
		for (int i = 0; i < 50; i++)
			account[i].clear();
		scanf("%d", &N);
		for (int i = 0; i < N; i++) {
			scanf("%s", c);
			int len = strlen(c);
			if (hs[len].find(c) != hs[len].end()) {	// 중복인 경우 되돌아감
				i--, N--;
			}
			else {
				account[len].push_back(c);
				hs[len].insert(c);
			}
		}

		for(int i = 0; i<50;i++){
			sort(account[i].begin(), account[i].end(), comparision);
		}
		printf("#%d\n", t + 1);
		for (int i = 0; i < 50; i++) {
			for (int j = 0; j < account[i].size(); j++) {	// 출력
				printf("%s\n", account[i][j].c_str());
			}
		}
	}

	return 0;
}
*/

/*
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int test, n;

bool cmp(string a, string b) {
	if (a.size() == b.size()) return a < b;
	return a.size() < b.size();
}

int main() {
	ios::sync_with_stdio(false);

	cin >> test;

	for (int tc = 1; tc <= test; tc++) {
		vector< string > name;
		cin >> n;

		for (int i = 0; i < n; i++) {
			string s;
			cin >> s;
			name.push_back(s);
		}

		sort(name.begin(), name.end(), cmp);

		name.erase(unique(name.begin(), name.end()), name.end());

		cout << "#" << tc << "\n";
		for (auto next : name) {
			cout << next << "\n";
		}
	}
	return 0;
}
*/

/*
&Solution
1. 이름 길이 짧을 수록 앞에
2. 사전 순

sort함수를 이용해 사전순으로 정렬 후 -> 이름 길이 순 정렬하기

ios::sync_with_stdio(false); << 입출력 이거 안했다고 시간 초과남.. 쉣또

길이 별로 저장해서 sort하면 더 빠를수도?
*/