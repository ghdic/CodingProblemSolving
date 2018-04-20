/*
https://www.acmicpc.net/problem/9295

&Title
Dice
&Question
You roll two standard six-sided dice. Given the results of the dice roll, determine its sum.
&Input
The first line of input is the number of test cases that follow.

Each input case appears on a single line, and will be two space-separated integers, each representing the value of one rolled die. All input will be valid.
&Output
For each case, output the line ¡°Case x:¡± where x is the case number, on a single line followed by a single space and the sum of the rolled dice values.
&Example
-input
5
1 2
1 3
3 5
2 6
3 4
-output
Case 1: 3
Case 2: 4
Case 3: 8
Case 4: 8
Case 5: 7
*/

/*
#include <iostream>
using namespace std;

int main() {
	int N, a, b;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		cout << "Case " << i + 1 << ": " << a + b << endl;
	}

	return 0;
}
*/