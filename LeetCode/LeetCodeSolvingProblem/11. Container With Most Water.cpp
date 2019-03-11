/*
https://leetcode.com/problems/container-with-most-water/

&Title
11. Container With Most Water

&Question
Given n non-negative integers a1, a2, ..., an , wh
ere each represents a point at coordinate (i, ai).
 n vertical lines are drawn such that the two endp
oints of line i is at (i, ai) and (i, 0). Find two
 lines, which together with x-axis forms a contain
er, such that the container contains the most wate
r.
Note: You may not slant the container and n is at 
least 2.
  The above vertical lines are represented by arra
y [1,8,6,2,5,4,8,3,7]. In this case, the max area 
of water (blue section) the container can contain 
is 49.
  Example:
Input: [1,8,6,2,5,4,8,3,7]
Output: 49

*/

/*
#include "header.h"

class Solution {
public:
    int maxArea(vector<int>& height) {
		vector<pair<int, int> > l, r;
		int lpivot = 0, rpivot = height.size() - 1, lmax = height[lpivot], rmax = height[rpivot];
		l.push_back(make_pair(lpivot, lmax));
		for (int i = lpivot + 1; i < height.size(); i++) {
			if (height[i] > lmax) {
				lpivot = i;
				lmax = height[i];
				l.push_back(make_pair(lpivot, lmax));
			}
		}
		r.push_back(make_pair(rpivot, rmax));
		for (int i = rpivot - 1; i >= 0; i--) {
			if (height[i] > rmax) {
				rpivot = i;
				rmax = height[i];
				r.push_back(make_pair(rpivot, rmax));
			}
		}

		int best = 0;
		for (vector<pair<int, int> >::iterator i = l.begin(); i != l.end(); ++i) {
			for (vector<pair<int, int> >::iterator j = r.begin(); j != r.end(); ++j) {
				int gap = get<0>(*j) - get<0>(*i);
				if (gap <= 0)break;
				int high = get<1>(*j) < get<1>(*i) ? get<1>(*j) : get<1>(*i);
				if (gap*high > best) {
					best = gap * high;
				}
			}
		}
		return best;
    }
};

int main() {
	vector<int> height = { 1, 8, 6, 2, 5, 4, 8, 3, 7 };
	cout << Solution().maxArea(height) << endl;
	return 0;
}
*/

/*
Solution
접근법 1 : Brute Forece
Java
```
public class Solution {
	public int maxArea(int[] height) {
		int maxarea = 0;
		for (int i = 0; i < height.length; i++)
			for (int j = i + 1; j < height.length; j++)
				maxarea = Math.max(maxarea, Math.min(height[i], height[j]) * (j - i));
		return maxarea;
```
시간복잡도 : O(n^2)

접근법 2 : Two Pointer Approach
항상 짧은 선에 높이가 제한 된다는 점, 선들이 멀수록 더 많은 면적이 얻어 진다는 것을 유의한다.
선들이 가까워질수록 높이의 제한이 높아지는 경우만 구하면됨
(내가푼 방식인데... 첨에 이렇게 똑같이 하려 했는데 왼쪽증가,
오른쪽감소에 대한 조건에 대한 자신감이 없었음..ㅋㅋ)

Java
```
public class Solution{
	public int maxArea(int[] height) {
		int maxarea = 0, i = 0, r = height.length - 1;
		while(l < r) {
			maxarea = Math.max(maxarea, Math.min(height[i], height[r]) * (r-1));
			if(height[i] < height[r])
				i++;
			else
				r--;
		}
		return maxarea;
	}
}
```
시간복잡도 : O(n)
*/