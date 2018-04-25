/*
https://www.acmicpc.net/problem/3040

&Title
3040�� - �鼳 ���ֿ� �ϰ� �����̽���� ����

&Question
���� ���� �ϰ� �����̴� �������� ���� �Ϸ� ����. 
�����̰� ���� �ϴ� ���� �鼳���ִ� �׵��� ���� ���� �Ļ縦 
�غ��Ѵ�. �鼳���ִ� ���� �ϰ���, ���� �ϰ���, ������ �ϰ����� �غ��Ѵ�. 
����� ���꿡�� ��ȩ �����̰� ���ƿԴ�. (�� �׸��� ��� ��ȩ 
�����̰� ���ƿԴ����� �ƹ��� �𸥴�) ��ȩ �����̴� ���� �ڽ��� �鼳������ 
�ϰ� �����̶�� ���� �ִ�. �鼳���ִ� �̷� ���� ���� ���� 
����ؼ�, �����̰� ���� �ٴϴ� ���ڿ� 100���� ���� ���� ������ 
���� ���Ҵ�. ��� �鼳 ���ִ� ���ְ� �Ǳ� ���� �ſ� 
������ �����ڿ���. ����, �ϰ� �������� ���ڿ� �� �ִ� ������ 
���� 100�� �ǵ��� ���� ���Ҵ�. ��ȩ �������� ���ڿ� �� 
�ִ� ���� �־����� ��, �ϰ� �����̸� ã�� ���α׷��� �ۼ��Ͻÿ�. 
(��ȩ ���� �� �� ���� 100�� �Ǵ� �ϰ� ���� 
���� ã���ÿ�) 

&Input
�� ��ȩ�� �ٿ� 1���� ũ�ų� ���� 99���� �۰ų� 
���� �ڿ����� �־�����. ��� ���ڴ� ���� �ٸ���. ��, �׻� 
���� ������ ��츸 �Է����� �־�����. 

&Output
�ϰ� �����̰� �� ���ڿ� �� �ִ� ���� �� 
�ٿ� �ϳ��� ����Ѵ�. 

&Example
-input
7
8
10
13
15
19
20
23
25

-output
7
8
10
13
19
20
23


*/

/*
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int arr[9];
	for (int i = 0; i < 9; i++)
		cin >> arr[i];
	sort(arr, arr + 9);

	int a = 0, b = 1;
	for (int i = 0; i < 36; i++) {
		int sum = 0;
		b++;
		if (b % 9 == 0) {
			a++;
			b = a + 1;
		}
		for (int j = 0; j < 9; j++) {
			if (j == a || j == b)continue;
			else sum += arr[j];
		}
		if (sum == 100)break;
	}

	for (int i = 0; i < 9; i++) {
		if (i == a || i == b)continue;
		else cout << arr[i] << endl;
	}
	return 0;
}
*/