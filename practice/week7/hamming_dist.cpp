#include <iostream>
#include <string>
using namespace std;

int main() {
	//변수 s1과 s2선언
	string s1, s2;
	int count = 0;
	//s1과 s2에 입력받은 문자열을 할당
	cout << "DNA!: ";
	cin >> s1;
	cout << "DNA2 : ";
	cin >> s2;
	// 만약 s1의 길이가 s2의 길이와 다르다면 오류를 출력
	if (s1.length() != s2.length())
		cout << "오류: 길이가 다름" << endl;
	//s1과s2의 길이가 다르지 않다면 해밍거리를 계산하여 출력
	else {
		for (int i = 0; i < s1.length(); i++) {
			if (s1[i] != s2[i])
				count += 1;
		}
		cout << " 해밍 거리는 " << count << endl;
	}
	return 0;
}
