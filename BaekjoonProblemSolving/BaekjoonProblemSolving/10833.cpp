/*
https://www.acmicpc.net/problem/10833

&Title
���
&Question
���ϵ� Ư��ǰ�� ����� �л��鿡�� �����ֱ� ���� ���� �б��� ����� �����Ͽ���. ������ ��� ������ �б����� �ٸ� �� �ְ�, �л� ���� �б����� �ٸ� �� �ִ�. �� �б������� ������ ����� ��� �л��鿡�� �Ȱ��� �����ֵ�, ���� ����� ������ �ּҷ� �Ϸ��� �Ѵ�. (���� �ٸ� �б��� ���� �л��� �޴� ��� ������ �ٸ� �� �ִ�.)

���� ���, 5�� �б��� �л� ���� ������ ��� ���� ������ ���ٰ� ����.
�б�	A	B	C	D	E
�л� ��	24	13	5	23	7
��� ����	52	22	53	10	70
A �б������� ��� �л����� ����� �� ���� �����ְ� 4���� ����� ���� �ȴ�. B �б������� ��� �л����� ����� �� ���� �����ְ� 9���� ����� ���� �ȴ�. ����ϰ� C �б������� 3���� �����, D �б������� 10���� �����, E �б������� 0���� ����� ���� �Ǿ�, ���� ����� �� ���� 4+9+3+10+0 = 26�̴�.

�� �б��� �л� ���� ��� ������ �־����� ��, �л��鿡�� �����ְ� ���� ����� �� ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
&Input
ù ��° �ٿ��� �б��� ���� ��Ÿ���� ���� N (1 �� N �� 100)�� �־�����. ���� N ���� �ٿ� �� �б��� �л� ���� ������ ��� ������ ��Ÿ���� �� ���� ������ �־�����. �л� ���� ��� ������ ��� 1�̻� 100�����̴�.
&Output
���� ����� �� ������ ��Ÿ���� ������ ����Ѵ�.
&Example
-input
5
24 52
13 22
5 53
23 10
7 70
-output
26
*/

/*
#include <iostream>
using namespace std;

int main() {
	int N, sum = 0, a, b;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		sum += b % a;
	}
	cout << sum << endl;
	return 0;
}
*/