/*
https://www.acmicpc.net/problem/2457

&Title
2457번 - 공주님의 정원

&Question
오늘은 공주님이 태어난 경사스러운 날이다. 왕은 이 날을 
기념하기 위해 늘 꽃이 피어있는 작은 정원을 만들기로 결정했다.총 
N개의 꽃이 있는 데, 꽃은 모두 같은 해에 피어서 
같은 해에 진다. 하나의 꽃은 피는 날과 지는 날이 
정해져 있다. 예를 들어, 5월 8일 피어서 6월 13일 
지는 꽃은 5월 8일부터 6월 12일까지는 꽃이 피어 있고, 
6월 13일을 포함하여 이후로는 꽃을 볼 수 없다는 의미이다. 
(올해는 4, 6, 9, 11월은 30일까지 있고, 1, 3, 
5, 7, 8, 10, 12월은 31일까지 있으며, 2월은 28일까지만 
있다.)이러한 N개의 꽃들 중에서 다음의 두 조건을 만족하는 꽃들을 
선택하고 싶다.공주가 가장 좋아하는 계절인 3월 1일부터 11월 30일까지 
매일 꽃이 한 가지 이상 피어 있도록 한다.정원이 넓지 
않으므로 정원에 심는 꽃들의 수를 가능한 적게 한다. N개의 
꽃들 중에서 위의 두 조건을 만족하는, 즉 3월 1일부터 
11월 30일까지 매일 꽃이 한 가지 이상 피어 있도록 
꽃들을 선택할 때, 선택한 꽃들의 최소 개수를 출력하는 프로그램을 
작성하시오. 

&Input
첫째 줄에는 꽃들의 총 개수 N (1<=N<=100,000)이 주어진다. 
다음 N개의 줄에는 각 꽃이 피는 날짜와 지는 날짜가 
주어진다. 하나의 날짜는 월과 일을 나타내는 두 숫자로 표현된다. 
예를 들어서, 3 8 7 31은 꽃이 3월 8일에 
피어서 7월 31일에 진다는 것을 나타낸다. 

&Output
첫째 줄에 선택한 꽃들의 최소 개수를 출력한다. 만약 
두 조건을 만족하는 꽃들을 선택할 수 없다면 0을 출력한다. 


&Example
-input
4
1 1 5 31
1 1 6 30
5 15 8 31
6 10 12 10
-output
2

*/

/*
1. st순으로 정렬해줌(같을 경우 ed가 큰게 앞으로)
========
2. startTime보다 클때까지 반복 후 이전값을 사용하여 startTime를 업데이트해줌
3. startTime > endTime일때까지 반복
========
*/
#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;

struct date {
	int month, day;
	date(int m = 0, int d = 0) : month(m), day(d) {};

	bool operator < (const date& a) {
		return (month == a.month ? day < a.day : month < a.month);
	}

	bool operator > (const date& a) {
		return (month == a.month ? day > a.day : month > a.month);
	}

	bool operator == (const date& a) {
		return month == a.month && day == a.day;
	}
};

struct flower {
	date st, ed;
	flower(date _st = date(), date _ed = date()) : st(_st), ed(_ed) {};

	bool operator < (const flower& a) {
		return (st == a.st ? ed > a.ed : st < a.st);
	}
};
int n;

flower arr[100001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i].st.month >> arr[i].st.day >> arr[i].ed.month >> arr[i].ed.day;
	}
	sort(&arr[0], &arr[n]);
	for (int i = 0; i < n; ++i) {
		cout << arr[i].st.month << " " << arr[i].st.day << endl;
	}

	int index = -1;
	date temp();
	int res = 0;
	date left(3, 1), right(11, 30);
	while(left < right){
		bool flag = false;
		++index;

		for (int j = index; j < n; ++j) {
			if (arr[j].st > left)break;

			if (temp < arr[j].ed)
		}
		
	}
	return 0;
}
