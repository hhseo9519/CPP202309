#include <iostream>
using namespace std;

int main() {
	//변수 선언
	int number;
	//"숫자를 입력하시오"를 출력
	cout << "숫자를 입력하시오";
	//숫자를 입력받기
	cin >> number;
	//number가 1보다 작으면 zero를 출력
	if (number < 1)
		cout << "zero\n";
	//number가 1과 같으면 one을 출력
	else if (number == 1)
		cout << "one\n";
	//나머지는 many를 출력
	else
		cout << "many\n";
	return 0;
}