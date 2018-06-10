/*
https://www.acmicpc.net/problem/11104

&Title
11104번 - Fridge of Your Dreams

&Question
Eirik drinks a lot of Bingo Cola to 
help him program faster, and over the years he 
has burned many unnecessary calories walking all the way 
to the kitchen to get some. To avoid this 
he has just bought a small fridge, which is 
beautifully placed next to his computer. To make it 
match his fancy big-tower with all its blinking LEDs, 
it is necessary to style it a bit.He has 
bought a weight sensor with a display and a 
small general purpose programmable chip, to put underneath the 
fridge. The idea is to make the display show 
how many litres of Bingo Cola there is in 
the fridge. To do this he must read a 
binary register in the sensor, and convert it to 
a decimal number to be displayed. 

&Input
The first line of input gives n ≤ 
1000, the number of test cases. Then follow n 
lines with positive numbers represented as 24-bit binary strings 
(0s and 1s). 

&Output
For each number, output its decimal representation, without 
any leading zeros. 

&Example
-input
5
000000000000000000000001
000000000001010101010101
000000000000000000001010
101011001010101100101101
111111111111111111111111

-output
1
5461
10
11316013
16777215


*/

/*
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;

int main() {
	int N;
	scanf("%d", &N);
	while (N--) {
		char s[25];
		scanf("%s", s);
		int result = 0;
		for (int i = 0; i < 24; i++) {
			result = 2 * result + (s[i]-'0');
		}
		printf("%d\n", result);
	}
	return 0;
}
*/