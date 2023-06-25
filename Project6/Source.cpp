#include <iostream>
#include <cmath>
using namespace std;

int gcd(int a, int b) {
	if (a == 0)
		return b;
	else
		return gcd(b % a, a);
}

int main() {
	setlocale(LC_ALL, "RU");
	int p = 19;
	int q = 5;
	int n = p * q;
	int phi = (p - 1) * (q - 1);
	int e, d;
	for (int i = 2; i < phi; i++) {
		if (gcd(i, phi) == 1) {
			e = i;
			break;
		}
	}
	for (int i = 1; i < phi; i++) {
		if ((i * e) % phi == 1) {
			d = i;
			break;
		}
	}
	cout << "Открытый ключ: (" << e << ", " << n << ")" << endl;
	cout << "Закрытый ключ: (" << d << ", " << n << ")" << endl;

	int msg;
	cout << "Введите сообщение для шифрования: ";
	cin >> msg;

	int c = pow(msg, e);
	c = c % n;

	int decrypted_msg = pow(c, d);
	decrypted_msg = decrypted_msg % n;

	cout << "Зашифрованное сообщение: " << c << endl;
	cout << "Расшифрованное сообщение: " << decrypted_msg << endl;

	return 0;
}