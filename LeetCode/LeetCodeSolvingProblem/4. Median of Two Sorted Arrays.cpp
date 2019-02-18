/*
https://leetcode.com/problems/median-of-two-sorted-arrays/

&Title
4. Median of Two Sorted Arrays

&Question
There are two sorted arrays nums1 and nums2 of siz
e m and n respectively.
Find the median of the two sorted arrays. The over
all run time complexity should be O(log (m+n)).
You may assume nums1 and nums2 cannot be both empt
y.
Example 1:
nums1 = [1, 3]
nums2 = [2]

The median is 2.0
Example 2:
nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5

*/

#include "header.h"
class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int m = nums1.size();
		int n = nums2.size();
		if (m > n) {
			nums1.swap(nums2);
			swap(m, n);
		}
		int iMin = 0, iMax = m, halfLen = (m + n + 1) / 2;
		while (iMin <= iMax) {
			int partitionX = (iMin + iMax) / 2;
			int partitionY = halfLen - partitionX;
			if (i < iMax && nums2[partitionY - 1] > nums1[partitionX]) {
				iMin = partitionX + 1;
			}
			else if (partitionX > iMin && nums1[partitionX - 1] > nums2[partitionY]) {
				iMax = partitionX - 1;
			}
			else {
				int maxLeft = 0;
				if (partitionX == 0) { maxLeft = nums2[partitionY - 1]; }
				else if (partitionY == 0) { maxLeft = nums1[partitionX - 1]; }
				else { maxLeft = max(nums1[partitionX - 1], nums2[partitionY - 1]); }
				if ((m + n) % 2 == 1) { return maxLeft; }

				int minRight = 0;
				if (partitionX == m) { minRight = nums2[partitionY]; }
				else if (partitionY == n) { minRight = nums1[partitionX]; }
				else { minRight = min(nums2[partitionY], nums1[partitionX]); }

				return (maxLeft + minRight) / 2.0;
			}
		}
		return 0.0;
	}
};

int main() {
	vector<int> nums1 = { 1, 3 }, num2 = { 2 };
	Solution sol;
	double z = sol.findMedianSortedArrays(nums1, num2);
	cout << z << endl;
}

/*
#include "header.h"


// 그냥 합쳐서 sort해서 풀었뜸
class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		vector<int> nums3;
		nums3.insert(nums3.end(), nums1.begin(), nums1.end());
		nums3.insert(nums3.end(), nums2.begin(), nums2.end());
		sort(nums3.begin(), nums3.end());
		int length = nums3.size();
		if (length % 2 == 0)
			return (nums3[length / 2 - 1] + nums3[length / 2]) / 2.0;
		else
			return nums3[length / 2];

	}
};

int main() {
	vector<int> nums1 = { 1, 3 }, num2 = { 2 };
	Solution sol;
	double z = sol.findMedianSortedArrays(nums1, num2);
	cout << z << endl;
}
*/

