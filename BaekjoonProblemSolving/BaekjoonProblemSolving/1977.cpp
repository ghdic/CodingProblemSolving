/*
https://www.acmicpc.net/problem/1977

&Title
완전제곱수
&Question
M과 N이 주어질 때 M이상 N이하의 자연수 중 완전제곱수인 것을 모두 골라 그 합을 구하고 그 중 최소값을 찾는 프로그램을 작성하시오. 예를 들어 M=60, N=100인 경우 60이상 100이하의 자연수 중 완전제곱수는 64,  81,  100 이렇게 총 3개가 있으므로 그 합은 245가 되고 이 중 최소값은 64가 된다.
&Input
첫째 줄에 M이, 둘째 줄에 N이 주어진다. M과 N은 10000이하의 자연수이며 M은 N보다 같거나 작다.
&Output
M이상 N이하의 자연수 중 완전제곱수인 것을 모두 찾아 첫째 줄에 그 합을, 둘째 줄에 그 중 최소값을 출력한다. 단, M이상 N이하의 자연수 중 완전제곱수가 없을 경우는 첫째 줄에 -1을 출력한다.
&Example
-input
60
100
-output
245
64
*/

/*
#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int M, N, sum = 0, first = -1;
	bool b = false;
	cin >> M >> N;
	for (int i = 1; i < 317; i++) {
		if (pow(i, 2) > N)break;
		if (b == true)sum += pow(i, 2);
		if (pow(i, 2) >= M && b == false) {
			b = true;
			first = pow(i, 2);
			sum += pow(i, 2);
		}
		
	}
	if (first == -1)cout << -1 << endl;
	else cout << sum << "\n" << first << endl;
	return 0;
}
*/