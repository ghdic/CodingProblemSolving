/*
https://www.acmicpc.net/problem/2484

&Title
2484번 - 주사위 네개

&Question
1에서부터 6까지의 눈을 가진 4개의 주사위를 던져서 다음과 
같은 규칙에 따라 상금을 받는 게임이 있다. 같은 눈이 
4개가 나오면 50,000원+(같은 눈)*5,000원의 상금을 받게 된다. 같은 눈이 
3개만 나오면 10,000원+(3개가 나온 눈)*1,000원의 상금을 받게 된다. 같은 
눈이 2개씩 두 쌍이 나오는 경우에는 2,000원+(2개가 나온 눈)*500원+(또 
다른 2개가 나온 눈)*500원의 상금을 받게 된다.같은 눈이 2개만 
나오는 경우에는 1,000원+(같은 눈)*100원의 상금을 받게 된다. 모두 다른 
눈이 나오는 경우에는 (그 중 가장 큰 눈)*100원의 상금을 
받게 된다. 예를 들어, 4개의 눈이 3, 3, 3, 
3으로 주어지면 50,000+3*5,000으로 계산되어 65,000원의 상금을 받게 된다. 4개의 
눈이 3, 3, 6, 3으로 주어지면 상금은 10,000+3*1,000으로 계산되어 
13,000원을 받게 된다. 또 4개의 눈이 2, 2, 6, 
6으로 주어지면 2,000+2*500+6*500으로 계산되어 6,000원을 받게 된다. 4개의 눈이 
6, 2, 1, 6으로 주어지면 1,000+6*100으로 계산되어 1,600원을 받게 
된다. 4개의 눈이 6, 2, 1, 5로 주어지면 그 
중 가장 큰 값이 6이므로 6*100으로 계산되어 600원을 상금으로 
받게 된다.N(1≤N≤1,000)명이 주사위 게임에 참여하였을 때, 가장 많은 상금을 
받은 사람의 상금을 출력하는 프로그램을 작성하시오. 

&Input
첫째 줄에는 참여하는 사람 수 N이 주어지고 그 
다음 줄부터 N개의 줄에 사람들이 주사위를 던진 4개의 눈이 
빈칸을 사이에 두고 각각 주어진다. 

&Output
첫째 줄에 가장 많은 상금을 받은 사람의 상금을 
출력한다. 

&Example
-input
4
3 3 3 3
3 3 6 3
2 2 6 6
6 2 1 5
-output
65000

*/

/*
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N;
	int max = -1;
	cin >> N;
	while (N--) {
		int score = 0;
		vector<int> dice(4);
		for (int i = 0; i < 4; i++) {
			cin >> dice[i];
		}
		sort(dice.begin(), dice.end());
		if (dice[0] == dice[3])
			score = 50000 + (5000 * dice[0]);
		else if (dice[0] == dice[2] || dice[1] == dice[3])
			score = 10000 + dice[2] * 1000;
		else if (dice[0] != dice[1] && dice[1] != dice[2] && dice[2] != dice[3])
			score = dice[3] * 100;
		else if (dice[0] == dice[1] && dice[2] == dice[3])
			score = 2000 + dice[0] * 500 + dice[2] * 500;
		else if (dice[0] == dice[1])
			score = 1000 + dice[0] * 100;
		else
			score = 1000 + dice[2] * 100;
		if (max < score)
			max = score;
	}
	cout << max << endl;
}
*/