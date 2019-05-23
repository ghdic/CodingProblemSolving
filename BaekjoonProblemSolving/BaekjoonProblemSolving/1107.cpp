/*
https://www.acmicpc.net/problem/1107

&Title
1107번 - 리모컨

&Question
수빈이는 TV를 보고 있다. 수빈이는 채널을 돌리려고 했지만, 
버튼을 너무 세게 누르는 바람에, 일부 숫자 버튼이 고장났다.리모컨에는 
버튼이 0부터 9까지 숫자, +와 -가 있다. +를 누르면 
현재 보고있는 채널에서 +1된 채널로 이동하고, -를 누르면 -1된 
채널로 이동한다. 채널 0에서 -를 누른 경우에는 채널이 변하지 
않고, 채널은 무한대 만큼 있다.수빈이가 지금 이동하려고 하는 채널은 
N이다. 어떤 버튼이 고장났는지 주어졌을 때, 채널 N으로 이동하기 
위해서 버튼을 최소 몇 번 눌러야하는지 구하는 프로그램을 작성하시오. 
수빈이가 지금 보고 있는 채널은 100번이다. 

&Input
첫째 줄에 수빈이가 이동하려고 하는 채널 N (0 
≤ N ≤ 500,000)이 주어진다. 둘째 줄에는 고장난 버튼의 
개수 M (0 ≤ M ≤ 10)이 주어진다. 고장난 
버튼이 있는 경우에는 셋째 줄에는 고장난 버튼이 주어지며, 같은 
버튼이 여러 번 주어지는 경우는 없다. 

&Output
첫째 줄에 채널 N으로 이동하기 위해 버튼을 최소 
몇 번 눌러야 하는지를 출력한다. 

&Example
-input
5457
3
6 7 8

-output
6

-input
100
5
0 1 2 3 4

-output
0

-input
500000
8
0 2 3 4 6 7 8 9

-output
11117


*/

/*
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cmath>
#include <string>
#define MIN(a,b) (a<b ? a:b)
using namespace std;

int button_set[10] = { 1,1,1,1,1,1,1,1,1,1 };
int min_cnt = 0x3f3f3f3f, N;
void find(string num) {
	for (int i = 0; i < 10; i++) {
		if (button_set[i]) {
			string tmp_num = num + to_string(i);
			min_cnt = MIN(min_cnt, abs(N - stoi(tmp_num)) + tmp_num.length());
			
			if (tmp_num.length() < 6)
				find(tmp_num);
		}
	}
}

int main() {
	int M, channel = 100, arr[10], temp = 0;
	scanf("%d", &N);
	min_cnt = MIN(min_cnt, abs(100 - N));
	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		scanf("%d", &temp);
		button_set[temp] = 0;
	}
	if (M < 10) {
		find("");
	}
	printf("%d", min_cnt);
	return 0;
}
*/

/*
아..뭔가 숫자 중복안된다고 잘못생각해버렸다.
재귀를 통해 채널 자리수에 맞게 구해준다.
사람들이 많이 틀린 이유는 경우를 둘로 안나눠서 그런거 아닐까
채널 옮기고 +-하기, +-하기를 나누어주면 된다.

*/