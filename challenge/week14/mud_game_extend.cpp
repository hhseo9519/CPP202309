#include <iostream>
#include<fstream>
#include <string>
#include "user.h"
#include <vector>

using namespace std;

const int mapX = 5;
const int mapY = 5;

// 게임 구현에 필요한 함수 선언
bool checkXY(int user_x, int mapX, int user_y, int mapY);
void displayMap(int map[][mapX], Magician& magician, Warrior& warrior);
bool checkGoal(int map[][mapX], int user_x, int user_y);
void checkState(int map[][mapX], int user_x, int user_y, User& myHP);
bool checkUser(User& user);

void loadMapFromFile(int map[][mapX], const string& filename) {
    try {
        ifstream file(filename);

        if (!file.is_open()) {
            throw runtime_error("파일을 열 수 없습니다.");
        }

        for (int i = 0; i < mapY; ++i) {
            for (int j = 0; j < mapX; ++j) {
                if (!(file >> map[i][j])) {
                    throw runtime_error("파일에서 데이터를 읽을 수 없습니다.");
                }
            }
        }

        file.close();
    }
    catch (const exception& e) {
        cerr << "예외 발생: " << e.what() << endl;
        exit(1);
    }
}
// 메인 함수
int main() {

    
    vector<User*> list;
    int width = 5;
    int height = 5;
    // 클래스 선언
    // 생성자를 hp=20으로 초기화
    Magician magician{ 0, 0, 'M', 20 };
    Warrior warrior{ 2, 2, 'W', 20 };
    int map[mapY][mapX];
    loadMapFromFile(map, "map.txt");


    // 현재 유저
    User* currentUser = &magician;

    // 게임 시작
    while (1) { // 사용자에게 계속 입력받기 위해 무한 루프
        string a;
        int number = 0;
        if (number % 2 == 0) {
            a = "마법사";
        }
        else {
            a = "전사";
        }
        // 사용자의 입력을 저장할 변수
        string user_input = "";
        cout << "현재 체력은 :" << currentUser->GetHP() << endl;
        cout << "지금은 " << a << "의 차례입니다" << endl;

        cout << "명령어를 입력하세요 (상 = w, 하 = s,좌 = a, 우 = d): ";
        cin >> user_input;
        if (user_input == "w" || user_input == "s" || user_input == "a" || user_input == "d") {
            currentUser->move(user_input[0]);
            displayMap(map, magician, warrior);
            currentUser->useHP();
        }

        // 체력에 관한 제약
        checkState(map, currentUser->getX(), currentUser->getY(), *currentUser);

        // 목적지 도달 확인하는 함수
        bool finish = checkGoal(map, currentUser->getX(), currentUser->getY());
        if (finish) {
            cout << "목적지에 도착했습니다! 축하합니다!" << endl;
            cout << "게임을 종료합니다." << endl;
            break;
        }

        // HP가 0이 되면 종료
        if (!checkUser(*currentUser)) {
            break;
        }

        // 다음 턴의 유저로 변경
        if (currentUser == &magician) {
            currentUser = &warrior;
        }
        else {
            currentUser = &magician;
        }
        number++;
    }

    return 0;
}

// 이동 가능한 칸인지 체크하는 함수
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

// 적을 만난 경우와 포션을 만난 경우의 유저의 HP 변경을 나타내는 함수
void checkState(int map[][mapX], int user_x, int user_y, User& myHP) {
    // 적을 만난 경우
    if ((user_y == 0 && user_x == 2) || (user_y == 1 && user_x == 3) || (user_y == 3 && user_x == 1) ||
        (user_y == 4 && user_x == 4)) {
        cout << "적을 만났습니다. HP가 2 줄어듭니다" << endl;
        myHP.DecreaseHP();
        if (dynamic_cast<Magician*>(&myHP)) {
            dynamic_cast<Magician*>(&myHP)->doAttack();
        }

        else if (dynamic_cast<Warrior*>(&myHP)) {
            dynamic_cast<Warrior*>(&myHP)->doAttack();
        }
    }
    // 포션을 만난 경우
    else if ((user_y == 3 && user_x == 2) || (user_y == 4 && user_x == 0)) {
        cout << "포션을 만났습니다. HP가 2 늘어납니다" << endl;
        myHP.IncreaseHP();

    }
}

bool checkUser(User& user) {
    if (user.GetHP() <= 0) {
        cout << "실패!! 체력을 모두 소진하였습니다" << endl;
        return false;
    }
    else {
        return true;
    }
}

void displayMap(int map[][mapX], Magician& magician, Warrior& warrior) {
    for (int i = 0; i < mapY; i++) {
        for (int j = 0; j < mapX; j++) {
            if (i == magician.getY() && j == magician.getX()) {
                cout << "  M   |";  // magician의 위치
            }
            if (i == warrior.getY() && j == warrior.getX()) {
                cout << "  W   |";  // warrior의 위치
            }
            else {
                int posState = map[i][j];
                switch (posState) {
                case 0:
                    cout << "      |";  // 6칸 공백
                    break;

                case 2:
                    cout << "  적  |";  // 양 옆 2칸 공백
                    break;
                case 3:
                    cout << " 포션 |";  // 양 옆 1칸 공백
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