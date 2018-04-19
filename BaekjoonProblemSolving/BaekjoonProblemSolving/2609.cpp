/*
https://www.acmicpc.net/problem/2609

&Title
최대공약수와 최소공배수
&Question
두 개의 자연수를 입력받아 최대 공약수와 최소 공배수를 출력하는 프로그램을 작성하시오.
&Input
첫째 줄에는 두 개의 자연수가 주어진다. 이 둘은 10,000이하의 자연수이며 사이에 한 칸의 공백이 주어진다.
&Output
첫째 줄에는 입력으로 주어진 두 수의 최대공약수를,둘째 줄에는 입력으로 주어진 두 수의 최소 공배수를 출력한다.
&Example
-input
24 18
-output
6
72
*/

/*
#include <iostream>
using namespace std;

int gcd(int a, int b) {
	if (b == 0)
		return a;
	else
		return gcd(b, a%b);
}

int main() {
	int A, B, G;
	cin >> A >> B;
	G = gcd(A, B);
	cout << G << endl;
	cout << A * B / G << endl;
	return 0;
}
*/