/*
Solution

Python 
접근법 : 재귀적 접근
중앙값에 대해 이해해야 한다. 중앙값의 하나의 특징은 한 집합을
두개의 각기 다른 집합으로 나눈다는 것이다. 작은 요소들의 집합과 큰 요소들의 집합으로 말이다.

각 배열들은 작은 요소들의 집합에 속해있는 요소들이거나 큰 요소들의 집합에
속해있는 요소들을 동시에 가지고 있다.

		left_part		|		right_part 
A[0], A[1], ..., A[i-1] | A[i], A[i+1], ..., A[m-1] 
B[0], B[1], ..., B[j-1] | B[j], B[j+1], ..., B[n-1]


left_part는 작은 요소들의 집합이고 right_part는 큰 요소들의 집합이다.
이 성질을 이용하여 다음과 같이 가정할 수 있다.

1. len(left_part) = len(right_part) //이렇게 되도록 유도하는 것이다.
2. max(left_part) <= min(right_part) //이거

left_part의 크기가 right_part의 크기가 같다. 이것은 자명하다.
두 번째 공식은 명백한대, 왜냐하면 언제나 left_part들의 요소는 right_part의 요소보다 작기 때문이다.

이걸 더 세세한 공식으로 쓰면 다음과 같다.

1. i+j = m-i+n-j 
(if n>=m, i=0~m, j=(m+n+1)/2 - i로 설정한다.)
2. B[j-1]<=A[i] and A[i-1] <= B[j]

이것은
[0,m] 영역에서
B[j-1] <= A[i] and A[i-1] <=B[j], where j = (m+n+1)/2 - i
이 성립함을 의미한다.

```
def median(A, B):
	m, n = len(A), len(B)
	if m > n:
		A, B, m, n = B, A, n, m; #이거 되네...?
	if n == 0:
		raise ValueError

	imin, imax, half_len = 0, m, (m + n + 1) / 2
	while imin <= imax:
		i = (imin + imax) / 2
		j = half_len - i
		if i < m and B[j-1] > A[i]:
			# i is too small, must increase it
			imin = i + 1
		elif i > 0 and A[i-1] > B[j]:
			# i is too big, must decrease it
			imax = i - 1
		else:
			# i is perfect
			if i == 0: max_of_left = B[j-1]
			elif j == 0: max_of_left = A[i-1]
			else: max_of_left = max(A[i-1], B[j-1])

			if (m + n) % 2 == 1:
				return max_of_left

			if i == m: min_of_right = B[j]
			elif j == n: min_of_right = A[i]
			else: min_of_right = min(A[i], B[j])

			return (max_of_left + min_of_right) / 2.0
```

이해가 안가서 영상보고 설명추가
https://www.youtube.com/watch?v=LPFhl65R7ww

1. 크기가 더 작은걸 X, 더 큰걸 Y 배열로 설정한다.
2. start = 0(iMin), end = m(iMax), partitionX = (start+end)/2, partitionY = (m+n+1)/2 - partitionX 으로 값 설정
3. A1 | A2
   B1 | B2
   에서 A1 < A2가 성립하지 않으면 start = partitionX + 1 로 설정하고 루프
   B1 < B2가 성립하지 않으면 end = partitionX - 1 로 설정하고 루프
4. 만약 두개의 array 중 나눠진 파티션에 원소가 없는 경우 해당 파티션은 -INF or INF 원소가 있는걸로 가정한다.
5. 3번이 만족될때, 두 배열의 원소수합이 짝수인 경우 avg(max(A1, B1), min(A2, B2))이고, 홀수인 경우 max(A1,B1)이다.
```
class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int m = nums1.size();
		int n = nums2.size();
		if (m > n) {
			nums1.swap(nums2);
			swap(m, n);
		}
		int iMin = 0, iMax = m, halfLen = (m + n + 1) / 2;
		while (iMin <= iMax) {
			int partitionX = (iMin + iMax) / 2;
			int partitionY = halfLen - partitionX;
			if (i < iMax && nums2[partitionY - 1] > nums1[partitionX]) {
				iMin = partitionX + 1;
			}
			else if (partitionX > iMin && nums1[partitionX - 1] > nums2[partitionY]) {
				iMax = partitionX - 1;
			}
			else {
				int maxLeft = 0;
				if (partitionX == 0) { maxLeft = nums2[partitionY - 1]; }
				else if (partitionY == 0) { maxLeft = nums1[partitionX - 1]; }
				else { maxLeft = max(nums1[partitionX - 1], nums2[partitionY - 1]); }
				if ((m + n) % 2 == 1) { return maxLeft; }

				int minRight = 0;
				if (partitionX == m) { minRight = nums2[partitionY]; }
				else if (partitionY == n) { minRight = nums1[partitionX]; }
				else { minRight = min(nums2[partitionY], nums1[partitionX]); }

				return (maxLeft + minRight) / 2.0;
			}
		}
		return 0.0;
	}
};
```

*/