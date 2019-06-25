/*
https://www.acmicpc.net/problem/2312

&Title
2312번 - 수 복원하기

&Question
양의 정수 N이 주어졌을 때, 이 수를 소인수분해 
한 결과를 출력하는 프로그램을 작성하시오. 

&Input
첫째 줄에 테스트 케이스의 수가 주어진다. 각 테스트 
케이스마다 양의 정수 N (2 ≤ N ≤ 100,000)이 
주어진다. 

&Output
각 테스트 케이스마다 각 인수와 그 인수가 곱해진 
횟수를 한 줄씩 출력한다. 출력 순서는 인수가 증가하는 순으로 
한다. 

&Example
-input
2
6
24

-output
2 1
3 1
2 3
3 1


*/

/*
#include <iostream>
using namespace std;
int arr[100001] = { 0, 1 };
int prime[9592] = {};
int main() {
	int T;
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;
	int cnt = 0;
	for (int i = 2; i <= 100000; i++) {
		if (arr[i]) continue;
		prime[cnt++] = i;
		for (int j = i << 1; j <= 100000; j += i)
			arr[j] = 1;
	}
	
	while (T--) {
		int N;
		cin >> N;
		for(int i = 0; N!=1; i++){
			if (N % prime[i] == 0) {
				int count = 0;
				while (N % prime[i] == 0) {
					++count;
					N /= prime[i];
				}
				cout << prime[i] << " " << count << "\n";
			}
		}
	}
	return 0;
}
*/