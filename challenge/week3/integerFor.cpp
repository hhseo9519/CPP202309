#include<iostream>
using namespace std;

int main() {
	int userInput;

	cout << "정수를 10번 입력하세요 (0을 입력하면 종료):";
	// i=0 에서 시작해서 i<10이라면 아래 cout 수행 후 i에 1을 더하고 다시 i와 10을 비교
	for (int i = 0; i < 10; i++) {
		cin >> userInput;
		if (userInput == 0) {
			break;
		}
		cout << "입력값:" << userInput << "횟수 :" << i << endl;
	}
	cout << "종료 되었습니다";
	return 0;
}