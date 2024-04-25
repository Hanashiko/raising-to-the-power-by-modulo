#include <iostream>
#include <cmath>

using namespace std;

long long Mod(string num, long long mod) {
	long long number = 0;
	for (long long i = 0; i < num.length(); i++) {
		number = (number * 10 + (num[i] - '0'));
		number %= mod;
	}
	return number;
}

long long PowMod(string& a, string& b, long long m) {
	long long result = 1;
	long long x = Mod(a, m);
	long long y = Mod(b, m);

	while (y) {
		if (y & 1) result = (result * x) % m;
		y = y >> 1;
		x = ((x % m) * (x % m)) % m;
	}
	return (result % m + m) % m;
}

int main() {
	string a, b;
	cin >> a;
	cin >> b;
	long long m = 1000000007;
	cout << PowMod(a, b, m);
	return 0;
}
