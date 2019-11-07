/*
https://www.acmicpc.net/problem/2037

&Title
2037번 - 문자메시지

&Question
오른쪽 그림과 같은 핸드폰 자판이 있다. 이 자판을 
이용하여 어떤 영어 메시지를 치려고 할 때, 걸리는 최소 
시간을 구하는 프로그램을 작성하시오.단, 1번은 누를 경우에는 공백이 찍힌다고 
하자. 그리고 만약에 AC라는 문자를 치려 한다면 A를 치고 
난 후 일정 시간을 기다린 후 C를 치면 된다.하나의 
문자를 입력하려면, 버튼을 눌러야 한다. 버튼을 누르면 버튼에 쓰여 
있는 문자가 입력되며, 버튼을 누를 때 마다 다음 문자로 
바뀌게 된다. 예를 들어, 2를 누르면 A, 2번 누르면 
B, 3번 누르면 C이다. 공백을 연속으로 누를 때는 기다릴 
필요가 없다. 

&Input
첫째 줄에 p와 w가 주어진다. (1 ≤ p, 
w ≤ 1,000) p는 버튼을 한번 누르는데 걸리는 시간이고, 
w는 AC와 같은, 같은 숫자인 문자를 연속으로 찍기 위해 
기다리는 시간을 의미한다. 그리고 둘째 줄에는 적을 문자열이 주어진다. 
단, 이 문자열의 길이는 1000보다 작고, 맨 앞과 맨 
뒤에 공백이 들어오는 경우는 없다고 가정하여도 좋다. 문자열은 알파벳 
대문자와 띄어쓰기만으로 이루어져 있다. 

&Output
첫째 줄에 메시지를 적는데 걸리는 시간을 출력한다. 

&Example
-input
2 10
ABBAS SALAM
-output
72

*/

/*
#include <iostream>
#include <string>
using namespace std;

int p, w; // 버튼 누르는 시간, 연속으로 찍기 위해 기다리는 시간
string s;
int map[91];

int main() {
	ios::sync_with_stdio(false);
	int idx = 'A';
	for (int i = 2; i <= 9; ++i)
		for (int j = 1; j <= 3; ++j)
			map[idx++] = j;
	map[idx++] = 4;
	map[' '] = 1;

	cin >> p >> w;
	cin.ignore();
	getline(cin, s);
	int prev = 0;
	int sum = 0;
	for (int i = 0; i < s.length(); ++i) {
		if (s[i] == ' ') {
			sum += p;
			prev = 1;
		}
		else {
			int add = 0;
			for (int j = 0; j <= 7; ++j) {
				int item = 'A' + 3 * j + add;
				if (j == 5 || j == 7) {
					if (s[i] >= item && s[i] <= item + 3) {
						sum += (s[i] - item + 1) * p + (prev == j + 2 ? w : 0);
						prev = j + 2;
						
					}
					++add;
				}
				else {
					if (s[i] >= item && s[i] <= item + 2) {
						sum += (s[i] - item + 1) * p + (prev == j + 2 ? w : 0);
						prev = j + 2;
					}
				}
			}
		}
	}
	cout << sum << endl;
	return 0;
}
*/