/*
https://www.acmicpc.net/problem/1456

&Title
1456번 - 거의 소수

&Question
어떤 수가 소수의 N제곱(N ≥ 2) 꼴일 때, 
그 수를 거의 소수라고 한다.A와 B가 주어지면, A보다 크거나 
같고, B보다 작거나 같은 거의 소수가 몇 개인지 출력한다. 


&Input
첫째 줄에 왼쪽 범위 A와 오른쪽 범위 B가 
공백 한 칸을 사이에 두고 주어진다. A의 범위는 10^14보다 
작거나 같은 자연수이고, B는 A보다 크거나 같고, 10^14보다 작거나 
같은 자연수이다. 

&Output
첫째 줄에 총 몇 개가 있는지 출력한다. 

&Example
-input
1 1000

-output
25


*/

/*
#include <iostream>
#include <cmath>
using namespace std;

const int MAXN = 1e7;
const long long MAX = 1e12;
bool arr[MAXN + 1];
long long A, B;

int main() {
	ios::sync_with_stdio(false);
	cin >> A >> B;
	arr[0] = arr[1] = true;
	for (int i = 2; i <= MAXN; ++i) {
		if (!arr[i]) {
			for (int j = i + i; j <= MAXN; j += i)
				arr[j] = true;
		}
	}
	int a = sqrt(A), b = sqrt(B);
	int res = 0;
	for (int i = 1; i <= b; ++i) {
		if (!arr[i]) {
			long long num = i;
			while (i <= B / num) {
				if (i * num >= A)
					++res;
				num *= i;
			}
		}
	}
	cout << res << endl;
	return 0;
}
*/