/*
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
string num;

void changeNum(int n, int k) {
	while (n  > 0) {
		num  += to_string(n  % k);
		n  /= k;
	}
	reverse(num.begin(), num.end());
}

bool checkPrime(long long n) {
	if (n  == 0 || n  == 1) {
		return false;
	}
	for (int i  = 2; i  <= sqrt(n); i++) {
		if (n  % i  == 0) {
			return false;
		}
	}
	return true;
}

int findAnswer() {
	int answer  = 0;
	string str  = "";
	for (auto c : num) {
		if (c  == '0') {
			if (str.length() == 0) continue;
			if (checkPrime(stol(str)) == true) {
				answer++;
			}
			str  = "";
		}  else {
			str  += c;
		}
	}

	if(str.length() != 0) {
		if (checkPrime(stol(str)) == true) answer++;
	}
	return answer;
}

int solution(int n, int k) {
	int answer  = -1;
	changeNum(n, k);
	answer  = findAnswer();
	return answer;
}

#include <iostream>

int main() {
	cout << solution(437674, 3) << endl;
}
*/