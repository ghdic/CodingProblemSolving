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
2. startTime보다 클때까지 반복 하여 index증가 클경우 arr[index-1].ed를 사용하여 startTime를 업데이트해줌
(이때 startTime이 같은 경우 ed < a.ed 정렬하므로 ed가 큰게 뒤에 있음
3. startTime > endTime일때까지 반복

4. 마지막 값은 무조건 업데이트 될 수 있게(arr[n]에 13월을 넣어줌)
5. l > r을 만족할 경우 res 출력 아니면 0
========
*/

/*
#include <iostream>
#include <algorithm>
using namespace std;

struct date {
	int month, day;
	date(int m = 0, int d = 0) : month(m), day(d) {};

	bool operator < (const date& a) {
		return (this->month == a.month ? this->day < a.day : this->month < a.month);
	}

	bool operator > (const date& a) {
		return (this->month == a.month ? this->day > a.day : this->month > a.month);
	}

	bool operator == (const date& a) {
		return this->month == a.month && this->day == a.day;
	}

};

struct flower {
	date st, ed;
	flower(date _st = date(), date _ed = date()) : st(_st), ed(_ed) {};

	bool operator < (const flower& a) {
		return (st == a.st ? ed < a.ed : st < a.st); // 공백이 생기는 순간 이전꺼 사용할꺼니 ㅇ.ㅇ
	}
};
int n;

flower arr[100002];
int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i].st.month >> arr[i].st.day >> arr[i].ed.month >> arr[i].ed.day;
	}
	sort(&arr[0], &arr[n]);
	arr[n] = { date(13,0), date(13,1) };

	date l(3, 1), r(11, 30), update = arr[0].ed, prev = l;
	int index = 1, res = 0;
	if (l < arr[0].st) {
		cout << 0 << endl;
		return 0;
	}
	while (index <= n) {
		if (l < arr[index].st) {
			l = update; // 이전까지 있던 값중 가장 큰걸로 업뎃
			++res;
			if (l > r)break; // 끝
			if (prev == l)break; // 더이상 전진 불가
			prev = l;
		}
		else {
			if (arr[index].ed > update)update = arr[index].ed;
			++index;
		}
	}
	if (l > r)
		cout << res << endl;
	else
		cout << 0 << endl;
	return 0;
}
*/


/*
#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;
int n;

pair<int, int> arr[100002];
int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	int a, b, c, d;
	for (int i = 0; i < n; ++i)
	{
		cin >> a >> b >> c >> d;
		arr[i].first = 100 * a + b;
		arr[i].second = 100 * c + d;
	}
	sort(&arr[0], &arr[n]);
	arr[n] = { 1300, 1301 };

	int l = 301, r = 1130, update = arr[0].second, prev = l;
	int index = 1, res = 0;
	if (l < arr[0].first) {
		cout << 0 << endl;
		return 0;
	}
	while (index <= n) {
		if (l < arr[index].first) {
			l = update; // 이전까지 있던 값중 가장 큰걸로 업뎃
			++res;
			if (l > r)break; // 끝
			if (prev == l)break; // 더이상 전진 불가
			prev = l;
		}
		else {
			if (arr[index].second > update)update = arr[index].second;
			++index;
		}
	}
	if (l > r)
		cout << res << endl;
	else
		cout << 0 << endl;
	return 0;
}
*/