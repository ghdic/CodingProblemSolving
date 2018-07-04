/*
https://www.acmicpc.net/problem/10698

&Title
10698번 - Ahmed Aly

&Question
Ahmed Aly was the chief judge for the 
last Arab Collegiate Programming Contest, and he will be 
the chief judge for the next one also. He 
was an ACM ICPC world finalist in Oralndo 2011, 
and currently he is a software engineer at Google.During 
the last ACPC contest, it was the first time 
that the chief judge didn’t not attend the contest, 
and this was because his son Omar was expected 
to be born a few days before or after 
the contest (he was born 10 days after the 
contest), so he could not travel to Jordan.Now his 
son Omar is old enough (9 months old) to 
start learning programming. His first program was very simple, 
just a program to add or subtract two numbers, 
and he needs your help to check if his 
program is correct or not. 

&Input
Your program will be tested on one or 
more test cases. The first line of the input 
will be a single integer T, the number of 
test cases (1 ≤ T ≤ 100). Followed by 
T lines, each test case is a single line 
containing an equation in the following format “X O 
Y = Z”, where X, Y and Z are 
positive integers (1 ≤ X,Y,Z ≤ 100) and O 
is either ‘+’ or ‘-’ (without the quotes). 

&Output
For each test case print a single line 
containing “Case n:” (without the quotes) where n is 
the test case number (starting from 1) followed by 
a space then “YES” (without the quotes) if the 
equation is correct or “NO” (without the quotes) if 
the equation is wrong. 

&Example
-input
4
1 + 23 = 22
1 + 22 = 23
22 - 1 = 23
23 - 1 = 22

-output
Case 1: NO
Case 2: YES
Case 3: NO
Case 4: YES


*/


//#define _CRT_SECURE_NO_WARNINGS
//#include <cstdio>
//using namespace std;
//
//int main() {
//	int T;
//	scanf("%d", &T);
//	for (int i = 1; i <= T; i++) {
//		int a, b, c;
//		char n, m;
//		scanf("%d %c %d %c %d", &a, &n, &b, &m, &c);
//		if (n == '+') {
//			printf("Case %d: %s\n", i, (a + b) == c ? "YES" : "NO");
//		}
//		else {
//			printf("Case %d: %s\n", i, (a - b) == c ? "YES" : "NO");
//		}
//	}
//
//	return 0;
//}
