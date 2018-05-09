/*
https://www.acmicpc.net/problem/2702

&Title
2702번 - 초6 수학

&Question
두 정수 a와 b 최소공배수는 두 수의 공통된 
배수 중 가장 작은 수이고, 최대공약수는 두 수의 공통된 
약수중 가장 큰 수이다. a와 b가 주어졌을 때, 최소공배수와 
최대공약수를 구하는 프로그램을 작성하시오. 

&Input
첫째 줄에 테스트 케이스의 개수 T(1<=T<=1,000)가 주어진다. 각 
테스트 케이스는 두 정수 a와 b로 이루어져 있고, 공백으로 
구분되어 있다. (1 <= a,b <= 1,000) 

&Output
각 테스트 케이스에 대해 최소공배수와 최대공약수를 차례대로 출력한다. 


&Example
-input
3
5 10
7 23
42 56
-output
10 5
161 1
168 14

*/

/*
#include <iostream>
using namespace std;
int GCD(int a, int b) {
	int swap;
	while (b) {
		swap = a % b;
		a = b;
		b = swap;
	}
	return a;
}
int main() {
	int N, a, b;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		int G = GCD(a, b);
		cout << a * b / G << " " << G << endl;
	}
	return 0;
}
*/