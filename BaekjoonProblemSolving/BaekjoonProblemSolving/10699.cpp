/*
https://www.acmicpc.net/problem/10699

&Title
오늘 날짜
&Question
서울의 오늘 날짜를 출력하는 프로그램을 작성하시오.
&Input
입력은 없다.
&Output
서울의 오늘 날짜를 "YYYY-MM-DD" 형식으로 출력한다.
&Example
-input

-output
2015-01-24
*/

/*
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <ctime>
using namespace std;

int main() {
	time_t t = time(NULL);
	struct tm * now = localtime(&t);
	printf("%04d-%02d-%02d\n", now->tm_year + 1900, now->tm_mon + 1, now->tm_mday);
	return 0;
}
*/