/*
https://www.acmicpc.net/problem/5635

&Title
Birthdates
&Question
Write a program to identify the youngest person and the oldest person in a class.
&Input
The number n (1 ≤ n ≤ 100) in the first line determines the number of people in a class.

The following n lines contain person’s name and his/her birthdate.

The information in each line is of this format:

personName dd mm yyyy

where personName is a single word less than 15 letters, dd mm yyyy are date, month and year of the birthdate.

Suppose that no one has the same name or the same birthdate.
&Output
Print out 2 lines containing the name of youngest person and oldest person, respectively.
&Example
-input
5
Mickey 1 10 1991
Alice 30 12 1990
Tom 15 8 1993
Jerry 18 9 1990
Garfield 20 9 1990
-output
Tom
Jerry
*/

/*
#include <iostream>
#include <string>
using namespace std;

int main() {
	int N, year, month, day, unix_time, max_date, min_date; //unix완벽구현 x 그냥 모든달 31일 있는거로 계산
	string name, max_name, min_name;
	const int day_s = 24 * 60 * 60, month_s = 31 * 24 * 60 * 60, year_s = 12 * 31 * 24 * 60 * 60;
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> name >> day >> month >> year;
		unix_time = day * day_s+ month * month_s + (year - 1970) * year_s;
		if (i == 0) {
			max_date = unix_time;
			max_name = name;
			min_date = unix_time;
			min_name = unix_time;
		}
		if (max_date < unix_time) {
			max_date = unix_time;
			max_name = name;
		}
		if (min_date > unix_time) {
			min_date = unix_time;
			min_name = name;
		}
	}
	cout << max_name << "\n" << min_name << endl;
	return 0;
}
*/