/*
https://www.acmicpc.net/problem/18301

&Title
	18301번 - Rats출처다국어 

&Question
To celebrate the Lunar New Year of the 
Rat, Douglas decides to count the number of rats 
living in his area. It is impossible for him 
to find all rats, as they tend to be 
well hidden. However, on the first day of the 
new year, Douglas manages to capture n1 rats, and 
marks each of them with an ear tag before 
releasing them. On the second day of the new 
year, Douglas captures n2 rats, and observes that n12 
of them had been marked during the first day.Douglas 
is asking for your help to estimate the total 
number of rats in his area. Looking up in 
your statistics textbook, you propose using the Chapman estimator 
N, given by:N := ⌊(n1 + 1)(n2 + 1)/(n12 
+ 1) - 1⌋where ⌊x⌋ is the floor of 
a real number x, i.e., the closest integer less 
than or equal to x. 

&Input
The input consists of a single line, with 
three space-separated integers: n1, n2, n12, in that order. 


&Output
The output should contain a single line with 
the single integer N. 

&Example
-input
15 18 11

-output
24


*/

/*
#include <iostream>
using namespace std;

int n1, n2, n12;

int main() {
	ios::sync_with_stdio(false);
	cin >> n1 >> n2 >> n12;
	cout << (n1 + 1) * (n2 + 1) / (n12 + 1) - 1 << endl;
	return 0;
}
*/