/*
https://www.acmicpc.net/problem/9657

&Title
9657번 - 돌 게임 3

&Question
돌 게임은 두 명이서 즐기는 재밌는 게임이다.탁자 위에 
돌 N개가 있다. 상근이와 창영이는 턴을 번갈아가면서 돌을 가져가며, 
돌은 1개, 3개 또는 4개 가져갈 수 있다. 마지막 
돌을 가져가는 사람이 게임을 이기게 된다.두 사람이 완벽하게 게임을 
했을 때, 이기는 사람을 구하는 프로그램을 작성하시오. 게임은 상근이가 
먼저 시작한다. 

&Input
첫째 줄에 N이 주어진다. (1 ≤ N ≤ 
1000) 

&Output
상근이가 게임을 이기면 SK를, 창영이가 게임을 이기면 CY을 
출력한다. 

&Example
-input
6

-output
SK


*/


#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <algorithm>
#include <list>
using namespace std;

//재귀로 결과 구하는 함수
bool recursive_result(vector<int> v, bool result, int count) {

}

// 이전 결과 활용하는 함수
bool use_prev_result(vector<int> v, bool result, list<int> values) {

}

// 벡터, 마지막돌을 잡은사람이 이기는가 지는가
void rockGame(vector<int> v, bool result) {
	int count;
	list<int> values;
	sort(v.begin, v.end);
	vector<int>::iterator iter;
	// 가장 큰 수까지 재귀&이전결과로 결과 구함
	for (count = 1; count <= v[v.size];count++) {
		for (iter = v.begin; iter != v.end; ++iter) {
			// 이전 결과 활용
			if (count > *iter) {
				//리스트 pop push는 여기서 처리
				use_prev_result(v, result, values);
			}
			// 재귀로 결과 구함
			else {
				recursive_result(v, result, count);
			}
		}
	}

	// 가장 큰 수까지 결과 구했으면 이전결과로 결과 구함

}

int main() {
	int kinds, tmp;
	
	return 0;
}
