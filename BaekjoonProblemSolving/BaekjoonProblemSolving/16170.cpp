/*
https://www.acmicpc.net/problem/16170

&Title
16170번 - 오늘의 날짜는 스페셜 저지

&Question
2018 SCAL-MOOKJA에 출전하기로 한 무근이와 인서는 대회 준비를 
위해 같이 모여 문제를 풀기로 했다.그런데 어느 날, 일어나서 
날짜를 확인해 보니 무근이와 인서의 시계가 서로 다른 날짜를 
가리키고 있었다. 두 사람이 정확한 날짜에 모일 수 있도록 
문제를 푸는 지금 시각이 UTC+0(세계 표준시)을 기준으로 무슨 날짜인지 
출력해 주는 프로그램을 작성하자.만약 서울에서 확인한 시각이 2018년 9월 
29일 오후 2시 정각이라면 UTC+0 기준의 시각은 2018년 9월 
29일 오전 5시 정각이다.Fri Sep 29 05:00:00 UTC 2018 


&Input
이 문제는 입력이 없다. 

&Output
지금 시각을 UTC+0(세계 표준시)을 기준으로 나타냈을 때의 연도, 
월, 일을 한 줄에 하나씩 순서대로 출력한다. 

&Example
-input

-output
2018
09
29


*/

/*
#include <cstdio>
#include <ctime>
using namespace std;

int main() {
	time_t timer = time(NULL);
	struct tm* t = gmtime(&timer);
	printf("%d\n%d\n%d\n", t->tm_year + 1900, t->tm_mon + 1, t->tm_mday);
	return 0;
}
*/