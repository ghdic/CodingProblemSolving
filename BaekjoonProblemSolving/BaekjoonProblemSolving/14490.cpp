/*
https://www.acmicpc.net/problem/14490

&Title
14490번 - 백대열

&Question
대열이는 욱제의 친구다.“야 백대열을 약분하면 뭔지 알아?”“??”“십대일이야~ 하하!”n:m이 
주어진다. 욱제를 도와주자. (...) 

&Input
n과 m이 :을 사이에 두고 주어진다. (1 <= 
n, m <= 100,000,000) 

&Output
두 수를 최대한으로 약분하여 출력한다. 

&Example
-input
100:10

-output
10:1

-input
18:24

-output
3:4


*/

/*
#include <iostream>
#include <string>
using namespace std;

int gcd(int a, int b) {
	if (b == 0)return a;
	return gcd(b, a % b);
}
int main() {
	int n, m;
	string s;
	cin >> s;
	int pos = 0;
	while (s[pos] != ':')++pos;
	n = stoi(s.substr(0, pos));
	m = stoi(s.substr(pos + 1, s.length() - pos - 1));
	int div = gcd(n, m);
	cout << n / div << ":" << m / div << endl;
	return 0;
}
*/