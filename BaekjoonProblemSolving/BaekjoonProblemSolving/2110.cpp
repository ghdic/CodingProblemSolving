/*
https://www.acmicpc.net/problem/2110

&Title
2110번 - 공유기 설치

&Question
도현이의 집 N개가 수직선 위에 있다. 각각의 집의 
좌표는 x1, ..., xN이고, 집 여러개가 같은 좌표를 가지는 
일은 없다.도현이는 언제 어디서나 와이파이를 즐기기 위해서 집에 공유기 
C개를 설치하려고 한다. 최대한 많은 곳에서 와이파이를 사용하려고 하기 
때문에, 한 집에는 공유기를 하나만 설치할 수 있고, 가장 
인접한 두 공유기 사이의 거리를 가능한 크게 하여 설치하려고 
한다.C개의 공유기를 N개의 집에 적당히 설치해서, 가장 인접한 두 
공유기 사이의 거리를 최대로 하는 프로그램을 작성하시오. 

&Input
첫째 줄에 집의 개수 N (2 ≤ N 
≤ 200,000)과 공유기의 개수 C (2 ≤ C ≤ 
N)이 하나 이상의 빈 칸을 사이에 두고 주어진다. 둘째 
줄부터 N개의 줄에는 집의 좌표를 나타내는 xi (1 ≤ 
xi ≤ 1,000,000,000)가 한 줄에 하나씩 주어진다. 

&Output
첫째 줄에 가장 인접한 두 공유기 사이의 최대 
거리를 출력한다. 

&Example
-input
5 3
1
2
8
4
9

-output
3


*/

/*
#include <iostream>
#include <algorithm>
using namespace std;

int N, C; // 2 ~ 200,000, 2~N
int arr[200001]; // 1 ~ 1,000,000,000

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> C;
	for (int i = 0; i < N; ++i)
		cin >> arr[i];
	sort(arr, arr + N);
	
	int left = 1; // 가능한 최소 거리
	int right = arr[N - 1] - arr[0]; // 가능한 최대 거리
	int d = 0;
	int answer = 0;

	// 이진탐색으로 시간복잡도를 logN으로 줄인다.
	// 1. 특정 간격을 기준으로 가능한 위치에 공유기를 설치한다.
	// 2. 공유기 수가 더 설치되어야 한다면, 간격을 줄인다.
	// 3. 공유기 수를 줄여야한다면, 간격을 늘린다.

	while (left <= right) {
		int mid = (left + right) / 2;
		int start = arr[0];
		int cnt = 1;

		// 간격(d)를 기준으로 공유기 설치
		for (int i = 1; i < N; ++i) {
			d = arr[i] - start;
			if (mid <= d) { // mid간격으로 공유기를 설치함을 알 수 있음
				++cnt;
				start = arr[i];
			}
		}

		if (cnt >= C) {
			// 공유기의 수를 줄이자 -> 간격 넓히기
			answer = mid;
			left = mid + 1;
		}
		else {
			// 공유기가 더 설치되어야한다 -> 간격을 좁히기
			right = mid - 1;
		}
	}
	cout << answer << endl;
	return 0;
}
*/