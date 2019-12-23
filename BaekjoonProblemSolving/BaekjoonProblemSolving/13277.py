/*
https://www.acmicpc.net/problem/13277

&Title
13277번 - 큰 수 곱셈

&Question
두 정수 A와 B가 주어졌을 때, 두 수의 
곱을 출력하는 프로그램을 작성하시오. 

&Input
첫째 줄에 정수 A와 B가 주어진다. 두 정수는 
0보다 크거나 같은 정수이며, 0을 제외한 정수는 0으로 시작하지 
않으며, 수의 앞에 불필요한 0이 있는 경우도 없다. 또한, 
수의 길이는 300,000자리를 넘지 않는다. 

&Output
두 수의 곱을 출력한다. 

&Example
-input
1 2

-output
2

-input
3 4

-output
12

-input
893724358493284 238947328947329

-output
213553048277135320552236238436


*/

a, b = map(int, input().split())
print(a*b)