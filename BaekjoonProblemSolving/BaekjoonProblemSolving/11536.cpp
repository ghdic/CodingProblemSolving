/*
https://www.acmicpc.net/problem/11536

&Title
11536번 - 줄 세우기

&Question
악독한 코치 주혁은 선수들을 이름 순으로 세우는 것을 
좋아한다. 더 악독한 것은 어떤 순서로 서야할지도 알려주지 않았다! 
선수들의 이름이 주어질 때 어떤 순서로 이루어져있는지 확인해보자. 

&Input
첫째 줄에 N개의 이름이 주어진다. (2 ≤ N 
≤ 20)다음 N개의 줄에는 각 선수들의 이름이 주어진다. 이름은 
2 이상 12 이하의 대문자로만 이루어져있다. 선수의 이름은 중복되지 
않는다. 

&Output
이름이 증가하는 순으로 나타나면 INCREASING, 감소하는 순이면 DECREASING을 
한 줄에 출력한다. 만약 위의 두 경우가 아니라면 NEITHER를 
출력한다. 

&Example
-input
5
JOE
BOB
ANDY
AL
ADAM

-output
DECREASING

-input
11
HOPE
ALI
BECKY
JULIE
MEGHAN
LAUREN
MORGAN
CARLI
MEGAN
ALEX
TOBIN

-output
NEITHER

-input
4
GEORGE
JOHN
PAUL
RINGO

-output
INCREASING


*/


//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//#include <string>
//using namespace std;
//
//int main() {
//	int N;
//	string s[20];
//	cin >> N;
//	for (int i = 0; i < N; i++)
//		cin >> s[i];
//	bool increasing = true, decreasing = true;
//	for(int i=0;i<N-1;i++)
//		if (s[i].compare(s[i + 1]) > 0) {
//			increasing = false;
//			break;
//		}
//	for(int i=0;i<N-1;i++)
//		if (s[i].compare(s[i + 1]) < 0) {
//			decreasing = false;
//			break;
//		}
//	if (increasing)
//		cout << "INCREASING" << endl;
//	else if (decreasing)
//		cout << "DECREASING" << endl;
//	else
//		cout << "NEITHER" << endl;
//	return 0;
//}
