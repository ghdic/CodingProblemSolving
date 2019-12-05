/*
https://www.acmicpc.net/problem/2104

&Title
2104번 - 부분배열 고르기

&Question
크기가 N(1≤N≤100,000)인 1차원 배열 A[1], …, A[N]이 있다. 
어떤 i, j(1≤i≤j≤N)에 대한 점수는, (A[i]+…+A[j])×Min{A[i], …, A[j]}가 된다. 
즉, i부터 j까지의 합에다가 i부터 j까지의 최솟값을 곱한 것이 
점수가 된다.배열이 주어졌을 때, 최대의 점수를 갖는 부분배열을 골라내는 
프로그램을 작성하시오. 

&Input
첫째 줄에 정수 N이 주어진다. 다음 줄에는 A[1], 
…, A[N]을 나타내는 정수들이 주어진다. 각각의 정수들은 음이 아닌 
값을 가지며, 1,000,000을 넘지 않는다. 

&Output
첫째 줄에 최대 점수를 출력한다. 

&Example
-input
6
3 1 6 4 5 2

-output
60


*/

/*
#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[1000001];

long long getMax(int from, int to) {
	if (from == to)return (long long)arr[from] * arr[to];

	int mid = (from + to) / 2;
	long long maxValue = max(getMax(from, mid), getMax(mid + 1, to));

	int left = mid;
	int right = mid + 1;

	long long sum = (long long)arr[left] + arr[right];
	long long minValue = min(arr[left], arr[right]);
	maxValue = max(maxValue, sum * minValue);

	while (left > from || right < to) {
		if (right < to && (left == from || arr[left - 1] < arr[right + 1])) {
			sum += arr[++right];
			minValue = min(minValue, (long long)arr[right]);
		}
		else {
			sum += arr[--left];
			minValue = min(minValue, (long long)arr[left]);
		}
		maxValue = max(maxValue, sum * minValue);
	}
	return maxValue;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> arr[i];
	cout << getMax(1, n);
	return 0;
}
*/