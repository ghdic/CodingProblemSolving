/*
https://www.acmicpc.net/problem/8464

&Title
8464번 - Non-Squarefree Numbers

&Question
A positive integer k is called squarefree if 
k is not divisible by d2 for any d 
> 1. 

&Input
The input contains one integer n, 1 ≤ 
n ≤ 1010. 

&Output
Your program should output one integer, the n-th 
non-squarefree number. 

&Example
-input
10

-output
27


*/

/*
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 1e6;
const long long MAX = 4e10;

long long n;
long long arr[MAXN];

int main() {
	ios::sync_with_stdio(false);
	fill(&arr[0], &arr[MAXN], 1);
	cin >> n;

	for(int i = 2; i*i< MAXN; ++i)
		if (arr[i] == 1) {
			for (int j = i; j < MAXN; j += i)
				arr[j] *= -i;
			for (int j = i * i; j < MAXN; j += i * i)
				arr[j] = 0;
		}

	for (int i = 2; i < MAXN; ++i) {
		if (arr[i] == i)arr[i] = 1;
		else if (arr[i] == -i)arr[i] = -1;
		else if (arr[i] < 0)arr[i] = 1;
		else if (arr[i] > 0)arr[i] = -1;
	}

	long long left = 1, right = MAX;
	while (left <= right) {
		long long mid = (right + left) / 2;
		long long sum = 0;
		for (int i = 1; (long long)i * i <= mid; ++i)
			sum += ((mid / i) / i) * arr[i];
		sum = mid - sum;
		if (sum < n)
			left = mid + 1;
		else
			right = mid - 1;
	}
	cout << left << endl;
	return 0;
}
*/