#include <iostream>
#include <string>
using namespace std;
//문자열을 소문자로 바꾸는 함수 생성 (tolower함수 사용)
string toLowerStr(string str) {
	string newstr = str;
	for (char& c : newstr) {
		c=tolower(c)
	}
	return newstr;
}
//문자열을 대문자로 바꾸는 함수 생성 (toupper함수 사용)
string toUpperStr(string str) {
	string newstr = str;
	for (char& c : newstr) {
		c = toupper(c)
	}
	return newstr;
}
//두 문자열을 소문자로 바꾸고 해밍거리를 계산하는 함수를 생성
int calcHammingdist(string s1, string s2) {
	s1 = toLowerstr(s1);
	s2 = toLowerstr(s2);
	int count = 0;
	for (int i = 0; i < s1.length(); i++) {
		if (s1[i] != s2[i])
			count += 1;
	}
	return 0;
}

int main() {
	string s1, s2;
	//계속 반복하는 while 문을 사용하여 문자열을 입력받고
	while (true) {
		cout << "DNA1: ";
		cin >> s1;
		cout << "DNA2: ";
		cin >> s2;
		//길이가 다르다면 오류를 출력, 길이가 같다면 해밍거리 계산후 해밍거리 출력
		if (s1.length() != s2.length()) {
			cout << "오류: 길이가 다름" << endl;
			continue;
		}
		else {
			int count = calcHammingdist(s1, s2);
			cout << "해밍 거리는 " << count << endl;
			break;
		}
	}
	return 0;
}