#include <iostream>
#include "Array.h"

using namespace std;

int main()
{
	Array test_array(10);
	for (size_t i = 0; i < 10; ++i) {
		test_array.Insert(i, i);
	}

	for (int i = 9; i >= 0; --i) {
		cout << "Element " << i << " = " << test_array.GetPosValue(i) << endl;
	}

	return 0;
}