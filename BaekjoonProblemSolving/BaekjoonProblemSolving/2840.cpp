/*
https://www.acmicpc.net/problem/2840

&Title
2840번 - 행운의 바퀴

&Question
상덕이는 최근에 행운의 바퀴를 구매했다. 상덕이는 바퀴의 각 
칸에 알파벳 대문자를 아래 그림과 같이 적었다.바퀴에 같은 글자는 
두 번 이상 등장하지 않는다. 또, 바퀴는 시계방향으로만 돌아간다. 
바퀴 옆에는 화살표가 있는데, 이 화살표는 항상 한 곳을 
가리키고 있으며, 돌아가는 동안 가리키는 글자는 바뀌게 된다. 위의 
그림에서는 H를 가리키고 있다.상덕이는 바퀴를 연속해서 K번 돌릴 것이다. 
매번 바퀴를 돌릴 때 마다, 상덕이는 화살표가 가리키는 글자가 
변하는 횟수와 어떤 글자에서 회전을 멈추었는지를 종이에 적는다.희원이는 상덕이가 
적어놓은 종이를 발견했다. 그 종이를 바탕으로 상덕이가 바퀴에 적은 
알파벳을 알아내려고 한다.상덕이가 종이에 적어놓은 내용과 바퀴의 칸의 수가 
주어졌을 때, 바퀴에 적어놓은 알파벳을 알아내는 프로그램을 작성하시오. 

&Input
첫째 줄에 바퀴의 칸의 수 N과 상덕이가 바퀴를 
돌리는 횟수 K가 주어진다. (2 ≤ N ≤ 25, 
1 ≤ K ≤ 100)다음 줄부터 K줄에는 바퀴를 회전시켰을 
때 화살표가 가리키는 글자가 몇 번 바뀌었는지를 나타내는 S와 
회전을 멈추었을 때 가리키던 글자가 주어진다. (1 ≤ S 
≤ 100) 

&Output
첫째 줄에 마지막 회전에서 화살표가 가리키는 문자부터 시계방향으로 
바퀴에 적어놓은 알파벳을 출력한다. 이때, 어떤 글자인지 결정하지 못하는 
칸은 '?'를 출력한다. 만약, 상덕이가 적어놓은 종이에 해당하는 행운의 
바퀴가 없다면 "!"를 출력한다. 

&Example
-input
8 8
4 V
3 I
7 T
7 A
6 R
5 N
1 O
9 H

-output
HONITAVR


*/

/*
#include <cstdio>
#include <cstring>
int n, k; // 2~25 바퀴칸수, 1~1000 바퀴돌리는횟수
int s; // 1~100 글자 몇번바뀌었는지
char c; // 가르키던 글자
char str[27]; // 룰렛에 글자
bool check[26];
int main() {
	setbuf(stdout, NULL);
	memset(str, '?', sizeof(char) * 27); // ? 으로 초기화
	scanf("%d %d", &n, &k);

	int pos = 0;
	bool impossible = false;
	for (int i = 0; i < k; ++i) {
		scanf("%d %c", &s, &c);
		pos -= s % n;
		pos = pos < 0 ? n + pos : pos;
		if (str[pos] == '?' && !check[c - 'A']) {
			check[c - 'A'] = true;
			str[pos] = c;
		}
		else if (str[pos] == c);
		else {
			impossible = true;
		}
	}
	if (impossible) {
		printf("%s\n", "!");
		return 0;
	}
	
	//char temp[26];
	//
	//memcpy(temp, str + pos, (n - pos) * sizeof(char));
	//memcpy(str + (n - pos), str, pos * sizeof(char));
	//memcpy(str, temp, (n - pos) * sizeof(char));
	//str[n] = '\0';
	//printf("%s\n", str);
	
	for (int i = 0; i < n; i++)
		printf("%c", str[(i + pos) % n]);
	printf("\n");
	return 0;
}
*/