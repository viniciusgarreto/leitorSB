#include <iostream>

using namespace std;

ostream& indentBy(unsigned int n, ostream& out) {
	for (int i = 0; i < n; i++) out << "\t";
	return out;
}
