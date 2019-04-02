/*
https://leetcode.com/problems/substring-with-concatenation-of-all-words/

&Title
30. Substring with Concatenation of All Words

&Question
You are given a string, s, and a list of words, wo
rds, that are all of the same length. Find all sta
rting indices of substring(s) in s that is a conca
tenation of each word in words exactly once and wi
thout any intervening characters.
Example 1:
Input:
  s = "barfoothefoobarman",
  words = ["foo","bar"]
Output: [0,9]
Explanation: Substrings starting at index 0 and 9 
are "barfoor" and "foobar" respectively.
The output order does not matter, returning [9,0] 
is fine too.
Example 2:
Input:
  s = "wordgoodgoodgoodbestword",
  words = ["word","good","best","word"]
Output: []

*/

/*
#include "header.h"

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
		vector<int> ans;
		int n = s.size(), cnt = words.size();
		if (n <= 0 || cnt <= 0) return ans;

		unordered_map<string, int> dict;
		for (int i = 0; i < cnt; ++i)dict[words[i]]++;

		int wl = words[0].size();
		//단어 길이 만큼의 루프
		for (int i = 0; i < wl; ++i) {
			int left = i, count = 0;
			unordered_map<string, int> tdict;
			//i부터 단어길이 단위로 s길이까지 루프
			for (int j = i; j <= n - wl; j += wl) {
				string str = s.substr(j, wl);

				// dict안에 일치하는 키가 있는 경우 1반환 없을 경우 0 반환하는 함수
				// 딱히 어떤게 몇개가 일치하는지 반환하지는 않는듯..
				// 즉 앞부분을 substr한게 dict안에 있는지 확인함
				if (dict.count(str)) {
					// 초기화가 자동으로 0으로 되나봄..?
					tdict[str]++;
					if (tdict[str] <= dict[str])
						count++;
					else {
						while (tdict[str] > dict[str]) {
							//시작한 가장 왼쪽으로 부터 일치했던걸 전진시켜서 카운트를 줄인다.
							string str1 = s.substr(left, wl);
							tdict[str1]--;
							if (tdict[str1] < dict[str1])count--;
							left += wl;
						}
					}

					//결과 도출
					if (count == cnt) {
						ans.push_back(left);
						// 하나의 단어만큼 전진시킨다
						tdict[s.substr(left, wl)]--;
						count--;
						left += wl;
					}
				}
				// 유효한 단어가 아닌 경우 값 초기화
				else {
					tdict.clear();
					count = 0;
					left = j + wl;
				}
			}
		}
		return ans;
    }
};


int main() {
	string s = "barfoothefoobarman";
	vector<string> words = { "foo", "bar" };
	vector<int> result;
	result = Solution().findSubstring(s, words);
	for (int i = 0; i < result.size(); i++)
		cout << result[i] << " ";
	return 0;
}
*/

/*
&Solution
Substring들이 연속된 조합으로 한번씩 사용된 곳의 위치를
반환하는게 목표이다.

먼저 생각해본건
1. Substring 하나하나 다 비교 해봄(Brute Force)
2. Substring의 조합의 모든 경우의 수에 대한 벡터를 만든다.(단점은 초기 비교군이 많아진다.)
3. KMP알고리즘으로 각 Substring의 위치를 담은 벡터를 생성후, 해당 벡터로 해답을 찾기
- 이미 한번 사용된것에 대한 처리는 복사한 벡터에서
사용한걸 제외하는 식인게 가장 쉽지만 비효율적일거같다..

!단어의 길이가 모두 같다는건 s의길이는 단어의길이의 배수가 되는거아닌가?
n개 단위로 끊어서 검사하면??

※남의 소스 보고 풀 경우 어떻게 할까...?
1. 먼저 소스를 그대로 따라 쳐본다.
2. 소스를 분석하며 주석을 단다.
3. 디버깅을 해본다.
4. 안보고 다시 짜본다
*/