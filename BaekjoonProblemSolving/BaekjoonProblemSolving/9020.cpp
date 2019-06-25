/*
https://www.acmicpc.net/problem/9020

&Title
9020번 - 골드바흐의 추측

&Question
1보다 큰 자연수 중에서 1과 자기 자신을 제외한 
약수가 없는 자연수를 소수라고 한다. 예를 들어, 5는 1과 
5를 제외한 약수가 없기 때문에 소수이다. 하지만, 6은 6 
= 2 × 3 이기 때문에 소수가 아니다.골드바흐의 추측은 
유명한 정수론의 미해결 문제로, 2보다 큰 모든 짝수는 두 
소수의 합으로 나타낼 수 있다는 것이다. 이러한 수를 골드바흐 
수라고 한다. 또, 짝수를 두 소수의 합으로 나타내는 표현을 
그 수의 골드바흐 파티션이라고 한다. 예를 들면, 4 = 
2 + 2, 6 = 3 + 3, 8 
= 3 + 5, 10 = 5 + 5, 
12 = 5 + 7, 14 = 3 + 
11, 14 = 7 + 7이다. 10000보다 작거나 같은 
모든 짝수 n에 대한 골드바흐 파티션은 존재한다.2보다 큰 짝수 
n이 주어졌을 때, n의 골드바흐 파티션을 출력하는 프로그램을 작성하시오. 
만약 가능한 n의 골드바흐 파티션이 여러 가지인 경우에는 두 
소수의 차이가 가장 작은 것을 출력한다. 

&Input
첫째 줄에 테스트 케이스의 개수 T가 주어진다. 각 
테스트 케이스는 한 줄로 이루어져 있고 짝수 n이 주어진다. 
(4 ≤ n ≤ 10,000) 

&Output
각 테스트 케이스에 대해서 주어진 n의 골드바흐 파티션을 
출력한다. 출력하는 소수는 작은 것부터 먼저 출력하며, 공백으로 구분한다. 


&Example
-input
3
8
10
16

-output
3 5
5 5
5 11


*/
/*
#include <iostream>
using namespace std;

int arr[10001] = { 0, -1 };
int prime[10001] = { 0 };
int main() {
	int T;
	ios::sync_with_stdio(false);
	for (int i = 2; i <= 10000; i++) {
		if (arr[i] != -1) {
			for (int j = 2; i * j <= 10000; j++)
				arr[i * j] = -1;
		}
	}
	int cnt = 0;
	for (int i = 2; i <= 10000; i++) {
		if (arr[i] == 0)prime[cnt++] = i;
	}
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		int a = 0, b = 10001, val = 0;
		while(val < cnt)
			if (prime[val++] > N)break;
		for (int i = 0; i < val; i++) {
			for (int j = i; j < val; j++) {
				if (prime[i] + prime[j] == N) {
					if(b-a > prime[j] - prime[i])
						a = prime[i], b = prime[j];
				}
			}
		}
		cout << a << " " << b << "\n";
	}
	return 0;
}
*/

/*
무식하면 컴퓨터가 고생한다는 말이 있다하오...

c++
```
#include <cstdio>

int arr[10001] = {0, 1};
int main() {
	int T;
	scanf("%d", &T);
	for (int i = 2; i <= 10000; i++)
		if (arr[i] != 1) {
			for (int j = i + i; j <= 10000; j += i)
				arr[j] = 1;
		}
	while (T--) {
		int N;
		scanf("%d", &N);
		int left = N / 2, right = N / 2;
		while (true) {
			if (arr[left] == 0 && arr[right] == 0)break;
			left--, right++;
		}
		// 소수끼리 더하는 이중문으로 하는게 최선이라 생각했었는데..
		// N/2기준으로 left--, right++ 일때 두 소수의 합인걸 찾으면 최선인것이 나옴
		// 갭이 가장 적다는걸 구하라는걸.. N/2에서부터 찾는다는 생각을...
		// 소수의 합을 찾는 다는 점에서 이 부분을 놓쳐버렸다.
		printf("%d %d\n", left, right);
	}
}
*/
