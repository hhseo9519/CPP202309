#include <iostream>
using namespace std;

int main() {
	int choice;
	//아래의 choice들을 출력
	cout << "1. 파일저장" << endl;
	cout << "2. 저장 없이 닫기" << endl;
	cout << "3. 종료" << endl;
	cin >> choice;
	//switch문을 사용하여 아래 4개중 사용자가 하나를 선택할 시 cout로 문장을 출력하고 종료
	switch (choice) {
	case 1:
		cout << "파일 저장을 선택했습니다." << endl;
		break;
	case 2:
		cout << "파일 닫기를 선택했습니다." << endl;
		break;
	case 3:
		cout << "프로그램을 종료합니다." << endl;
		break;
	default:
		cout << "잘못된 선택입니다." << endl;
		break;

	}
	return 0;
}