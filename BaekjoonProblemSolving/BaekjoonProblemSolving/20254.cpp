/*
https://www.acmicpc.net/problem/20254

&Title
	20254번 - Site Score출처다국어 

&Question
Teams from variaous universities compete in ICPC regional 
contests for tickets to the ICPC World Finals. The 
number of tickets allocated to every regional contest may 
be different. The allocation method in our super region, 
Asia Pacific, is based on a parameter called site 
score.Site scores will only count teams and universities solving 
at least one problem, in the regional contest or 
its preliminary contest TOPC. In 2020, the formula for 
calculating the site score of the Taipei-Hsinchu regional contest 
is much simpler than past years. LetUR be the 
number of universities solving at least one problem in 
the regional contest.TR be the number of teams solving 
at least one problem in the regional contest.UO be 
the number of universities solving at least one problem 
in TOPC.TO be the number of teams solving at 
least one problem in TOPC.The site score of 2020 
Taipei-Hsinchu regional contest will be 56UR + 24TR + 
14UO + 6TO. Please write a program to compute 
the site score of the 2020 Taipei-Hsinchu regional contest. 


&Input
The input has only one line containing four 
blank-separated positive integers UR, TR, UO, and TO. 

&Output
Output the site score of the 2020 Taipei-Hsinchu 
regional contest. 

&Example
-input
1 1 1 1

-output
100

-input
1 10 100 1000

-output
7696


*/

/*
#include <iostream>
using namespace std;

int ur, tr, uo, to;

int main() {
	ios::sync_with_stdio(false);
	cin >> ur >> tr >> uo >> to;
	cout << 56 * ur + 24 * tr + 14 * uo + 6 * to << endl;
	return 0;
}
*/