/*
https://www.acmicpc.net/problem/1182

&Title
1182번 - 부분수열의 합

&Question
N개의 정수로 이루어진 수열이 있을 때, 크기가 양수인 
부분수열 중에서 그 수열의 원소를 다 더한 값이 S가 
되는 경우의 수를 구하는 프로그램을 작성하시오. 

&Input
첫째 줄에 정수의 개수를 나타내는 N과 정수 S가 
주어진다. (1 ≤ N ≤ 20, |S| ≤ 1,000,000) 
둘째 줄에 N개의 정수가 빈 칸을 사이에 두고 주어진다. 
주어지는 정수의 절댓값은 100,000을 넘지 않는다. 

&Output
첫째 줄에 합이 S가 되는 부분수열의 개수를 출력한다. 


&Example
-input
5 0
-7 -3 -2 5 8

-output
1


*/

/*
#include <iostream>
using namespace std;

int n, s, arr[20];

int backtracking(int index, int sum) {
	if (index == n) {
		return sum == s ? 1 : 0;
	}
	int res = 0;
	res += backtracking(index + 1, sum + arr[index]);
	res += backtracking(index + 1, sum);
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> s;
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	int res = backtracking(0, 0);
	if (s == 0)--res; // 아무것도 안고르는 경우 0
	cout << res << endl;
	return 0;
}
*/