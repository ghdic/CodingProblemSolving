/*
https://www.acmicpc.net/problem/5063

&Title
TGN
&Question
상근이는 TGN사의 사장이다. TGN은 Teenager Game Network의 약자 같지만, 사실 Temporary Group Name의 약자이다.

이 회사는 청소년을 위한 앱을 만드는 회사이다. 일년에 걸친 개발기간 끝에 드디어 앱을 완성했고, 이제 팔기만 하면 된다.

상근이는 데이트를 인간의 두뇌로 이해할 수 없을 정도로 많이 한다. 따라서 엄청난 데이트 비용이 필요하다. 상근이는 광고를 적절히 해서 수익을 최대한 올리려고 한다.

어느날 하늘을 바라보던 상근이는 시리우스의 기운을 받게 되었고, 광고 효과를 예측하는 능력을 갖게 되었다.

광고 효과가 주어졌을 때, 광고를 해야할지 말아야할지 결정하는 프로그램을 작성하시오.
&Input
첫째 줄에 테스트 케이스의 개수 N이 주어진다. 다음 N개의 줄에는 3개의 정수 r, e, c가 주어진다. r은 광고를 하지 않았을 때 수익, e는 광고를 했을 때의 수익, c는 광고 비용이다. (-106 ≤ r,e ≤ 106, 0 ≤ c ≤ 106)
&Output
각 테스트 케이스에 대해서, 광고를 해야 하면 "advertise", 하지 않아야 하면 "do not advertise", 광고를 해도 수익이 차이가 없다면 "does not matter"를 출력한다.
&Example
-input
3
0 100 70
100 130 30
-100 -70 40
-output
advertise
does not matter
do not advertise
*/

/*
#include <iostream>
using namespace std;

int main() {
	int N;
	int r, e, c;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> r >> e >> c;
		if (c < e - r)cout << "advertise" << endl;
		else if (c == e - r)cout << "does not matter" << endl;
		else cout << "do not advertise" << endl;
	}
	return 0;
}
*/