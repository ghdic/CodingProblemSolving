//https://algospot.com/judge/problem/read/CLOCKSYNC
/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define INF 9999
#define SWITCH 10
#define CLOCK 16
//linked[i][j]=1 i번 스위치와 j번 시계가 연결되어 있다
//linked[i][j]=0 i번 스위치와 j번 시계가 연결되어 있지 않다

int linked[SWITCH][CLOCK] = {
	{ 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0 },
{ 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1 },
{ 1, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0 },
{ 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1 },
{ 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1 },
{ 0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1 },
{ 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0 }
};

//모든 시계가 12시를 가리키고 있는지 확인한다.
bool areAligned(const vector<int>&clocks) {

	for (int i = 0; i<CLOCK; ++i)
		if (clocks[i] != 12)
			return false;
	return true;
}
//swtch번 스위치를 누른다.
void push(vector<int>& clocks, int swtch) {
	for (int clock = 0; clock < CLOCK; ++clock) {
		if (linked[swtch][clock] == 1) {
			clocks[clock] += 3;
			if (clocks[clock] == 15)clocks[clock] = 3;
		}
	}
}

//clocks:현재 시계들의 상태
//switch: 이번에 누를 스위치의 번호
//가 주어질때, 남은 스위치들을 눌러서 clocks를 12시로 맞출 수 있는 최소 횟수를 반환한다.
//만약 불가능하다면 INF이상의 큰 수를 반환한다.
int solve(vector<int>&clocks, int swtch) {
	if (swtch == SWITCH)return areAligned(clocks) ? 0 : INF;
	//이 스위치를 0번 누르는 경우부터 세 번 누르는 경우까지를 모두 시도한다.
	int ret = INF;
	for (int cnt = 0; cnt < 4; ++cnt) {
		ret = min(ret, cnt + solve(clocks, swtch + 1));
		push(clocks, swtch);
	}
	//push(clocks, swtch)가 네번 호출되었으니 clocks는 원래와 같은 상태가 된다.
	return ret;
}

int main() {
	int C;
	cin >> C;
	if (C < 0 || C>30)exit(-1);

	for (int i = 0; i < C; ++i) {
		vector<int>clocks;
		clocks.resize(CLOCK);
		for (int j = 0; j < CLOCK; ++j)
			cin >> clocks[j];
		int result = solve(clocks, 0);
		if (result == INF)result = -1;
		cout << result << endl;
	}
	return 0;
}
*/