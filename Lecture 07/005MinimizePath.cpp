#include<iostream>
#include<cmath>

using namespace std;

int main() {

	int xCount = 0; // to track the net movement along the x-axis
	int yCount = 0; // to track the net movement along the y-axis

	char ch;

	while (true) {

		ch = cin.get();

		if (ch == '\n') {
			break;
		}

		if (ch == 'N') {
			yCount++;
		} else if (ch == 'S') {
			yCount--;
		} else if (ch == 'E') {
			xCount++;
		} else { // ch == 'W'
			xCount--;
		}

	}

	// cout << xCount << " " << yCount << endl;

	if (xCount > 0) {

		// print 'E' xCount times

		for (int i = 1; i <= xCount; i++) {
			cout << 'E';
		}

	}

	if (yCount > 0) {

		// print 'N' yCount times

		for (int i = 1; i <= yCount; i++) {
			cout << 'N';
		}

	}

	if (yCount < 0) {

		// print 'S' abs(yCount) times or -yCount times

		for (int i = 1; i <= -yCount; i++) {
			cout << 'S';
		}

	}

	if (xCount < 0) {

		// print 'W' abs(xCount) times or -xCount times

		for (int i = 1; i <= abs(xCount); i++) {
			cout << 'W';
		}

	}


	return 0;
}