/*
https://www.acmicpc.net/problem/11047

&Title
11047번 - 동전 0

&Question
준규가 가지고 있는 동전은 총 N종류이고, 각각의 동전을 
매우 많이 가지고 있다.동전을 적절히 사용해서 그 가치의 합을 
K로 만드려고 한다. 이 때 필요한 동전 개수의 최소값을 
구하는 프로그램을 작성하시오. 

&Input
첫째 줄에 N과 K가 주어진다. (1 ≤ N 
≤ 10, 1 ≤ K ≤ 100,000,000)둘째 줄부터 N개의 
줄에 동전의 가치 Ai가 오름차순으로 주어진다. (1 ≤ Ai 
≤ 1,000,000, A1 = 1, i ≥ 2인 경우에 
Ai는 Ai-1의 배수) 

&Output
첫째 줄에 K원을 만드는데 필요한 동전 개수의 최소값을 
출력한다. 

&Example
-input
10 4200
1
5
10
50
100
500
1000
5000
10000
50000

-output
6

-input
10 4790
1
5
10
50
100
500
1000
5000
10000
50000

-output
12


*/

/*
#include <iostream>
using namespace std;

int main() {
	int N, K, arr[10], cnt = 0;
	cin >> N >> K;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	for (int i = N - 1; i >= 0; i--) {
		if (K/arr[i] != 0) {
			cnt += K / arr[i];
			K = K % arr[i];
		}
	}
	cout << cnt << endl;
	return 0;
}
*/