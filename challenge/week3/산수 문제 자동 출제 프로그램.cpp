#include <iostream>
#include <time.h>
using namespace std;

int main() {
	int i;
	int ans;
	cout << "산수 문제를 자동으로 출제합니다." << endl;

	while (true) {
		//firstnum과 secondnum을 생성하는 함수
		int firstnum = rand() % 100;
		int secondnum = rand() % 100;

		cout << firstnum << "+" << secondnum << "=";
		cin >> ans;
		//firstnum과 secondnum을 더한것이 ans와같으면 맞았습니다 출력
		if (firstnum + secondnum == ans) {
			cout << "맞았습니다." << endl;
			break;
		}
		//나머지는 틀렸습니다 출력
		else {
			cout << "틀렸습니다." << endl;
		}
		return 0;
	}
}