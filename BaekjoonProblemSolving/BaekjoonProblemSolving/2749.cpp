/*
https://www.acmicpc.net/problem/2749

&Title
2749번 - 피보나치 수 3

&Question
피보나치 수는 0과 1로 시작한다. 0번째 피보나치 수는 
0이고, 1번째 피보나치 수는 1이다. 그 다음 2번째 부터는 
바로 앞 두 피보나치 수의 합이 된다. 이를 식으로 
써보면 Fn = Fn-1 + Fn-2 (n>=2)가 된다. n=17일때 
까지 피보나치 수를 써보면 다음과 같다. 0, 1, 1, 
2, 3, 5, 8, 13, 21, 34, 55, 89, 
144, 233, 377, 610, 987, 1597 n이 주어졌을 때, 
n번째 피보나치 수를 구하는 프로그램을 작성하시오. 

&Input
첫째 줄에 n이 주어진다. n은 1,000,000,000,000,000,000보다 작거나 같은 
자연수이다. 

&Output
첫째 줄에 n번째 피보나치 수를 1,000,000으로 나눈 나머지를 
출력한다. 

&Example
-input
1000
-output
228875

*/

/*
#include <iostream>
using namespace std;
const int mod = 1000000;
const int p = mod / 10 * 15;	//10^6 으로 나누므로 주기는 15*10^5
int fibo[p] = { 0,1 };
int main() {
	long long n;
	cin >> n;
	for (int i = 2; i<p; i++) {
		fibo[i] = fibo[i - 1] + fibo[i - 2];
		fibo[i] %= mod;	//10^6 넘을 경우를 나머지 반환
	}
	cout << fibo[n%p] << '\n';	//
	return 0;
}
*/