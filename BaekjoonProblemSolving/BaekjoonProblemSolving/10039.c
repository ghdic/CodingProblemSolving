/*
https://www.acmicpc.net/problem/10039

&Title
��� ����

&Question
�����̰� ����ġ�� ������ �� ���� ������ �������� ����, ����, ���, ��, �����̴�.

���� �� ������ �⸻���簡 �־���, �����̴� ���� �л����� �⸻���� �������� ä���ϰ� �ִ�. �⸻���� ������ 40�� �̻��� �л����� �� ���� �״�� �ڽ��� ������ �ȴ�. ������, 40�� �̸��� �л����� �����н��� ��� ������ �����ϸ� 40���� �ް� �ȴ�. �����н��� �ź��� �� ���� ������, 40�� �̸��� �л����� �׻� 40���� �ް� �ȴ�.
�л� 5���� ������ �־����� ��, ��� ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

&Input
�Է��� �� 5�ٷ� �̷���� �ְ�, �������� ����, ������ ����, ������� ����, ������ ����, ������ ������ ������� �־�����.

������ ��� 0�� �̻�, 100�� ������ 5�� ����̴�. ����, ��� ������ �׻� �����̴�.

&Output
ù° �ٿ� �л� 5���� ��� ������ ����Ѵ�.

&Example
-input
10
65
100
30
95
-output
68

*/

/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int student[5], sum=0;

	for (int i = 0; i < 5; i++) {
		scanf("%d", &student[i]);
		if (student[i] < 40)
			student[i] = 40;
		sum += student[i];
	}

	printf("%d\n", sum / 5);
	return 0;
}
*/