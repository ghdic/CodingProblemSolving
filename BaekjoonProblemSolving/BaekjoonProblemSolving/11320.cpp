/*
https://www.acmicpc.net/problem/11320

&Title
11320번 - 삼각 무늬 - 1

&Question
무엇이든 덮어버리는 것을 좋아하는 구사과는 한변의 길이가 A인 
정삼각형을 한변의 길이가 B인 정삼각형으로 완전히 덮어 버리고자 한다.두개의 
정수 A, B 가 주어지고, B ≤ A 이고, 
A를 B로 나눌수 있을때, 한 변의 길이가 A인 정삼각형을 
완전하게 덮기 위한, 한변의 길이가 B인 정삼각형의 개수를 구하라. 


&Input
첫째 줄에 테스트 케이스의 개수 T가 주어진다. (T 
≤ 100)각각의 테스트 케이스는 한줄로 이루어져 있으며 두개의 정수 
A, B가 (1 ≤ B ≤ A ≤ 1,000, 
B|A) 주어진다. 

&Output
각 테스트 케이스마다 한변의 길이가 A인 정삼각형을 완벽하게 
덮을 수 있는 한변의 길이가 B인 정삼각형의 최소 개수를 
출력한다. 

&Example
-input
2
2 1
3 3

-output
4
1


*/


//#define _CRT_SECURE_NO_WARNINGS
//#include <cstdio>
//using namespace std;
//
//int main() {
//	int T, a, b;
//	scanf("%d", &T);
//	while (T--) {
//		scanf("%d %d", &a, &b);
//		int div = a % b == 0 ? a / b : a / b + 1;
//		int sum = 0;
//		int inc = 1;
//		for (int i = 1; i <= div; i++) {
//			sum += inc;
//			inc += 2;
//		}
//		printf("%d\n", sum);
//	}
//
//	return 0;
//}
