#include<iostream>
using namespace std;

int main() {
	//변수 선언
	int userInput;
	//정수를 입력받기
	cout << "정수를 10번 입력하세요 (0을 입력하면 종료):";
	// 조건문에 따른 for문 실행
	for (int i = 0; i < 10; i++) {
		cin >> userInput;
		if (userInput == 0) {
			break;
		}
		//최종으로 입력값과 횟수 출력
		cout << "입력값:" << userInput << "횟수 :" << i << endl;
	}
	cout << "종료 되었습니다";
	return 0;
}