/*
https://leetcode.com/problems/two-sum/

&Title
1. Two Sum

&Question
Given an array of integers, return indices of the 
two numbers such that they add up to a specific ta
rget.
You may assume that each input would have exactly 
one solution, and you may not use the same element
 twice.
Example:
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
 

*/

/*
#include "header.h"


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
		vector<int>::iterator i, j;

		for (i = nums.begin(); i != nums.end(); ++i) {
			for (j = i; j != nums.end(); ++j) {
				if (i == j)continue;
				if ((*i + *j) == target) {
					return { distance(nums.begin(), i), distance(nums.begin(), j) };
				}
			}
		}
		return nums;
    }
};


int main() {
	vector<int> nums = { 2, 7, 11, 15 };
	int target = 26;
	cout << Solution().twoSum(nums, target)[0] << " " << Solution().twoSum(nums, target)[1] << endl;
	return 0;
}
*/

/*


Solution

Java Code
접근법 1 : Brute Force
target - x와 다른 값을 비교하여 반복문을 통해 값을 찾는다.

```
public int[] twoSum(int[] nums, int target) {
	for (int i = 0; i < nums.length; i++){
		for (int j = i + 1; j < nums.length; j++) {
			if (nums[j] == target - nums[i]) {
				return new int[] { i, j };
			}
		}
	}
	throw new IllegalArgumentException("No two sum solution");
}
```

시간복잡도 : O(n^2)


접근법 2 : Two-pass Hash Table
해쉬 테이블에 값을 키로, 인덱스를 값으로 매핑하여 요소에 더 빠르게 접근한다.
target - nums[i] 한 값을 빠르게 서치함으로써 시간복잡도를 줄인다.(해시테이블은 서치 시간복잡도가 O(1)이다.)

```
public int[] twoSum(int[] nums, int target){
	Map<Integer, Integer> map = new HashMap<>();
	for (int i =0; i < nums.length; i++){
		map.put(nums[i], i);
	}
	for(int i = 0; i < nums.length; i++){
		int complement = target - nums[i];
		if (map.containsKey(complement) && map.get(complement) != i) {
			return new int[] { i, map.get(complement) };
		}
	}
	throw new IllgalArgumentException("No two sum solution");
}

```

시간복잡도 : O(n)


접근법 3: One-pass Hash Table
해쉬테이블에 값을 삽입하는 과정을 한번의 루프 안에 집어 넣음, 접근법 2를 조금 개선
containsKey함수로 검사할때 map의 크기자체는 이전것보다 작지만 HashMap이므로
map의 크기와 상관없이 찾는 속도는 같음, 맨앞 원소와 맨 뒤 원소의 합이 target일 경우가 최악의 경우가 될 것
for문하나로 구현했다는 것에 의의

```
public int[] twoSum(int[] nums, int target){
	Map<Integer, Integer> map = new HashMap<>();
	for (int i = 0; i < nums.length; i++){
		int complement = target - nums[i];
		if (map.containsKey(complement)){
			return new int[]{ map.get(complement), i };
		}
		map.put(nums[i], i);
	}
	throw new IllegalArugmentException("No two sum solution");
}

```

시간복잡도 : O(n)

*/