/*
https://www.acmicpc.net/problem/2712

&Title
2712번 - 미국 스타일

&Question
싸이가 강남 스타일로 2012년 10월 4일 현재 빌보드 
핫100 차트 2위에 2주 연속 랭크되고 있다. 싸이는 곧 
다시 미국으로 가서 해외 활동할 예정이라고 한다.하지만 미국은 한국과 
사용하는 단위 체계가 다르다. 한국은 미터법을 사용하지만, 미국은 미국 
단위계를 사용한다. 싸이를 위해 단위를 바꾸어 주는 프로그램을 작성하시오.아래 
표를 참고해서 계산하면 되고, 킬로그램 <-> 파운드, 리터 <-> 
갤런만 변환하면 된다.종류미터법미국 단위계무게1.000 킬로그램2.2046 파운드 0.4536 킬로그램1.0000 파운드부피1.0000 
리터0.2642 갤런 3.7854 리터1.0000 갤런 

&Input
첫째 줄에 테스트 케이스의 개수 T(1<=T<=1,000)가 주어진다. 각 
테스트 케이스는 한 줄로 이루어져 있다. 첫 번째 숫자는 
값이고, 두 번째 등장하는 문자는 단위이다. 값은 소수점일 수도 
있다. 단위는 kg, lb, l, g 중 하나이며, 순서대로 
킬로그램, 파운드, 리터, 갤런이다. 

&Output
각 테스트 케이스에 대해서 바꾼 값과 단위를 출력한다. 
값은 반올림해서 소수점 4째자리까지 출력한다. 단위는 kg, lb, l, 
g중 하나이며, 설명은 입력 설명에 있다. 

&Example
-input
5 
1 kg 
2 l 
7 lb 
3.5 g 
0 l 
-output
2.2046 lb 
0.5284 g 
3.1752 kg 
13.2489 l 
0.0000 g

*/

/*
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
using namespace std;

int main() {
	int N;
	double a;
	char c[3];
	char list[4][3] = { "kg", "lb", "l", "g" };
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%lf %s", &a, c);
		if (strcmp(c, list[0]) == 0) {
			printf("%.4lf lb\n", 2.2046 * a);
		}
		else if (strcmp(c, list[1]) == 0) {
			printf("%.4lf kg\n", 0.4536 * a);
		}
		else if (strcmp(c, list[2]) == 0) {
			printf("%.4lf g\n", 0.2642 * a);
		}
		else if (strcmp(c, list[3]) == 0) {
			printf("%.4lf l\n", 3.7854 * a);
		}
	}
	return 0;
}
*/