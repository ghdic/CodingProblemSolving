/*
https://www.acmicpc.net/problem/1850

&Title
1850번 - 최대공약수

&Question
모든 자리가 1로만 이루어져있는 두 자연수 A와 B가 
주어진다. 이때, A와 B의 최대 공약수를 구하는 프로그램을 작성하시오.예를 
들어, A가 111이고, B가 1111인 경우에 A와 B의 최대공약수는 
1이고, A가 111이고, B가 111111인 경우에는 최대공약수가 111이다. 

&Input
첫째 줄에 두 자연수 A와 B를 이루는 1의 
개수가 주어진다. 입력되는 수는 263보다 작은 자연수이다. 

&Output
첫째 줄에 A와 B의 최대공약수를 출력한다. 정답은 천만 
자리를 넘지 않는다. 

&Example
-input
3 4

-output
1

-input
3 6

-output
111

-input
500000000000000000 500000000000000002

-output
11


*/

/*
#include <iostream>
#include <string>
using namespace std;

long long gcd(long long A, long long B) {
	if (B == 0)return A;
	return gcd(B, A % B);
}
int main() {
	long long A, B; // 1~2^63
	ios::sync_with_stdio(false);
	cin >> A >> B;
	string s = "";
	long long range = gcd(A, B);
	while (range--)s += '1';
	cout << s << endl;
	return 0;
}
*/