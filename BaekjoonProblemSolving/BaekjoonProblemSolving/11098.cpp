/*
https://www.acmicpc.net/problem/11098

&Title
Help Chelsea!
&Question
When football clubs achieve poor results, there is only one thing to do: Buy new players! This is the most popular strategy among the major football clubs in Europe today, and Rosenborg is an example of a Norwegian club which has used this strategy with success. They have many talent scouts travelling around the earth to find promising young footballers.

Chelsea struggles in Premier League at the moment, and they have decided to buy another player. But they are sick and tired of waiting around for a talent scout to find a descent player, and employ a way more efficient strategy. They actually put a famous saying from B©¡rum into practice: ¡°If something is on sale, you can be sure there is a reason why.¡±

In a football setting, this means that the most expensive player is probably the best one. Hence, looking for a new player only involves calling all football clubs and asking for their most expensive player. Your task is to help Chelsea find the most expensive player from a list.
&Input
The input has n ¡Â 100 cases, where n is given by the first line of input. The first line of each test case is a single positive integer, p ¡Â 100, giving the number of players to consider. Then follow p lines, where each line represents a player. The line starts with a positive integer ci < 2 ¡¤ 109, the price of player i. Then follows a single space before the name of the player. All player prices are unique. Player names are never more than 20 characters long, and contain no spaces.
&Output
For each test case your program should output a single line giving the name of the most expensive player.
&Example
-input
2
3
10 Iversen
1000000 Nannskog
2000000 Ronaldinho
2
1000000 Maradona
999999 Batistuta
-output
Ronaldinho
Maradona
*/

/*
#include <iostream>
#include <string>
using namespace std;

int main() {
	int N, price, max_price = 0;
	string name, max_name;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int p;
		max_name.clear();
		max_price = 0;
		cin >> p;
		for (int j = 0; j < p; j++) {
			cin >> price >> name;
			if (max_price < price) {
				max_price = price;
				max_name = name;
			}
		}
		cout << max_name << endl;
	}
	return 0;
}
*/