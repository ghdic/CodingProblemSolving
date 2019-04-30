/*
https://leetcode.com/problems/group-anagrams/

&Title
49. Group Anagrams

&Question
Given an array of strings, group anagrams together
.
Example:
Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
Output:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]
Note:
All inputs will be in lowercase.
The order of your output does not matter.

*/

/*
#include "header.h"

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
		unordered_map<string, vector<string>> dict;
		for (int i = 0; i < strs.size(); i++) {
			string item = strs[i];
			sort(item.begin(), item.end());
			dict[item].push_back(strs[i]);
		}
		vector<vector<string>> result;
		for (pair<string, vector<string>> element : dict)
			result.push_back(element.second);
		return result;
    }
};


int main() {
	vector<string> strs = { "eat","tea","tan","ate","nat","bat" };
	vector<vector<string>> v = Solution().groupAnagrams(strs);
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v[i].size(); j++)
			cout << v[i][j] << " ";
		cout << "\n";
	}
}
*/

/*
&Solution
정렬시 같은 단어들 끼리 묶는 문제이다.
일반적으로는 정렬한것을 키로 해쉬테이블을 사용하는게 기본적인 방법.

좀 더 나아가면 소문자로만 이루어 진다는 것을 이용해
각 단어의 문자 개수를 카운팅하는 해쉬 테이블을 만들면 좀 더 빠르다.



C++
100% 솔루션인데... 잘 이해 못하겠슈.. ㅋㅋ
해쉬 써서 한다는것만? visual studio에선 에러가 나네..
```
class Solution {
	using key = array<uint32_t, 32>;
	struct array_hash {
		size_t operator()(const key& a) const noexcept {
			const auto buffer = reinterpret_cast<const uintmax_t*>(a.data());
			auto h = buffer[0];
			for (size_t index : {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15}) {
				h *= 0x100000001B3ULL; //FNV_64_PRIME
				h = h << 29 | h >> (sizeof(uintmax_t) * 8 - 29);
				h ^= buffer[index];
			}
			static constexpr hash<uintmax_t> hasher{};
			return hasher(h);
		}
	};

public:
	static vector<vector<string>> groupAnagrams(vector<string>& strs) noexcept {
		switch (strs.size()) {
		case 0: return { };
		case 1: return { move(strs) };
		default:
			unordered_map<key, vector<string>, array_hash> map(strs.size());
			for (auto& s : strs) {
				key count{};
				for (char ch : s) ++count[ch - 'a'];
				map[count].emplace_back(move(s));
			}
			vector<vector<string>> result;
			result.reserve(map.size());
			for (auto& [_, value] : map)
				result.emplace_back(move(value));
			return result;
		}
	}
};

static const auto _ = []() __attribute__((always_inline)) noexcept { ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0; }();

```
*/