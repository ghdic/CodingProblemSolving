/*
https://www.acmicpc.net/problem/1755

&Title
	1755번 - 숫자놀이

&Question
79를 영어로 읽되 숫자 단위로 하나씩 읽는다면 "seven 
nine"이 된다. 80은 마찬가지로 "eight zero"라고 읽는다. 79는 80보다 
작지만, 영어로 숫자 하나씩 읽는다면 "eight zero"가 "seven nine"보다 
사전순으로 먼저 온다.문제는 정수 M, N(1 ≤ M, N 
≤ 99)이 주어지면 M 이상 N 이하의 정수를 숫자 
하나씩 읽었을 때를 기준으로 사전순으로 정렬하여 출력하는 것이다. 

&Input
첫째 줄에 M과 N이 주어진다. 

&Output
M 이상 N 이하의 정수를 문제 조건에 맞게 
정렬하여 한 줄에 10개씩 출력한다. 

&Example
-input
8 28

-output
8 9 18 15 14 19 11 17 16 13
12 10 28 25 24 21 27 26 23 22
20


*/

/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string kv[10] = {
	"zero",
	"one",
	"two",
	"three",
	"four",
	"five",
	"six",
	"seven",
	"eight",
	"nine"
};

struct Num {
	int num;
	string str_num;

	Num(int num) {
		this->num = num;
		str_num = to_string(num);
	}

	string to_string(int num) {
		string s = "";
		while (num) {
			int rest = num % 10;
			num /= 10;
			if (s == "")
				s = kv[rest];
			else
				s = kv[rest] + " " + s;
		}
		return s;
	}

	bool operator < (const Num& nm) {
		return str_num < nm.str_num;
	}
};


int m, n;
vector<Num> v;

int main() {
	ios::sync_with_stdio(false);
	cin >> m >> n;
	for (int i = m; i <= n; i++) {
		v.push_back(Num(i));
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++) {
		if (i !=0 && i % 10 == 0)cout << "\n";
		cout << v[i].num << " ";
	}

	return 0;
}
*/