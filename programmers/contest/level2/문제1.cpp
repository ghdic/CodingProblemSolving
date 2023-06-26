#include <iostream>
#include <string>
#include <stack>
using namespace std;
/*
int solution(string s)
{
	stack<char> compare;
	compare.push(s[0]);
	for (int i = 1; i < s.size(); i++)
	{
		if (!compare.empty() && compare.top() == s[i]) {
			compare.pop();
		}
		else
			compare.push(s[i]);
	}
	return compare.empty();
}

int main() {
	cout << solution("baabaa") << endl;
	return 0;
}
*/