// https://www.algospot.com/judge/problem/read/HABIT

/*
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// 각 접미사들의 첫 t글자를 기준으로 한 그룹 번호가 주어질때,
// 주어진 두 접미사를 첫 2*t글자를 기준으로 비교한다
// group[]은 길이가 0인 접미사도 포함한다.
struct Comparator {
	const vector<int>& group;
	int t;
	Comparator(const vector<int>& _group, int _t) :group(_group), t(_t) {};
	bool operator () (int a, int b) {
		// 첫 t글자가 다르면 이들을 이용해 비교한다.
		if (group[a] != group[b])return group[a] < group[b];
		// 아니라면 S[a+t]와 S[b+t]의 첫 t글자를 비교한다.
		return group[a + t] < group[b + t];
	}
};

// s의 접미사 배열을 계산한다.
vector<int> getSuffixArray(const string& s) {
	int n = s.size();
	// group[i]=접미사들을 첫 t글자를 기준으로 정렬했을 때,
	// S[i..]가 들어가는 그룹 번호
	// t=1일 때는 정렬할 것 없이 S[i..]의 첫 글자로 그룹 번호를
	// 정해줘도 같은 효과가 있다.
	int t = 1;
	vector<int> group(n + 1);
	for (int i = 0; i < n; ++i)group[i] = s[i];
	group[n] = -1;
	// 결과적으로 접미사 배열이 될 반환 값. 이 배열을 lg(n)번 정렬한다
	vector<int> perm(n);
	for (int i = 0; i < n; ++i)perm[i] = i;
	while (t < n) {
		// group[]은 첫 t글자를 기준으로 계산해 뒀다.
		// 첫 2t글자를 기준으로 perm을 다시 정렬한다.
		Comparator compareUsing2T(group, t);
		sort(perm.begin(), perm.end(), compareUsing2T);
		// 2t글자가 n을 넘는다면 이제 접미사 배열 완성
		t *= 2;
		if (t >= n)break;
		// 2t글자를 기준으로 한 그룹 정보를 만든다
		vector<int> newGroup(n + 1);
		newGroup[n] = -1;
		newGroup[perm[0]] = 0;
		for (int i = 1; i < n; ++i)
			if (compareUsing2T(perm[i - 1], perm[i]))
				newGroup[perm[i]] = newGroup[perm[i - 1]] + 1;
			else
				newGroup[perm[i]] = newGroup[perm[i - 1]];
		group = newGroup;
	}
	return perm;
}

// s[i..]와 s[j..]의 공통 접두사의 최대 길이를 계산한다.
int commonPrefix(const string& s, int i, int j) {
	int k = 0;
	while (i < s.size() && j < s.size() && s[i] == s[j]) {
		++i, ++j, ++k;
	}
	return k;
}

// k번 이상 출현하는 s의 부분 문자열 중 최대 길이를 찾는다.
int longestFrequent(int k, const string& s) {
	vector<int> a = getSuffixArray(s);
	int ret = 0;
	for (int i = 0; i + k <= s.size(); ++i)
		ret = max(ret, commonPrefix(s, a[i], a[i + k - 1]));
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t, k;
	string s;
	cin >> t;
	while (t--) {
		cin >> k;
		cin >> s;
		cout << longestFrequent(k, s) << "\n";
	}
	return 0;
}
*/