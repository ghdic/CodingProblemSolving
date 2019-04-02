/*
https://leetcode.com/problems/next-permutation/

&Title
31. Next Permutation

&Question
Implement next permutation, which rearranges numbe
rs into the lexicographically next greater permuta
tion of numbers.
If such arrangement is not possible, it must rearr
ange it as the lowest possible order (ie, sorted i
n ascending order).
The replacement must be in-place and use only cons
tant extra memory.
Here are some examples. Inputs are in the left-han
d column and its corresponding outputs are in the 
right-hand column.
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1

*/

/*
#include "header.h"

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
		int n = nums.size(), k, l;
		for (k = n - 2; k >= 0; k--) {
			if (nums[k] < nums[k + 1])break;
		}
		if (k < 0)
			reverse(nums.begin(), nums.end());
		else {
			for (l = n - 1; l > k; l--)
				if (nums[l] > nums[k])break;
			//k와 바꿀 위치인거 찾음
			swap(nums[k], nums[l]);
			//k뒤에꺼 reverse로 재정렬
			reverse(nums.begin() + k + 1, nums.end());
		}
    }
};


int main() {
	vector<int> nums = { 1, 3, 2 };
	Solution().nextPermutation(nums);
	for (int i = 0; i < nums.size(); i++) {
		cout << nums[i] << " ";
	}
	return 0;
}
*/
/*
&Solution
사전 순으로 다음에 올 집합을 내뱉는 함수를 만드는게 목표이다.

1.탐색 범위 만큼 두개씩 비교
이때 오른쪽 값이 왼쪽보다 큰 경우 교환하고 끝
2.한 단계 위의 수와 이전의 수들과 교환할게 있는지 비교
3.탐색 범위 비교가 끝났는데 교환 안할 경우 탐색범위를 늘림
4.늘리기 전에 탐색 범위가 n일 경우 정렬된 값 반환

이렇게 생각했었는데..

그냥 값이 reverse된 경우 ex){ 3, 2, 1 }
가 핵심이다.
위치를 바꿀 두 수를 조건에 따라 찾고
바꾼후 k뒤에 값들을 reverse해주는게 핵심
*/