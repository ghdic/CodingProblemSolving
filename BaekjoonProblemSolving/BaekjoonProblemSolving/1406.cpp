/*
https://www.acmicpc.net/problem/1406

&Title
1406번 - 에디터

&Question
한 줄로 된 간단한 에디터를 구현하려고 한다. 이 
편집기는 영어 소문자만을 기록할 수 있는 편집기로, 최대 600,000글자까지 
입력할 수 있다.이 편집기에는 '커서'라는 것이 있는데, 커서는 문장의 
맨 앞(첫 번째 문자의 왼쪽), 문장의 맨 뒤(마지막 문자의 
오른쪽), 또는 문장 중간 임의의 곳(모든 연속된 두 문자 
사이)에 위치할 수 있다. 즉 길이가 L인 문자열이 현재 
편집기에 입력되어 있으면, 커서가 위치할 수 있는 곳은 L+1가지 
경우가 있다.이 편집기가 지원하는 명령어는 다음과 같다.L커서를 왼쪽으로 한 
칸 옮김 (커서가 문장의 맨 앞이면 무시됨)D커서를 오른쪽으로 한 
칸 옮김 (커서가 문장의 맨 뒤이면 무시됨)B커서 왼쪽에 있는 
문자를 삭제함 (커서가 문장의 맨 앞이면 무시됨) 삭제로 인해 
커서는 한 칸 왼쪽으로 이동한 것처럼 나타나지만, 실제로 커서의 
오른쪽에 있던 문자는 그대로임P \$\$라는 문자를 커서 왼쪽에 추가함초기에 
편집기에 입력되어 있는 문자열이 주어지고, 그 이후 입력한 명령어가 
차례로 주어졌을 때, 모든 명령어를 수행하고 난 후 편집기에 
입력되어 있는 문자열을 구하는 프로그램을 작성하시오. 단, 명령어가 수행되기 
전에 커서는 문장의 맨 뒤에 위치하고 있다고 한다. 

&Input
첫째 줄에는 초기에 편집기에 입력되어 있는 문자열이 주어진다. 
이 문자열은 영어 소문자로만 이루어져 있으며, 길이는 100,000을 넘지 
않는다. 둘째 줄에는 입력할 명령어의 개수를 나타내는 정수 N(1≤N≤500,000)이 
주어진다. 셋째 줄부터 N개의 줄에 걸쳐 입력할 명령어가 순서대로 
주어진다. 명령어는 위의 네 가지 중 하나의 형태로만 주어진다. 


&Output
첫째 줄에 모든 명령어를 수행하고 난 후 편집기에 
입력되어 있는 문자열을 출력한다. 

&Example
-input
abcd
3
P x
L
P y

-output
abcdyx

-input
abc
9
L
L
L
L
L
P x
L
B
P y

-output
yxabc

-input
dmih
11
B
B
P x
L
B
B
B
P y
D
D
P z

-output
yxz


*/

/*
#include <iostream>
#include <string>
#include <list>
using namespace std;

string s;
int n;
char c, h;
int main() {
	int N;
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> s;
	cin >> n;
	list<char> editor(s.begin(), s.end());
	auto cursor = editor.end();
	while (n--) {
		cin >> c;
		switch (c)
		{
		case 'L': // 커서 왼쪽으로 한칸
			if (cursor != editor.begin())--cursor;
			break;
		case 'D': // 커서 오른쪽으로 한칸
			if (cursor != editor.end())++cursor;
			break;
		case 'B': // 커서 왼쪽에 있는 문자 삭제
			if (cursor != editor.begin()) {
				auto del = --cursor;
				++cursor;
				editor.erase(del);
			}
			break;
		case 'P': // $이라는 문자를 커서 왼쪽에 추가함
			cin >> h;
			editor.insert(cursor, h);
			break;
		default:
			break;
		}
	}
	for (char c : editor)cout << c;
	return 0;
}
*/

/*
// 스택 이용한 풀이
// 두 스택을 이용하여 커서 위치 기준으로 행위를 하는것
#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main() {
	int n;
	string s; //초기 입력 문자열

	cin >> s; //abcd
	cin >> n;
	stack<char> s1, s2;
	//stack<char> s1(s.begin(),s.end());
	for (auto& x : s) {
		s1.push(x);
	}
	// s1.end() 커서의 위치  
	while (n--) {// 명령의 수 만큼 반복 
		char cmd;
		cin >> cmd; //명령어 입력 

		if (cmd == 'L') {
			if (!(s1.empty())) {
				//s1에 든게 없다 == 커서가 가장 왼쪽이다  
				s2.push(s1.top());
				s1.pop();
			}

		}
		else if (cmd == 'D') {
			if (!s2.empty()) {
				// s2에 든게 없다 == 커서가 가장 오른쪽이다  
				s1.push(s2.top());
				s2.pop();
			}
		}
		else if (cmd == 'B') {
			if (!(s1.empty())) {
				s1.pop();
			}

		}
		else if (cmd == 'P') {
			char x;
			cin >> x;
			s1.push(x);
		}
	}
	// 처음부터 순서대로 출력하기 위해 s1 스택에서 s2 스택으로 옮긴다. 
	while (!(s1.empty())) {
		s2.push(s1.top());
		s1.pop();
	}
	// s1에서 추가된 맨 위에서부터 출력하고 출력된 후에 스택에서 삭제  
	while (!(s2.empty())) {
		cout << s2.top();
		s2.pop();
	}
	return 0;
}
*/