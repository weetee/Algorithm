#include "SingleList.h"
#include <iostream>

using namespace std;

int main()
{
	SingleList my_singlelist;
	cout << "current size = " << my_singlelist.GetSize() << endl;
	my_singlelist.Print();

	int val;
	while (cin >> val && val != 0) {
		my_singlelist.Insert(0, val); // 在表头插入数据
	}

	cout << "now size = " << my_singlelist.GetSize() << endl;
	my_singlelist.Print();

	while (cin >> val && val != 0) {
		int pos = my_singlelist.FindValuePos(val);
		cout << "value: " << val << " position = " << pos << endl;
	}

	while (cin >> val && val != 0) {
		my_singlelist.Remove(val);
		my_singlelist.Print();
	}

	cout << endl;
	my_singlelist.Reverse();
	my_singlelist.Print();

	return 0;
}