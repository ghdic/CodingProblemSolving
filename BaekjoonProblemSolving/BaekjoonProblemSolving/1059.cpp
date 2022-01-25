/*
https://www.acmicpc.net/problem/1059

&Title
	1059번 - 좋은 구간

&Question
정수 집합 S가 주어졌을때, 다음 조건을 만족하는 구간 
[A, B]를 좋은 구간이라고 한다.A와 B는 양의 정수이고, A 
< B를 만족한다.A ≤ x ≤ B를 만족하는 모든 
정수 x가 집합 S에 속하지 않는다.집합 S와 n이 주어졌을 
때, n을 포함하는 좋은 구간의 개수를 구해보자. 

&Input
첫째 줄에 집합 S의 크기 L이 주어진다. 둘째 
줄에는 집합에 포함된 정수가 주어진다. 셋째 줄에는 n이 주어진다. 


&Output
첫째 줄에 n을 포함하는 좋은 구간의 개수를 출력한다. 


&Example
-input
4
1 7 14 10
2

-output
4

-input
5
4 8 13 24 30
10

-output
5

-input
5
10 20 30 40 50
30

-output
0

-input
8
3 7 12 18 25 100 33 1000
59

-output
1065


*/

/*
#include <iostream>
#include <algorithm>
using namespace std;

int L, S[51], n, index = -1;

int brute_force(int start, int end, int target) {
	if (start == end)
		return 0;
	
	int res = end - target + 1;
	if (start == target)
		res -= 1;

	if (start + 1 <= target && target <= end)
		res += brute_force(start + 1, end, target);

	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin >> L;
	S[0] = 0;
	for (int i = 1; i <= L; i++) {
		cin >> S[i];
	}
	cin >> n;

	

	sort(S, S + L + 1);

	for (int i = 0; i < L; i++) {
		if (S[i] < n && n < S[i + 1]) {
			index = i;
			break;
		}
	}

	if (index == -1) {
		cout << 0 << endl;
	}
	else {
		cout << brute_force(S[index] + 1, S[index + 1] - 1, n) << endl;
	}


	return 0;
}
*/