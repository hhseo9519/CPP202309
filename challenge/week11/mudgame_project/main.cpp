#include <iostream>
#include <string>
#include "user.h"
using namespace std;

const int mapX = 5;
const int mapY = 5;
int HP = 20;
// 게임 구현에 필요한 함수 선언
bool checkXY(int user_x, int mapX, int user_y, int mapY);
void displayMap(int map[][mapX], int user_x, int user_y);
bool checkGoal(int map[][mapX], int user_x, int user_y);
void checkState(int map[][mapX], int user_x, int user_y,User& myHP);
bool checkUser(User user);
// 메인  함수
int main() {
	// 게임에 필요한 2차원 배열 정의
	//0 = 빈공간,  2 = 적, 3 = 포션, 4 = 목적지 
	int map[mapY][mapX] = { {0, 0, 2, 0, 4},
					{0, 0, 0, 2, 0},
					{0, 0, 0, 0, 0},
					{0, 2, 3, 0, 0},
					{3, 0, 0, 0, 2} };
	//클래스 선언
	//생성자를 hp=20으로 초기화
	User myHP{ 20 };

	// 유저의 위치를 저장할 변수
	int user_x = 0; // 가로 번호
	int user_y = 0; // 세로 번호



	// 게임 시작
	while (1) { // 사용자에게 계속 입력받기 위해 무한 루프

		// 사용자의 입력을 저장할 변수
		string user_input = "";
		cout << "현재 체력은 :" << myHP.GetHP() << endl;
		cout << "명령어를 입력하세요 (상,하,좌,우,지도,종료): ";
		cin >> user_input;


		if (user_input == "상") {
			// 위로 한 칸 올라가기
			user_y -= 1;
			bool inMap = checkXY(user_x, mapX, user_y, mapY);
			if (inMap == false) {
				cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
				user_y += 1;
			}
			else {
				cout << "위로 한 칸 올라갑니다." << endl;
				displayMap(map, user_x, user_y);
				myHP.useHP();
			}
		}
		else if (user_input == "하") {
			// 아래로 한 칸 내려가기
			user_y += 1;
			bool inMap = checkXY(user_x, mapX, user_y, mapY);
			if (inMap == false) {
				cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
				user_y -= 1;
			}
			else {
				cout << "아래로 한 칸 내려갑니다." << endl;
				displayMap(map, user_x, user_y);
				myHP.useHP();
			}
		}
		else if (user_input == "좌") {
			// 왼쪽으로 이동하기
			user_x -= 1;
			bool inMap = checkXY(user_x, mapX, user_y, mapY);

			if (inMap == false) {
				cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
				user_x += 1;
			}
			else {
				cout << "왼쪽으로 이동합니다." << endl;
				displayMap(map, user_x, user_y);
				myHP.useHP();
			}
		}
		else if (user_input == "우") {
			// 오른쪽으로 이동하기
			user_x += 1;
			bool inMap = checkXY(user_x, mapX, user_y, mapY);
			if (inMap == false) {
				cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
				user_x -= 1;
			}
			else {
				cout << "오른쪽으로 이동합니다." << endl;
				displayMap(map, user_x, user_y);
				myHP.useHP();
			}
		}
		else if (user_input == "지도") {
			// 지도 보여주기 함수 호출
			displayMap(map, user_x, user_y);
		}
		else if (user_input == "종료") {
			cout << "종료합니다.";
			break;
		}
		else {
			cout << "잘못된 입력입니다." << endl;
			continue;
		}
		//체력에 관한 제약
		checkState(map, user_x, user_y,myHP);

		// 목적지 도달 확인 하는 함수
		bool finish = checkGoal(map, user_x, user_y);
		if (finish == true) {
			cout << "목적지에 도착했습니다! 축하합니다!" << endl;
			cout << "게임을 종료합니다." << endl;
			break;
		}
		//HP가 0이되면 종료-->checkUser 함수 생성
		if (checkUser(myHP) == false)
		{
			break;
		}

	}
	return 0;
}


// 사용자 위치가 포함된 지도를 출력하는 함수
void displayMap(int map[][mapX], int user_x, int user_y) {
	for (int i = 0; i < mapY; i++) {
		for (int j = 0; j < mapX; j++) {
			if (i == user_y && j == user_x) {
				cout << " USER |"; // 양 옆 1칸 공백
			}
			else {
				int posState = map[i][j];
				switch (posState) {
				case 0:
					cout << "      |"; // 6칸 공백
					break;

				case 2:
					cout << "  적  |"; // 양 옆 2칸 공백
					break;
				case 3:
					cout << " 포션 |"; // 양 옆 1칸 공백
					break;
				case 4:
					cout << "목적지|";
					break;
				}
			}
		}
		cout << endl;
		cout << " -------------------------------- " << endl;
	}
}

// 이동가능한 칸인지 체크하는 함수
bool checkXY(int user_x, int mapX, int user_y, int mapY) {
	bool checkFlag = false;
	if (user_x >= 0 && user_x < mapX && user_y >= 0 && user_y < mapY) {
		checkFlag = true;
	}
	return checkFlag;
}

// 유저의 위치가 목적지에 도달하였는지 체크하는 함수
bool checkGoal(int map[][mapX], int user_x, int user_y) {
	// 목적지에 도착하게 되면 실행
	if (map[user_y][user_x] == 4) {
		return true;
	}
	return false;
}
//적을 만난경우와 포션을 만난경우의 유저의 HP 변경을 나타내는 함수
void checkState(int map[][mapX], int user_x, int user_y, User& myHP) {
	//적을 만난 경우
	if (user_y == 0 && user_x == 2 || user_y == 1 && user_x == 3 || user_y == 3 && user_x == 1 ||
		user_y == 4 && user_x == 4) {
		cout << "적을 만났습니다. HP가 2 줄어듭니다" << endl;
		myHP.DecreaseHP();
	}
	// 포션을 만난경우
	else if (user_y == 3 && user_x == 2 || user_y == 4 && user_x == 0) {
		cout << "포션을 만났습니다. HP가 2 늘어납니다" << endl;
		myHP.IncreaseHP();
	}



}
bool checkUser(User user) {
	if (user.GetHP() <= 0) {
		cout << "실패!! 체력을 모두 소진하였습니다" << endl;
		return false;
	}
	else {
		return true;
	}
}
