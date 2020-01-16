/*
https://www.acmicpc.net/problem/1016

&Title
1016번 - 제곱 ㄴㄴ 수

&Question
어떤 수 X가 1보다 큰 제곱수로 나누어 떨어지지 
않을 때, 제곱ㄴㄴ수라고 한다. 제곱수는 정수의 제곱이다. min과 max가 
주어지면, min과 max를 포함한 사이에 제곱ㄴㄴ수가 몇 개 있는지 
출력한다. 

&Input
첫째 줄에 min과 max가 주어진다. min은 1보다 크거나 
같고, 1,000,000,000,000보다 작거나 같은 자연수이고, max는 min보다 크거나 같고, 
min+1,000,000보다 작거나 같은 자연수이다. 

&Output
첫째 줄에 [min,max]구간에 제곱ㄴㄴ수가 몇 개인지 출력한다. 

&Example
-input
1 10
-output
7

*/

/*
#include <iostream>
using namespace std;

long long Min, Max;
bool check[1000001];

int main() {
	ios::sync_with_stdio(false);
	cin >> Min >> Max;
	for (long long i = 2; i * i <= Max; ++i) {
		long long quotient = Min / (i * i) + (Min % (i * i) == 0 ? 0 : 1);

		while (quotient * (i * i) <= Max) {
			check[quotient * (i * i) - Min] = true;
			++quotient;
		}
	}
	int cnt = 0;
	for (int i = 0; i <= Max - Min; ++i)
		if (!check[i])++cnt;

	cout << cnt << endl;
	return 0;
}
*/