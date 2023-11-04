#include <iostream>
using namespace std;

int main() {
	//변수 선언
	int choice;
	//화면에 아래와 같이 출력
	cout << "1.파일저장" << endl;
	cout << "2. 저장 없이 닫기" << endl;
	cout << "3. 종료" << endl;
	cin >> choice;
	//choice가 1이면 파일저장을 선택했습니다를 출력
	if (choice == 1)
		cout << "파일 저장을 선택했습니다." << endl;
	//1이 아닐때 choice가 2라면 파일닫기를 선택했습니다를 출력
	else if (choice == 2)
		cout << "파일 닫기를 선택했습니다." << endl;
	//1,2가 아닐 떄 choice가 3이라면 프로그램을 종료합니다를 출력
	else if (choice == 3)
		cout << "프로그램을 종료합니다." << endl;
	//나머지는 잘못된 선택입니다를 출력
	else
		cout << " 잘못된 선택입니다." << endl;
	return 0;
}