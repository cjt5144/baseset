/*
Compile With:
-------------
g++ -std=c++11 basesettest.cpp baseset.cpp -o test
*/

#include "baseset.h"
#include <iostream>

int main() {
	using std::cout;
	using std::endl;
	
	std::cout << ct::itoc(0) << std::endl; // 0
	std::cout << ct::itoc(9) << std::endl; // 9
	std::cout << ct::itoc(10) << std::endl; // A
	std::cout << ct::itoc(35) << std::endl; // Z
	std::cout << ct::itoc(36) << std::endl; // a
	std::cout << ct::itoc(61) << std::endl; // z
	std::cout << ct::itoc(62) << std::endl; // null
	
	cout << ct::ctoi('/') << endl;
	cout << ct::ctoi('0') << endl;
	cout << ct::ctoi('9') << endl;
	cout << ct::ctoi(':') << endl;
	cout << ct::ctoi('@') << endl;
	cout << ct::ctoi('A') << endl;
	cout << ct::ctoi('Z') << endl;
	cout << ct::ctoi('[') << endl;
	cout << ct::ctoi('`') << endl;
	cout << ct::ctoi('a') << endl;
	cout << ct::ctoi('z') << endl;
	cout << ct::ctoi('{') << endl;
	
	cout << ct::digitsForBase(9, 10) << endl;
	cout << ct::digitsForBase(10, 10) << endl;
	cout << ct::digitsForBase(99, 10) << endl;
	cout << ct::digitsForBase(100, 10) << endl;
	cout << ct::digitsForBase(7, 2) << endl;
	cout << ct::digitsForBase(8, 2) << endl;
	
	ct::Baseset bs1 = ct::Baseset(9);
	ct::Baseset bs4 = ct::Baseset(10);
	ct::Baseset bs2 = ct::Baseset(7, 2);
	ct::Baseset bs3 = ct::Baseset(8, 2);
	
	return 0;
}
