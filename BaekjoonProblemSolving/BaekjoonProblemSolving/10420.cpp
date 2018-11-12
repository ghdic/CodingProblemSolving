/*
https://www.acmicpc.net/problem/10420

&Title
10420번 - 기념일 1

&Question
세계적으로 유명한 커플 상근이와 나예는 2016년 4월 3일이 
사귀기 시작한지 200일이 되는 날이었다. 상근이는 그 날이 200일인줄 
몰라서 나예한테 혼났다. 이런 일이 다시는 없도록 하기 위해서 
기념하려고 하는 날 수가 양의 정수로 주어지면 기념일 날짜를 
출력하는 프로그램을 작성하여 다시는 혼나는 일이 없도록 하려 한다. 
이 커플의 사귀기 시작한 날짜는 2015년 9월 17일이다. 하지만, 
알 수 없는 이유에 의해서 문제를 풀 때는 사귀기 
시작한 날짜를 2014년 4월 2일로 처리해야 한다.2월이 28일까지 있는 
년을 평년이라 하고, 29일까지 있는 년을 윤년이라 한다. 윤년은 
연도가 4의 배수이면서, 100의 배수가 아닐 때 또는 400의 
배수일 때이다. 예를들어 1900년은 4의 배수이지만 100의 배수이기 때문에 
윤년이 아니다. 하지만 2000년은 400의 배수이기 때문에 윤년이다. 

&Input
첫째 줄에 기념하려는 날이 양의 정수 N (1 
≤ N ≤ 10,000)으로 주어진다. 

&Output
첫째 줄에 기념일의 날짜를 YYYY-MM-DD 의 형식으로 출력한다. 


&Example
-input
200

-output
2014-10-18

-input
1

-output
2014-04-02


*/

/*
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;

int main() {
	int year = 2014, month = 4, day = 2, N;
	bool finish = false;
	scanf("%d", &N);
	day += N - 1;
	while (!finish) {
		switch (month) {

		case 4:
		case 6:
		case 9:
		case 11:
			//30
			if (day > 30) {
				day -= 30;
				month++;
				if (month > 12) {
					month = 1;
					year++;
				}
			}
			else
				finish = true;
			break;
		case 2:
			//28
			int date;
			if (year % 400==0) {
				date = 29;
			}
			else if(year % 100 == 0){
				date = 28;
			}
			else if (year % 4 == 0) {
				date = 29;
			}
			else {
				date = 28;
			}
			
			if (day > date) {
				day -= date;
				month++;
				if (month > 12) {
					month = 1;
					year++;
				}
			}
			else
				finish = true;
			break;
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			//31
			if (day > 31) {
				day -= 31;
				month++;
				if (month > 12) {
					month = 1;
					year++;
				}

			}
			else
				finish = true;\
		}
	}

	printf("%04d-%02d-%02d\n", year, month, day);
	return 0;
}
*/