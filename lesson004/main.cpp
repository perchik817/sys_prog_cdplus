#include <iostream>
#include <math.h>

using namespace std;

int main() {
	float b1 = 0.5, b2 = 0.2, bn;
	int n = 10;
	cout << 1 << ". " << b1 << endl;
	cout << 2 << ". " << b2 << endl;
	for (int i = 3; i <= n; i++) {
		bn = pow(b2, 2) + (b1 / i);
		cout << i << ". " << bn << endl;
		b1 = b2;
		b2 = bn;
	}

	return 0;
}