/*
https://www.acmicpc.net/problem/2921

&Title
���̳�
&Question
���̳�� ���� ������ Ÿ�� ���ӿ��� ����ϴ� �����̴�. ���̳� �������� �� ĭ���� �̷���� �ִ�. �� ĭ���� ���� �����ִµ�, ���� �� ������ ���� ���� �ִ�. ���� ������ ��Ʈ�� ũ�⿡ ���ؼ� �����ȴ�. ��Ʈ�� ũ�Ⱑ N�� ���̳� ��Ʈ���� ���� ������ 0���� ũ�ų� ����, N���� �۰ų� ����. �� ���̳뿡 �����մ� ���� ������ ���ٸ�, �� ���̳�� ������ ���̴�. ���� ���, ���� 2���� 8�� �����ִ� ���̳�� 8���� 2�� �����ִ� ���̳�� ���� ���̳��̴�.
ũ�Ⱑ N�� ���̳� ��Ʈ�� N �Ǵ� �׺��� �۰ų� ���� ���� �����ϴ� ������ ���̳븦 ��� �����ϰ� �ְ�, �� ���̳�� �ߺ����� �ʴ´�. ������ ũ�Ⱑ 2�� ���̳� ��Ʈ�̴�.



N�� �Է¹��� ��, ũ�Ⱑ N�� ���̳� ��Ʈ���� ���� �� �� ���� �ִ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
&Input
ù° �ٿ� ���̳� ��Ʈ�� ũ�� N (1 �� N �� 1000)�� �־�����.
&Output
ũ�Ⱑ N�� ���̳� ��Ʈ�� �����ִ� ���� ������ ����Ѵ�.
&Example
-input
2
-output
12
*/

/*
#include <iostream>
using namespace std;

int main() {
	int N, sum = 0;
	cin >> N;
	for (int i = 0; i <= N; i++) {
		sum += i * (i + 1) * 3 / 2;
	}
	cout << sum << endl;
	return 0;
}
*/