#include <iostream>
using namespace std;
int main() {
	int p = 12; int q = 4; while (q <= p - 4) { if (p == 2 * q) { q++;      break;      cout << " 1: " << p << ' ' << q; }   cout << " 2: " << p << " " << q;   q += 2; } cout << " 3:" << p << ' ' << q;
}