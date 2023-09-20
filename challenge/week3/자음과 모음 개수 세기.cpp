#include <iostream>
using namespace std;

int main() {
	int vowel = 0;
	int consonant = 0;
	cout << "영문자를 입력하고 crtl+z를 치세요" << endl;

	char ch; // 사용자 입력 저장하기 위한 변수
	while (cin >> ch)
	{
		switch (ch)
		{
			//a,e,i,o,u 인경우 break하기
		case 'a': case 'i': case'e':case'o':case'u':
			vowel++; break;
			//나머지는 자음으로 취급
		default:
			consonant++;
			break;
		}
		}
	cout << "모음: " << vowel << endl;
	cout << "자음: " << consonant << endl;
	return 0;
}