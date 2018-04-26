/*
https://www.acmicpc.net/problem/10987

&Title
10987번 - 모음의 개수

&Question
알파벳 소문자로만 이루어진 단어가 주어진다. 이 때, 모음(a, 
e, i, o, u)의 개수를 출력하는 프로그램을 작성하시오. 

&Input
첫째 줄에 단어가 주어진다. 단어의 길이는 1보다 크거나 
같고, 100보다 작거나 같으며, 알파벳 소문자로만 이루어져 있다. 

&Output
첫째 줄에 모음의 개수를 출력한다. 

&Example
-input
baekjoon

-output
4


*/

/*
#include <iostream>
#include <string>
using namespace std;

int main() {
	string N;
	int cnt = 0;
	cin >> N;
	for (int i = 0; i < N.size(); i++) {
		if (N[i] == 'a' || N[i] == 'e' || N[i] == 'i' || N[i] == 'o' || N[i] == 'u')
			cnt++;
	}
	cout << cnt << endl;
	return 0;
}
*/