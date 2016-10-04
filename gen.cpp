#include <iostream>

using namespace std;

int main() {
	int handlers = 48;
	for (int i = 0; i < handlers; i++) {
		cout << "new";
		if (i == 8 || (10 <= i && i <= 14) || i == 17)
			cout << "Err";
		cout << "Handler(" << i << ")\n";
	}
	for (int i = 0; i < handlers; i++)
		cout << "	.quad handler" << i << '\n';
}