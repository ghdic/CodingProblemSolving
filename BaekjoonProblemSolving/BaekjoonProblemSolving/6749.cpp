/*
https://www.acmicpc.net/problem/6749

&Title
	6749번 - Next in line출처다국어 

&Question
You know a family with three children. Their 
ages form an arithmetic sequence: the difference in ages 
between the middle child and youngest child is the 
same as the difference in ages between the oldest 
child and the middle child. For example, their ages 
could be 5, 10 and 15, since both adjacent 
pairs have a difference of 5 years.Given the ages 
of the youngest and middle children, what is the 
age of the oldest child? 

&Input
The input consists of two integers, each on 
a separate line. The first line is the age 
Y of the youngest child (0 ≤ Y ≤ 
50). The second line is the age M of 
the middle child (Y ≤ M ≤ 50). 

&Output
The output will be the age of the 
oldest child. 

&Example
-input
12
15

-output
18


*/

/*
#include <iostream>
using namespace std;

int a, b;

int main() {
	ios::sync_with_stdio(false);
	cin >> a >> b;
	cout << b + b - a << endl;
	return 0;
}
*/