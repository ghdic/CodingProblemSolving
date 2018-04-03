#include <iostream>
#include <cstdio>
using namespace std;

int main() {
	// Complete the code.
	int a;
	long b; //32bit -> 4byte, 64bit -> 8byte
	char c;
	float d;
	double e;

	cin >> a >> b >> c >> d >> e;
	printf("%d\n%ld\n%c\n%.2f\n%.9lf\n", a, b, c, d, e);
	return 0;
}
