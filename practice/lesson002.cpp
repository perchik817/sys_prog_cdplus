#include "lesson002.h"

bool isTwoDigit(int num) {
	return num / 10 < 10;
}

int reverseNum(int num) {
	return num / 10 + num % 10 * 10;
}

int f(int x) {

	if (isTwoDigit(x)) return reverseNum(x);
	else return x;
}