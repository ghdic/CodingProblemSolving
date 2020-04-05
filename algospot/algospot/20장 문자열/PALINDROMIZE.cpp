// https://www.algospot.com/judge/problem/read/PALINDROMIZE

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

// a의 접미사이면서 b의 접두사인 문자열의 최대 길이를 구한다.
int maxOverlap(const string& a, const string& b) {
	int n = a.size(), m = b.size();
	vector<int> pi = getPartialMatch(b);
	// begin = matched = 0 에서 부터 시작하자
	int begin = 0, matched = 0;
	while (begin < n) {
		// 만약 짚더미의 해당 글자가 바늘의 해당 글자와 같다면
		if (matched < m && a[begin + matched] == b[matched]) {
			++matched;
			if (begin + matched == n)
				return matched;
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
	return 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		string a, b;
		cin >> a;
		b.resize(a.size());
		reverse_copy(a.begin(), a.end(), b.begin());
		int res = a.length() * 2 - maxOverlap(a, b);
		cout << res << "\n";
	}
}
*/