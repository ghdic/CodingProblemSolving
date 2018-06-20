/*
https://www.acmicpc.net/problem/11383

&Title
11383번 - 뚊

&Question
정우는 "뚊"과 "돌돔"을 의미하는 두 이미지를 받았다. 과연 
두 그림이 같은지 검사해보자. 즉 N× M 크기의 이미지와 
N ×2 M 크기의 이미지가 주어질 때 첫 번째 
이미지를 가로로 두 배로 늘이면 두 번째 이미지가 되는지 
검사하는 프로그램을 작성하라. 

&Input
입력의 첫 번째 줄에 N, M (1 ≤ 
N, M ≤ 10)이 주어진다. 다음 N개의 줄의 각 
줄에는 M개의 문자가 주어진다. 다음 N개의 줄의 각 줄에는 
2M개의 문자가 주어진다. 모든 문자는 영문 알파벳 대문자 혹은 
소문자이다. 

&Output
첫 번째로 주어진 이미지를 가로로 두 배로 늘렸을 
때 두 번째 이미지가 된다면 "Eyfa"을 출력하고, 되지 않는다면 
"Not Eyfa"을 출력한다. 

&Example
-input
1 5
ABCDE
AABBCCDDEE

-output
Eyfa

-input
1 5
ABCDE
AABBCCDDEF

-output
Not Eyfa

-input
2 2
AB
CD
AABB
CCDD

-output
Eyfa


*/


//#define _CRT_SECURE_NO_WARNINGS
//#include <cstdio>
//using namespace std;
//
//int main() {
//	int a, b;
//	scanf("%d %d", &a, &b);
//	char s[10][10];
//	for (int i = 0; i < a; i++) {
//		scanf(" %s", s[i]);
//	}
//	char result[10][20];
//	for (int i = 0; i < a; i++) {
//		scanf(" %s", result[i]);
//	}
//	bool check = true;
//	for (int i = 0; i < a; i++) {
//		for (int j = 0; j < b; j++) {
//			if (!(s[i][j] == result[i][j * 2] && s[i][j] == result[i][j * 2 + 1])) {
//				check = false;
//				break;
//			}
//		}
//		if (!check)break;
//	}
//
//	printf("%s\n", check ? "Eyfa" : "Not Eyfa");
//	return 0;
//}
