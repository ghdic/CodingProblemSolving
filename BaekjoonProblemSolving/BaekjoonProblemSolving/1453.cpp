/*
https://www.acmicpc.net/problem/1453

&Title
1453�� - �ǽù� �˹�

&Question
�����̴� �ǽù濡�� �Ƹ�����Ʈ�� �Ѵ�. �������� �ǽù濡�� 1������ 100������ 
��ǻ�Ͱ� �ִ�.������ �մ��� ��� �ڱⰡ �ɰ� ���� �ڸ����� �ɰ��;��Ѵ�. 
���� �����鼭 ��ȣ�� ���Ѵ�. ���࿡ �� �ڸ��� ����� ������ 
�� �մ��� �� �ڸ��� �ɾƼ� ��ǻ�͸� �� �� �ְ�, 
����� �ִٸ� �������Ѵ�.�������ϴ� ����� ���� ����ϴ� ���α׷��� �ۼ��Ͻÿ�. ��ǻ�ʹ� 
�� ó���� ��� ����ְ�, � ����� �ڸ��� ������ �ڸ��� 
���� ���� ����. 

&Input
ù° �ٿ� �մ��� �� N�� �־�����. N�� 100���� 
�۰ų� ����. ��° �ٿ� �մ��� ������ ������� �� �մ��� 
�ɰ� �;��ϴ� �ڸ��� �Է����� �־�����. 

&Output
ù° �ٿ� �������ϴ� ����� ���� ����Ѵ�. 

&Example
-input
3
1 2 3

-output
0

*/

/*
#include <iostream>
using namespace std;

bool seat[100];
int main() {
	int N, a, cnt = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a;
		if (seat[a - 1] == false)
			seat[a - 1] = true;
		else
			cnt++;
		
	}
	cout << cnt << endl;
	return 0;
}
*/