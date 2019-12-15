/*
https://www.acmicpc.net/problem/1300

&Title
1300번 - K번째 수

&Question
세준이는 N*N크기의 배열을 만들었다. (배열의 방 번호는 1부터 
시작한다.)그 배열을 A라고 했을 때, 배열에 들어가는 수는 A[i][j] 
= i*j 이다.세준이는 이 수를 일차원 배열 B에 넣으려고 
한다. 그렇게 되면, B의 크기는 N*N이 될 것이다. 그러고 
난 후에, B를 오름차순 정렬해서 k번째 원소를 구하려고 한다.N이 
주어졌을 때, k번째 원소를 구하는 프로그램을 작성하시오. 

&Input
첫째 줄에 배열의 크기 N이 주어진다. N은 105보다 
작거나 같은 자연수이다. 둘째 줄에 k가 주어진다. k는 min(109, 
n2)보다 작거나 같은 자연수이다. 

&Output
k번째 원소를 출력한다. 

&Example
-input
3
7

-output
6


*/

/*
1 2 3 4 5 6
2 4 6 8 10 12
3 6 9 12 15 18
4 8 12 16 20 24
5 10 15 20 25 30
6 12 18 24 30 36

mid = 4 left = 2 right = 3
k = 6 1~6 4/1 4/2 4/3 /4/4 1 1 2 4
1 2 2 3 3 4 4 4 /5 5 6 6 6 6 8 8 9 10 / 10 12 12 12 12 15 15 16/ 18 18 20 20 24 24 25 30 30 36
*/

/*
#include <iostream>
#include <algorithm>
using namespace std;
int n, k;

int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	cin >> k;

	int l = 1, r = k;

	while (l <= r) {
		long long int cnt = 0;
		int mid = (l + r) / 2;
		for (int i = 1; i <= n; ++i)
			cnt += min(mid / i, n);
		if (cnt < k)l = mid + 1;
		else r = mid - 1;
	}

	cout << l << endl;
	return 0;
}
*/