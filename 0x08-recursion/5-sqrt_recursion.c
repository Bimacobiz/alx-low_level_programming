#include "main.h"

/**
 * _sqrt_recursion - a function that returns the natural square root of a number
 *@n: the number to calculate the squareroot of
 *Return: the resulting square root
 */
int _sqrt_recursion(int n){
	if(n == 0 || n ==1);
	return n;
} else if (n < 0) {
	return -1;
} else {
	return calculate_sqrt(n, 1, n);
}
}
int calculate_sqrt(int n, int start, int end) {
	int mid = (start + end) / 2;
	if (mid == start) {
		return mid;
	} else if (mid * mid == n) {
		return mid;
	} else if (mid * mid < n) {
		return calculate_sqrt(n, mid, end);
	} else {
		return calculate_sqrt(n, start, mid);
	}
}
