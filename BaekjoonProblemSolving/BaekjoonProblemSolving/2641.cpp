/*
https://www.acmicpc.net/problem/2641

&Title
2641번 - 다각형그리기

&Question
모눈종이에 다각형을 그리려고 한다. 그리는 방법은 모양수열로 표시된다. 
모양수열은 1과 4사이의 숫자가 연속되어 나열된 것으로 1은 오른쪽으로, 
2는 위쪽으로, 3은 왼쪽으로, 4는 아래쪽으로 한 칸씩 그리는 
것을 말한다. 예를 들어 아래 그림의 다각형 (2)는 점 
A에서 시작하여 화살표 방향으로 모양수열 1411433322를 따라서 그린 것이다. 
다각형 (3)은 점 B에서 시작하여 화살표 방향으로 모양수열 3221411433을 
따라서 그린 것이다. 또한 다각형(4)는 점 C에서 시작하여 화살표 
방향으로 모양수열 4411123323을 따라서 그린 것이다. 다각형 (2), (3), 
(4)는 다각형 (1)과 같으므로 모양수열들 1411433322, 3221411433, 4411123323은 모두 
같은 다각형을 그릴 수 있다. 단, 다각형이 회전된 것이나 
뒤집어진 것은 같은 다각형이 아니다. 그러므로 아래 그림의 다각형 
(5)와 (6)은 다각형 (1)과 다르다. 한 개의 표본 모양수열과 
여러 모양수열들이 주어졌을 때 표본 모양수열과 같은 다각형을 그릴 
수 있는 모양수열들을 모두 찾는 프로그램을 작성하시오. 

&Input
첫째 줄에는 표본 모양수열의 길이(숫자의 개수)가 주어지고, 둘째 
줄에는 표본 모양수열이 주어진다. 셋째 줄에는 모양수열의 개수가 주어지고 
넷째 줄부터는 각 줄에 표본 모양수열과 같은 길이의 모양수열이 
하나씩 주어진다. 단, 모양수열들의 개수는 최대 100 개이고 모양수열의 
길이는 최대 50 이다. 모양수열의 각 숫자 사이에는 빈칸이 
하나 있다. 

&Output
첫째 줄에는 입력된 표본 모양수열과 같은 다각형을 그리는 
모양수열들의 개수를 출력한다. 둘째 줄부터는 각 줄에 표본 모양수열과 
같은 다각형을 그릴 수 있는 모양수열을 출력한다. 출력되는 모양수열의 
숫자들은 한 칸 띄고 출력한다. 

&Example
-input
10
1 4 1 1 4 3 3 3 2 2
3
3 2 2 1 4 1 1 4 3 3
1 4 4 3 3 3 2 1 1 2
4 4 1 1 1 2 3 3 2 3

-output
2
3 2 2 1 4 1 1 4 3 3
4 4 1 1 1 2 3 3 2 3

*/

/*
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;

int main(int argc, char* argv[])
{
	int n;
	int cycle;
	int count = 0;
	string s;
	string ori1 = "";
	string ori2 = "";
	string result[110];

	cin >> n;

	for (int i = 0; i < n; ++i) {
		char c;
		cin >> c;

		ori1 += c;
		ori2 += (c + 1) % 4 + 1 + '0';
	}
	reverse(ori2.begin(), ori2.end());

	cin >> cycle;

	while (cycle--) {
		s = "";
		for (int i = 0; i < n; ++i) {
			char c;
			cin >> c;

			s += c;
		}

		string temp = s;

		for (int i = 0; i < n; ++i) {
			if (temp == ori1 || temp == ori2) {
				result[count] = s;
				++count;
				break;
			}
			temp = temp.substr(1, temp.length()) + temp[0];
		}
	}

	cout << count << endl;

	for (int i = 0; i < count; ++i) {
		for (int j = 0; j < ori1.length(); ++j) {
			cout << result[i][j];
			if (j < ori1.length() - 1) {
				cout << " ";
			}
		}
		cout << endl;
	}

	return 0;
}
*/