/*
https://www.acmicpc.net/problem/2920

&Title
2920번 - 음계

&Question
다장조는 c d e f g a b 
C, 총 8개 음으로 이루어져있다. 이 문제에서 8개 음은 
다음과 같이 숫자로 바꾸어 표현한다. c는 1로, d는 2로, 
..., C를 8로 바꾼다.1부터 8까지 차례대로 연주한다면 ascending, 8부터 
1까지 차례대로 연주한다면 descending, 둘 다 아니라면 mixed 이다.연주한 
순서가 주어졌을 때, 이것이 ascending인지, descending인지, 아니면 mixed인지 판별하는 
프로그램을 작성하시오. 

&Input
첫째 줄에 8개 숫자가 주어진다. 이 숫자는 문제 
설명에서 설명한 음이며, 1부터 8까지 숫자가 한 번씩 등장한다. 


&Output
첫째 줄에 ascending, descending, mixed 중 하나를 출력한다. 


&Example
-input
1 2 3 4 5 6 7 8

-output
ascending

-input
8 7 6 5 4 3 2 1

-output
descending

-input
8 1 7 2 6 3 5 4

-output
mixed


*/

/*
#include <iostream>
using namespace std;

int main() {
	int arr[8], up = 0, down = 0;
	for (int i = 0; i < 8; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < 7; i++) {
		if (arr[i] < arr[i + 1])up++;
		else if (arr[i] > arr[i + 1])down++;
	}

	if (up&&down) {
		cout << "mixed" << endl;
	}
	else if (up) {
		cout << "ascending" << endl;
	}
	else if (down) {
		cout << "descending" << endl;
	}
	return 0;
}
*/