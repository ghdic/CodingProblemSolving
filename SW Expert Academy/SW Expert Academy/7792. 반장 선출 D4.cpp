/*
https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWsBNHuqMMADFARG&categoryId=AWsBNHuqMMADFARG&categoryType=CODE

7792. 반장 선출 D4
※ SW Expert 아카데미의 문제를 무단 복제하는 것을 금지합니다.


이 시대의 진정한 리더가 되기를 원하는 학생들이 리더 스쿨에 모였다.

리더스쿨의 3학년 5반은 리더를 선출하기로 했다.

3학년 5반은 총 N명이며 모두 이름이 다르다.

리더 스쿨의 가르침에 따르면, 리더쉽이 가장 뛰어난 사람은 이름만 봐도 알 수 있다고 한다.

이름에 사용된 알파벳의 종류가 많을수록 다양한 사람을 존중하고 이해할 수 있다는 교훈에 따라서 반장은 이름에 쓰인 알파벳 종류의 개수가 가장 많은 사람으로 결정된다.

만약 그런 사람이 여럿이라면 그 중에 사전 순으로 가장 앞선 사람이 반장이 된다.

N명의 학생들의 이름이 주어졌을 때, 3학년 5반의 반장을 구하여라.


[입력]

첫 번째 줄에 테스트 케이스의 수 T(1 ≤ T ≤ 100)가 주어진다.

각 테스트 케이스의 첫 번째 줄에는 학생 수 N(1 ≤ N ≤ 100)이 주어진다.

이름은 대문자 알파벳과 ‘ ’(space)로 이루어져 있다.

이름의 시작과 끝은 항상 알파벳이며 최대 20글자이다.

이름은 최소 한 개의 알파벳은 포함한다.


[출력]

각 테스트 케이스마다 ‘#x’(x는 테스트케이스 번호를 의미하며 1부터 시작한다)를 출력하고,

반장의 이름을 한 줄에 출력한다.
 
입력
2
3
BBIBBI
DEAD BEEF
ABCDDCBA
2
ABC
AAAA BBBB CCCC
// 테스트 케이스 개수
// 첫 번째 테스트 케이스, N = 3

 

// 두 번째 테스트 케이스, N = 2

  input.txt
출력
#1 DEAD BEEF
#2 AAAA BBBB CCCC // 첫 번째 테스트 케이스 결과
// 두 번째 테스트 케이스 결과
output.txt
*/

/*
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main() {
	int T;
	
	setbuf(stdout, NULL);
	ios::sync_with_stdio(false);
	cin >> T;
	for (int t = 1; t <= T; t++) {
		vector<string> v[21];	// 종류의 개수에 따른 문자열을 담는 벡터 문자열 최대길이가 20개이므로 21
		string s;
		int N, m;
		cin >> N;
		cin.ignore(100, '\n');	// getline할때 이거 안해주면 처음버퍼로 '\n'을 먹음
		while (N--) {
			bool check[26] = {};	// 중복된 문자 확인
			int count = 0;
			getline(cin, s);
			for (int i = 0; i < s.size(); i++) {	// 문자 종류 counting
				if (s[i] != ' ') {
					if (!check[s[i] - 'A']) {
						check[s[i] - 'A'] = true;
						count++;
					}
				}
			}
			v[count].push_back(s);	// 해당 문자 종류 개수에 맞게 넣어줌
		}
		for (int i = 0; i < 21; i++) {
			if (!v[i].empty())m = i;
		}
		sort(v[m].begin(), v[m].end());	// 가장 종류가 높은 것을 사전순으로 정렬함
		cout << "#" << t << " " << v[m][0] << "\n";
	}
	return 0;
}
*/