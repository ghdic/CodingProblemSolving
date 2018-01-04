/*
https://www.acmicpc.net/problem/1924

&Title
2007년

&Question
오늘은 2007년 1월 1일 월요일이다. 그렇다면 2007년 x월 y일은 무슨 요일일까? 이를 알아내는 프로그램을 작성하시오.

&Input
첫째 줄에 빈 칸을 사이에 두고 x(1≤x≤12)와 y(1≤y≤31)이 주어진다. 참고로 2007년에는 1, 3, 5, 7, 8, 10, 12월은 31일까지, 4, 6, 9, 11월은 30일까지, 2월은 28일까지 있다.

&Output
첫째 줄에 x월 y일이 무슨 요일인지에 따라 SUN, MON, TUE, WED, THU, FRI, SAT중 하나를 출력한다.

&Example
-input
1 1
-output
MON

*/


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int month, day, sum=0;

	scanf("%d %d", &month, &day);

	for (int i = 1; i < month; i++) {
		if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
			sum += 31;
		else if (i == 4 || i == 6 || i == 9 || i == 11)
			sum += 30;
		else if (i == 2)
			sum += 28;
	}
	
	sum += day - 1;

	if (sum % 7 == 0)
		printf("MON\n");
	else if (sum % 7 == 1)
		printf("TUE\n");
	else if (sum % 7 == 2)
		printf("WED\n");
	else if (sum % 7 == 3)
		printf("THU\n");
	else if (sum % 7 == 4)
		printf("FRI\n");
	else if (sum % 7 == 5)
		printf("SAT\n");
	else if (sum % 7 == 6)
		printf("SUN\n");

	return 0;
}