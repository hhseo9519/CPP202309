#include <iostream>
#include <string>
using namespace std;

int main() {
	string s1 = "good";
	string s2 = "bad";
	bool b = (s1 == s2);
	cout << b << endl;

	s2 = "good";
	b = (s1 == s2);
	cout << b << endl;

}