#include <iostream>

#define MAX 101
using namespace std;

int t;



long long d[101];

void triangle(int num) {
	int start = 10;

	while (start < num) {
		start += 1;
		d[start] = d[start - 1] + d[start - 5];
	}

}

int main(void) {
	d[1] = 1;
	d[2] = 1;
	d[3] = 1;
	d[4] = 2;
	d[5] = 2;
	d[6] = 3;
	d[7] = 4;
	d[8] = 5;
	d[9] = 7;
	d[10] = 9;

	cin >> t;
	for (int i = 0; i < t; i++) {
		int num;
		cin >> num;

		if (num > 10) {
			triangle(num);
			cout << d[num] << "\n";
		}
		else {
			cout << d[num] << "\n";
		}
	}


}