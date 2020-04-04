// https://www.algospot.com/judge/problem/read/BRACKETS2

/*
#include <iostream>
#include <stack>
#include <algorithm>
#include <string>
using namespace std;

bool wellMatched(const string& formula) {
	// 여는 괄호 문자들과 닫는 괄호 문자들
	const string opening = "({[", closing = ")}]";
	// 이미 열린 괄호들을 순서대로 담는 스택
	stack<char> openStack;
	for (int i = 0; i < formula.size(); ++i) {
		// 여는 괄호인지 닫는 괄호인지 확인
		if (opening.find(formula[i]) != -1) {
			// 여는 괄호라면 무조건 스택에 집어넣는다
			openStack.push(formula[i]);
		}
		else {
			// 이 외의 경우 스택 맨위의 문자와 맞춰본다
			// 스택이 비어 있는 경우에는
			// 아직 못만난 짝이 있음에도 빈거니 짝이 안맞는것이다
			if (openStack.empty())return false;
			// 서로 짝이 맞지 않아도 실패
			// find함수가 npos를 return하는데 찾은게 몇번째 위치인지 돌려주는것이다
			// 즉 opening, closing에서 각 npos가 같은 경우 일치하는 짝인것이다.
			// find가 못찾을 경우(-1)인 경우는 이미 로직에서 처리되었기 때문에 고려할 필요 없다.
			if (opening.find(openStack.top()) != closing.find(formula[i]))
				return false;
			// 짝을 맞춘 괄호는 스택에서 뺀다.
			openStack.pop();
		}
	}
	// 닫히지 않는 괄호가 없어야 성공
	return openStack.empty();
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		cout << (wellMatched(s) ? "YES\n" : "NO\n");
	}
	return 0;
}
*/