/*
https://leetcode.com/problems/combinations/

&Title
77. Combinations

&Question
Given two integers n and k, return all possible co
mbinations of k numbers out of 1 ... n.
Example:
Input: n = 4, k = 2
Output:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]

*/

/*
#include "header.h"

class Solution {
public:
	vector<vector<int>> result;
    vector<vector<int>> combine(int n, int k) {
		vector<int> comb;
		combiner(0, n, k, comb);
		return result;
    }

	void combiner(int j, int &n, int k, vector<int>& comb) {
		if (k == 0) {
			result.push_back(comb);
			return;
		}
		for (int i = j+1; i <= n; i++) {
			comb.push_back(i);
			combiner(i, n, k - 1, comb);
			comb.pop_back();
		}
	}
};

int main() {
	int n = 4, k = 3;
	vector<vector<int>> result = Solution().combine(n, k);
	for (int i = 0; i < result.size(); i++) {
		for (int j = 0; j < result[i].size(); j++) {
			cout << result[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
*/

/*
&Solution
난 그냥 재귀로 쉽게 풀었다.


c++
재귀로 이루어진 과정을 좀더 깔쌈하게 재귀 안쓰고 한듯.
최소한의 정렬상태로 시작하여 맨끝을 1씩 더해감
최종끝까지 왔으면 그 전 수를 하나 증가시키고 그 전수 값의 +1씩 만큼 그 뒤에것들을 증가시킴
이렇게 끝날때까지 반복함
```
class Solution {
public:
	vector<vector<int>> combine(int n, int k) {
		vector<vector<int>> ans;
		if (k > n)
				return ans;

		vector<int> v(k, 0);
		for (int iii = 0; iii < k; iii++)
				v[iii] = iii + 1;
		ans.push_back(v);

		while (1) {
				bool finish = true;
				for (int iii = 0; iii < v.size(); iii++) {
						if (v[iii] != n - k + iii + 1) {
								finish = false;
								break;
						}
				}
				if (finish) {
						return ans;
				}

				for (int iii = v.size() - 1; iii >= 0; iii--) {
						if (v[iii] != n - k + iii + 1) {
								v[iii]++;
								for (int jjj = iii + 1; jjj < v.size(); jjj++) {
										v[jjj] = v[jjj - 1] + 1;
								}
								ans.push_back(v);
								break;
						}
				}

		}
	}
};
```


*/