// https://www.algospot.com/judge/problem/read/JAEHASAFE

/*
#include <iostream>
#include <vector>
#include <string>
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


vector<int> kmpSearch(const string& a, const string& b) {
	int aSz = a.size(), bSz = b.size();
	vector<int> ret;
	vector<int> pi = getPartialMatch(b);
	// 현재 대응된 글자 수
	int matched = 0;
	// 짚더미의 각 글자를 순회한다.
	for (int i = 0; i < aSz; ++i) {
		// matched번 글자와 짚더미의 해당 글자가 불일치 할 경우,
		// 현재 대응된 글자 수의 pi[matched-1]을 줄인다.
		while (matched > 0 && a[i] != b[matched])
			matched = pi[matched - 1];
		// 글자가 대응될 경우
		if (a[i] == b[matched]) {
			++matched;
			if (matched == bSz) {
				ret.push_back(i - bSz + 1);
				matched = pi[matched - 1];
			}
		}
	}
	return ret;
}

// 두 문자열을 이어 붙이면 원하는 목표를 찾을 수 있다
// 그럼 찾은 위치만큼 shift를 해주면 된다
// 시계방향, 반시계방향을 결정하는것은 original, target를 반대로 넣어주면 된다.
int shifts(const string& original, const string& target) {
	return kmpSearch(original + original, target)[0];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		vector<string> strs(n + 1);
		int res = 0;
		for (int i = 0; i <= n; ++i)
			cin >> strs[i];
		for (int i = 0; i < n; ++i) {
			if (i & 1)
				res += shifts(strs[i], strs[i + 1]); // 반시계
			else
				res += shifts(strs[i + 1], strs[i]); // 시계
		}
		cout << res << "\n";
	}
	return 0;
}
*/