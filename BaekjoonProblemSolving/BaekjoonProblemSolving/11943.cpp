/*
https://www.acmicpc.net/problem/11943

&Title
11943�� - ���� �ű��

&Question
�� ���� �ٱ��Ͽ� ����� �������� �ִ�. ù ��° 
�ٱ��Ͽ��� ��� A���� ������ B���� ������ �� ��° �ٱ��Ͽ��� 
��� C���� ������ D���� �ִ�.����� �� �ٱ��Ͽ� �ִ� ���� 
�ϳ��� ��� �ٸ� �ٱ��Ϸ� �ű� �� �ִ�. �̷� ������ 
������ �ű� ��, �� �ٱ��Ͽ��� ����� �ְ� �ϰ� �ٸ� 
�ʿ��� �������� �ְ� �Ϸ��� �Ѵ�.�ռ� ���� ������ �����ϵ��� ������ 
�ű� ��, ������ �ű�� �ּ� Ƚ���� ���ϴ� ���α׷��� �ۼ��Ͽ���. 


&Input
ù ��° �ٿ��� ù ��° �ٱ��Ͽ� �ִ� ����� 
�������� �� A, B�� �־�����. (0 �� A, B 
�� 1,000)�� ��° �ٿ��� �� ��° �ٱ��Ͽ� �ִ� ����� 
�������� �� C, D�� �־�����. (0 �� C, D 
�� 1,000) 

&Output
����� �������� �ű�� �ּ� Ƚ���� ����Ѵ�. 

&Example
-input
1 2
3 4

-output
5


*/

/*
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;

int main() {
	int A, B, C, D, cnt = 0;
	scanf("%d %d %d %d", &A, &B, &C, &D);
	printf("%d\n", (A + D) > (B + C) ? (B + C) : (A + D));
	return 0;
}
*/