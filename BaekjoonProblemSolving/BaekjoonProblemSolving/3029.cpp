/*
https://www.acmicpc.net/problem/3029

&Title
	3029번 - 경고출처다국어 

&Question
창영마을에서 정인이의 반란은 실패로 끝났다. (3028번)테러리스트로 변신한 정인이는 
창영마을에 경고를 하려고 한다.사실 정인이는 창영마을에서 제일 착한사람이다. 따라서, 
사람들을 다치지 않게하려고 한다.유튜브에서 폭발에 대한 동영상을 찾아보다가, 그는 
나트륨을 물에 던지면 폭발한다는 사실을 알게 되었다.정인이는 창영마을의 중심을 
지나는 "강산강" 근처에 숨어있다가, 나트륨을 위의 동영상처럼 물에 던질 
것이다.현재 시간과 정인이가 나트륨을 던질 시간이 주어졌을 때, 정인이가 
얼마나 숨어있어야 하는지 구하는 프로그램을 작성하시오. (정인이는 적어도 1초를 
기다리며, 많아야 24시간을 기다린다.) 

&Input
첫째 줄에 현재 시간이 hh:mm:ss 형식으로 주어진다. (시, 
분, 초) hh는 0보다 크거나 같고, 23보다 작거나 같으며, 
분과 초는 0보다 크거나 같고, 59보다 작거나 같다.둘째 줄에는 
나트륨을 던질 시간이 위와 같은 형식으로 주어진다. 

&Output
첫째 줄에 정인이가 기다려야 하는 시간을 입력과 같은 
형식으로 출력한다. 

&Example
-input
20:00:00
04:00:00

-output
08:00:00

-input
12:34:56
14:36:22

-output
02:01:26


*/

/*
#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

string cur_time, end_time;

struct Time {
	int h, m, s;

	Time() { h = m = s = 0; }

	Time(string t) {
		h = (t[0] - '0') * 10 + (t[1] - '0');
		m = (t[3] - '0') * 10 + (t[4] - '0');
		s = (t[6] - '0') * 10 + (t[7] - '0');
	}

	Time operator - (Time& t) {
		Time new_t;
		bool check = false;
		if (s < t.s) {
			new_t.s = 60 + s - t.s;
			check = true;
		}
		else {
			new_t.s = s - t.s;
		}

		if (m - check < t.m) {
			new_t.m = 60 + m - t.m - check;
			check = true;
		}
		else {
			new_t.m = m - t.m - check;
			check = false;
		}

		if (h - check < t.h) {
			new_t.h = 24 + h - t.h - check;
		}
		else {
			new_t.h = h - t.h - check;
		}
		return new_t;
	}

	string toString() {
		char output[9];
		sprintf(output, "%02d:%02d:%02d", h, m, s);
		return string(output);
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin >> cur_time;
	cin >> end_time;

	Time c = Time(cur_time);
	Time e = Time(end_time);

	Time result = e - c;
	if (result.h == 0 && result.m == 0 && result.s == 0)
		result.h = 24;

	cout << result.toString() << endl;
	return 0;
}
*/