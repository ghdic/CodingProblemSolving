/*
https://www.acmicpc.net/problem/2935

&Title
소음
&Question
수업 시간에 떠드는 두 학생이 있다. 두 학생은 수업에 집중하는 대신에 글로벌 경제 위기에 대해서 토론하고 있었다. 토론이 점점 과열되면서 두 학생은 목소리를 높였고, 결국 선생님은 크게 분노하였다.

이렇게 학생들이 수업 시간에 떠드는 문제는 어떻게 해결해야 할까?

얼마전에 초등학교 선생님으로 취직한 상근이는 이 문제를 수학 문제로 해결한다. 학생들을 진정시키기 위해 칠판에 수학 문제를 써주고, 아이들에게 조용히 이 문제를 풀게 한다. 학생들이 문제를 금방 풀고 다시 떠드는 것을 방지하기 위해서, 숫자를 매우 크게 한다.

아직 초등학교이기 때문에, 학생들은 덧셈과 곱셈만 배웠다. 또, 아직 10의 제곱꼴을 제외한 다른 수는 학교에서 배우지 않았기 때문에, 선생님이 써주는 수는 모두 10의 제곱 형태이다.

쉬는 시간까지 문제를 푸는 것을 막기 위해서, 선생님이 써주는 숫자는 최대 100자리이다.

칠판에 써있는 문제가 주어졌을 때, 결과를 구하는 프로그램을 작성하시오.
&Input
첫째 줄에 양의 정수 A가 주어진다.

둘째 줄에 연산자 + 또는 *가 주어진다.

셋째 줄에 양의 정수 B가 주어진다.

A와 B는 모두 10의 제곱 형태이고, 길이는 최대 100자리이다.
&Output
첫째 줄에 결과를 출력한다. 결과는 A+B 또는 A*B이며, 입력에서 주어지는 연산자에 의해 결정된다.
&Example
-input
1000
*
100
-output
100000
*/

/*
#include <iostream>
#include <string>
using namespace std;

int main() {
	string A, B;
	char op;
	int Afigure = 0, Bfigure = 0;

	cin >> A >> op >> B;
	for (int i = 0; i < A.size(); i++)
		if (A[i] == '0')
			Afigure++;

	for (int i = 0; i < B.size(); i++)
		if (B[i] == '0')
			Bfigure++;

	if (op == '+') {
		for (int i = (Afigure > Bfigure ? Afigure : Bfigure); i >= 0; i--) {
			if (i == Afigure && i == Bfigure)
				cout << "2";
			else if (i == Afigure || i == Bfigure)
				cout << "1";
			else
				cout << "0";
		}
	}
	else if (op == '*') {
		for (int i = Afigure + Bfigure; i >= 0; i--) {
			if (i == Afigure + Bfigure)
				cout << "1";
			else
				cout << "0";
		}
	}
	cout << endl;
	return 0;
}
*/