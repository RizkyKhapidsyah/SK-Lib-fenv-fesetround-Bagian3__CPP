#include <iostream>
#include <cmath>
#include <cfenv>
#include <conio.h>

#pragma STDC FENV_ACCESS ON

/*	Source by Programmiz
*	Modified by Rizky Khapidsyah
*/

using namespace std;

void print_current_rounding_direction() {
	cout << "Current rounding method: ";

	switch (fegetround()) {
	case FE_TONEAREST:
		cout << "FE_TONEAREST";
		break;
	case FE_DOWNWARD:
		cout << "FE_DOWNWARD";
		break;
	case FE_UPWARD:
		cout << "FE_UPWARD";
		break;
	case FE_TOWARDZERO:
		cout << "FE_TOWARDZERO";
		break;
	default:
		cout << "unknown";
	};
	
	cout << endl;
}

int main() {
	print_current_rounding_direction();
	cout << "6.2 -> " << rint(6.2) << endl;
	cout << "18.7 -> " << rint(18.7) << endl;

	fesetround(FE_UPWARD);
	print_current_rounding_direction();
	cout << "6.2 -> " << rint(6.2) << endl;
	cout << "19.7 -> " << rint(19.7) << endl;

	fesetround(FE_DOWNWARD);
	print_current_rounding_direction();
	cout << "6.2 -> " << rint(6.2) << endl;
	cout << "19.7 -> " << rint(19.7) << endl;

	_getch();
	return 0;
}