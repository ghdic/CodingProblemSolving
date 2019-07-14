/*
https://www.acmicpc.net/problem/2818

&Title
2818번 - 숙제하기 싫을 때

&Question
상근이는 숙제가 너무 하기 싫어서, 숙제 한 달치를 
걸고 창영이와 게임을 하기로 했다. 진 사람은 한 달동안 
숙제 두 명분을 해야 한다. 상근이는 영리하게 자신이 어렸을 
때, 하던 게임을 하자고 했다. 창영이는 흔쾌히 수락했다.이 게임을 
하기 위해서는 주사위가 필요하다. 주사위는 왼쪽 그림과 같이 생겼다. 
마주보는 면에 쓰여 있는 숫자의 합은 항상 7이다. 즉, 
6은 1, 5는 2, 4는 3은 마주보는 면이다. 그 
다음, 한 칸의 크기가 주사위의 한 면과 같은 표를 
그린다. 이 표의 크기는 R행 C열이다. 주사위는 가장 처음에 
왼쪽 위 칸에 있다. 윗 면에는 숫자 1이 있고, 
오른쪽 면에는 숫자 3이 있다. 이제 다음과 같이 주사위를 
굴린다. 1. 주사위를 마지막 열에 도착하기 전까지 오른쪽으로 굴린다. 
2. 주사위를 아래줄로 한 칸 굴린다. 3. 주사위를 첫 
번째 열에 도착하기 전까지 왼쪽으로 굴린다. 4. 2단계와 비슷하게 
주사위를 한 칸 아래로 굴린다. 상근이는 위와 같은 단계를 
할 수 있을 때 까지, 즉, 마지막 줄까지 반복한다. 
주사위가 어떤 칸에 도착하면, 창영이는 주사위 윗 면의 숫자를 
적는다. 마지막에, 지금까지 적은 숫자를 모두 더한 다음, 상근이에게 
물어본다. 상근이는 정답을 말할 것이고, 이 숫자가 창영이가 더한 
합과 같다면 상근이가 이긴다. 상근이는 잠시 머뭇거리다가 정답을 말했다. 
이제 창영이는 이 정답이 맞는지 확인해야 한다. R과 C가 
주어졌을 때, 윗 면의 합을 구하는 프로그램을 작성하시오. 

&Input
첫째 줄에 R과 C가 주어진다. (1 ≤ R, 
C ≤ 100,000) 

&Output
첫째 줄에 정답을 출력한다. 

&Example
-input
3 2

-output
19


*/

/*
#include <cstdio>
using namespace std;

struct dice { // 주사위 구조체
	int row[4];
	int up, down;

	dice() { // 구조체 안에 생성자 선언이되네?
		row[0] = 4;
		row[1] = 6;
		row[2] = 3;
		row[3] = 1;
		up = 5;
		down = 2;
	}
	void roll_down() { // 함수도..?
		int old_up = up;
		up = row[1];
		row[1] = down;
		down = row[3];
		row[3] = old_up;
	}

	void roll_right() {
		int old_left = row[0];

		for (int i = 0; i < 3; ++i)
			row[i] = row[i + 1];
		row[3] = old_left;
	}

	void roll_left() {
		int old_right = row[3];
		for (int i = 3; i > 0; --i)
			row[i] = row[i - 1];
		row[0] = old_right;
	}

	void roll(bool dir) {
		if (!dir)roll_right();
		else roll_left();
	}

	int top() { return row[3]; }
	int sum_row() { return row[0] + row[1] + row[2] + row[3]; } // 항상 14
};

int main() {
	dice curr;

	int r, c;
	scanf("%d %d", &r, &c);

	long long sol = 0;
	bool dir = false;

	for (int row = 0; row < r; ++row, dir = !dir) {
		sol += curr.top();

		int repeat = (c - 1) / 4;
		sol += repeat * curr.sum_row(); // 4번 이상 돌 경우 반복됨.

		int rest = (c - 1) % 4;
		for (int i = 0; i < rest; ++i) { // 나머지 처리
			curr.roll(dir);
			sol += curr.top();
		}

		curr.roll_down();
	}

	printf("%lld\n", sol);
	return 0;
}
*/

// 구현문제이다.
// 처음엔 3 * 4 배열로 구현하려했는데
// 이렇게 구조체로 다루니깐 훨씬 편하네...