// https://www.algospot.com/judge/problem/read/NAMING
/*
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// n에서 자기 자신을 찾으면서 나타나는 부분 일치를 이용해
// pi[]를 계산한다
// pi[i]=n[..i]의 접미사도 되고 접두사도 되는 문자열의 최대 길이
vector<int> getPartialMatch(const string& s) {
	int m = s.size();
	vector<int> pi(m, 0);
	// kmp로 자기 자신을 찾는다
	int begin = 1, matched = 0;
	// 비교할 문자가 s의 끝에 도달할때까지 찾으면서 부분 일치를 모두 기록한다
	while (begin + matched < m) {
		if (s[begin + matched] == s[matched]) {
			++matched;
			pi[begin + matched - 1] = matched;
		}
		else {
			if (matched == 0)
				++begin;
			else {
				begin += matched - pi[matched - 1];
				matched = pi[matched - 1];
			}
		}
	}
	return pi;
}

vector<int> getPrefixSuffix(const string& s) {
	vector<int> ret, pi = getPartialMatch(s);
	int k = s.size();
	while (k > 0) {
		ret.push_back(k);
		k = pi[k - 1];
	}
	return ret;
}

int main() {
	string a, b;
	cin >> a;
	cin >> b;
	a += b;
	vector<int> res = getPrefixSuffix(a);
	reverse(res.begin(), res.end());
	for (int n : res)
		cout << n << " ";
	return 0;
}
*/