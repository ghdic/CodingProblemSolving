/*
https://www.acmicpc.net/problem/10569

&Title
다면체
&Question
수학자가 구를 깎아서 볼록다면체를 만들었다. 이 수학자는 임의의 볼록다면체에 대해 (꼭짓점의 수) - (모서리의 수) + (면의 수) = 2가 성립한다는 것을 알고 있다. 그래서 구를 깎는 게 취미인 이 사람은 꼭짓점, 모서리와 면의 수를 기록할 때 꼭짓점과 모서리의 수만 세고 면의 수는 세지 않는다.
&Input
첫 번째 줄에 1 이상 100 이하의 자연수 T가 주어진다.

다음 T개의 줄에 4 이상 100 이하의 자연수 V와 E가 공백을 사이에 두고 주어진다. V와 E는 각각 꼭짓점의 개수와 모서리의 개수이다.
&Output
각 V와 E에 대해 볼록다면체의 면의 수를 한 줄에 하나씩 출력한다.
&Example
-input
2
8 12
4 6
-output
6
4
*/

/*
#include <iostream>
using namespace std;

int main() {
	int N, a, b;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		cout << 2 + b - a << endl;
	}
	return 0;
}
*/