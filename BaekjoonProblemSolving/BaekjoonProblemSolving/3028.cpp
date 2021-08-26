/*
https://www.acmicpc.net/problem/3028

&Title
	3028번 - 창영마을출처다국어 

&Question
상근이와 정인이는 창영마을에 살고 있다. 창영마을은 전세계에서 가장 
평화로운 마을로 알려져 있다. 이 마을의 이장은 상근이다.정인이는 항상 
상근이의 자리를 질투하고 있다. 정인이는 상근이가 이장의 자격이 없다는 
것을 속임수를 이용해서 사람들에게 알려주려고 한다. 먼저 정인이는 불투명한 
컵 세 개를 일렬로 탁자 위에 올려놓고, 가장 왼쪽 
컵에 작은 공 하나를 넣어놓았다. 이제 정인이는 컵 2개를 
위치를 바꿔가면서 여러 번 섞을것이고, 모두 섞은 뒤에 상근이에게 
어떤 컵에 공이 들어있는지 말하라고 할 것이다. 컵이 3개가 
있을 때, 위치를 바꿀 수 있는 가능한 방법은 아래와 
같이 3가지가 있다.정인이는 이날만을 위해 컵 섞기를 30년간 연습해왔다. 
따라서 상근이는 아무리 쳐다보아도 정인이의 팔 속도를 따라갈수 없다.하지만, 
정인이는 상근이가 뛰어난 프로그래머라는 것을 잊고 있었다. 또한, 상근이는 
정인이가 언젠간 이런 반란을 일으킬 것을 알았기 때문에, 항상 
정인이와 만날 때는 모든 상황을 비디오로 녹화하고 있었다.정인이가 컵을 
섞은 방법이 순서대로 주어질 때, 어떤 컵에 공이 있는지 
알아내는 프로그램을 작성하시오. 

&Input
첫째 줄에 정인이가 컵을 섞은 순서가 주어진다. 이 
순서는 A, B, C중 하나이고, 문제에 있는 그림을 참고하면 
된다. 정인이는 컵을 최대 50번 섞는다. 

&Output
공이 가장 왼쪽 컵에 있으면 1, 중앙에 있는 
컵에 있으면 2, 오른쪽에 있는 컵에 있으면 3을 출력한다. 


&Example
-input
AB

-output
3

-input
CBABCACCC

-output
1


*/

/*
#include <iostream>
#include <string>
using namespace std;

int res = 1;
string s;

void mix(char c) {
	if (c == 'A') {
		if (res == 1)res = 2;
		else if (res == 2)res = 1;
	}
	else if (c == 'B') {
		if (res == 2) res = 3;
		else if (res == 3)res = 2;
	}
	else if (c == 'C') {
		if (res == 1)res = 3;
		else if (res == 3)res = 1;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin >> s;
	for (char c : s) {
		mix(c);
	}
	cout << res << endl;
	return 0;
}
*/