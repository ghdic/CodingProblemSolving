/*
https://leetcode.com/problems/permutation-sequence/

&Title
60. Permutation Sequence

&Question
The set [1,2,3,...,n] contains a total of n! uniqu
e permutations.
By listing and labeling all of the permutations in
 order, we get the following sequence for n = 3:
"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence
.
Note:
Given n will be between 1 and 9 inclusive.
Given k will be between 1 and n! inclusive.
Example 1:
Input: n = 3, k = 3
Output: "213"
Example 2:
Input: n = 4, k = 9
Output: "2314"

*/

/*
#include "header.h"

class Solution {
public:
    string getPermutation(int n, int k) {
		string result;
		vector<char> v;
		vector<int> fac;
		fac.push_back(0);
		int fa = 1;
		for (int i = 1; i < n; i++)
			fac.push_back(fa = fa * i);
		for (int i = 1; i <= n; i++) {
			v.push_back(i + '0');
		}
		k--;
		while (k != 0) {
			int div = k / fac[--n];
			k = k % fac[n];
			if (div != 0) {
				result += v[div];
				v.erase(v.begin() + div);
			}
			else {
				result += v[0];
				v.erase(v.begin());
			}
		}

		for (int i = 0; i < v.size(); i++)
			result += v[i];
		return result;
    }
};


int main() {
	cout << Solution().getPermutation(9, 3) << endl;
	return 0;
}

/*
x번째에 어떤숫자가 올지?를 (n-m)!로 k를 나눈 몫을 통해 구한다.
모든 경우의수가 n!이므로 (n-1)! ~ 1! 까지 divide해주면 된다.
erase가 비용이 클줄알았는데 100% 나와서 놀랐다 개꾸르~

*/