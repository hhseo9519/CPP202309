#include <iostream>
#include <string>
using namespace std;

string toLowerStr(string str) {
	for (char i = 0; i = str.length(); i++) {
		str[i] = tolower(str[i]);
	
	}
	return str;
}
string toUpperStr(string str) {
	for (char i = 0; i = str.length(); i++) {
		str[i] = toupper(str[i]);
	
	}
	return str;
}

int calcHammingdist(string s1, string s2) {
	int count = 0;
	string S1,S2;
	cout << "s1 = ";
	cin >> S1;
	cout << "s2 = ";
	cin >> S2;
	S1 = toUpperStr(S1);
	S2 = toUpperStr(S2);
	if (S1.length() != S2.length())
		cout << "오류: 길이가 다름" << endl;
	else {
		for (int i = 0; i < S1.length(); i++) {
			if (S1[i] != S2[i])
				count += 1;
		}
		cout << " 해밍 거리는 " << count << endl;
	}
	return 0;
}