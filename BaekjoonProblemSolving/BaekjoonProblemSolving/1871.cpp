/*
https://www.acmicpc.net/problem/1871

&Title
1871번 - 좋은 자동차 번호판

&Question
앨버타의 자동차 번호판은 ABC-0123 (세 글자, 네 숫자)와 
같이 두 부분으로 나누어져 있다.좋은 번호판은 첫 번째 부분의 
가치와 두 번째 부분의 가치의 차이가 100을 넘지 않는 
번호판이다.글자로 이루어진 첫 번째 부분의 가치는 글자를 26진법 숫자처럼 
계산하다. (각 자리가 [A..Z]) 예를 들어, "ABC"의 가치는 28 
(0*26^2 + 1*26^1 + 2*26^0)이 된다. "ABC-0123"은 |28 - 
123| <= 100 이기 때문에, 좋은 번호판이다.자동차 번호판이 주어졌을 
때, 좋은 번호판인지 아닌지를 구하는 프로그램을 작성하시오. 

&Input
첫째 줄에 번호판의 수 N (1 ≤ N 
≤ 100)이 주어진다. 다음 N개 줄에는 자동차 번호판이 LLL-DDDD 
형식으로 주어진다. 

&Output
각각의 자동차 번호판에 대해서, 좋은 번호판이면 "nice"를, 아니면 
"not nice"를 출력한다. 

&Example
-input
2
ABC-0123
AAA-9999

-output
nice
not nice


*/

/*
#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int main() {
	int N;
	string s;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int a = 0, b = 0;
		cin >> s;
		for (int j = 0; j < 8; j++) {
			if (j < 3)a += (s[j] - 'A')*pow(26, 2 - j);
			else if (j > 3)b += (s[j] - '0')*pow(10, 7 - j);
		}
		if (abs(a - b) <= 100)cout << "nice" << endl;
		else cout << "not nice" << endl;
	}
	return 0;
}
*/