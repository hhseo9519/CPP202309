#include <iostream>
#include<fstream>
#include <string>
#include "user.h"
#include <vector>

using namespace std;

const int mapX = 5;
const int mapY = 5;

// ���� ������ �ʿ��� �Լ� ����
bool checkXY(int user_x, int mapX, int user_y, int mapY);
void displayMap(int map[][mapX], Magician& magician, Warrior& warrior);
bool checkGoal(int map[][mapX], int user_x, int user_y);
void checkState(int map[][mapX], int user_x, int user_y, User& myHP);
bool checkUser(User& user);

void loadMapFromFile(int map[][mapX], const string& filename) {
    try {
        ifstream file(filename);

        if (!file.is_open()) {
            throw runtime_error("������ �� �� �����ϴ�.");
        }

        for (int i = 0; i < mapY; ++i) {
            for (int j = 0; j < mapX; ++j) {
                if (!(file >> map[i][j])) {
                    throw runtime_error("���Ͽ��� �����͸� ���� �� �����ϴ�.");
                }
            }
        }

        file.close();
    }
    catch (const exception& e) {
        cerr << "���� �߻�: " << e.what() << endl;
        exit(1);
    }
}
// ���� �Լ�
int main() {

    
    vector<User*> list;
    int width = 5;
    int height = 5;
    // Ŭ���� ����
    // �����ڸ� hp=20���� �ʱ�ȭ
    Magician magician{ 0, 0, 'M', 20 };
    Warrior warrior{ 2, 2, 'W', 20 };
    int map[mapY][mapX];
    loadMapFromFile(map, "map.txt");


    // ���� ����
    User* currentUser = &magician;

    // ���� ����
    while (1) { // ����ڿ��� ��� �Է¹ޱ� ���� ���� ����
        string a;
        int number = 0;
        if (number % 2 == 0) {
            a = "������";
        }
        else {
            a = "����";
        }
        // ������� �Է��� ������ ����
        string user_input = "";
        cout << "���� ü���� :" << currentUser->GetHP() << endl;
        cout << "������ " << a << "�� �����Դϴ�" << endl;

        cout << "��ɾ �Է��ϼ��� (�� = w, �� = s,�� = a, �� = d): ";
        cin >> user_input;
        if (user_input == "w" || user_input == "s" || user_input == "a" || user_input == "d") {
            currentUser->move(user_input[0]);
            displayMap(map, magician, warrior);
            currentUser->useHP();
        }

        // ü�¿� ���� ����
        checkState(map, currentUser->getX(), currentUser->getY(), *currentUser);

        // ������ ���� Ȯ���ϴ� �Լ�
        bool finish = checkGoal(map, currentUser->getX(), currentUser->getY());
        if (finish) {
            cout << "�������� �����߽��ϴ�! �����մϴ�!" << endl;
            cout << "������ �����մϴ�." << endl;
            break;
        }

        // HP�� 0�� �Ǹ� ����
        if (!checkUser(*currentUser)) {
            break;
        }

        // ���� ���� ������ ����
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

// �̵� ������ ĭ���� üũ�ϴ� �Լ�
bool checkXY(int user_x, int mapX, int user_y, int mapY) {
    bool checkFlag = false;
    if (user_x >= 0 && user_x < mapX && user_y >= 0 && user_y < mapY) {
        checkFlag = true;
    }
    return checkFlag;
}

// ������ ��ġ�� �������� �����Ͽ����� üũ�ϴ� �Լ�
bool checkGoal(int map[][mapX], int user_x, int user_y) {
    // �������� �����ϰ� �Ǹ� ����
    if (map[user_y][user_x] == 4) {
        return true;
    }
    return false;
}

// ���� ���� ���� ������ ���� ����� ������ HP ������ ��Ÿ���� �Լ�
void checkState(int map[][mapX], int user_x, int user_y, User& myHP) {
    // ���� ���� ���
    if ((user_y == 0 && user_x == 2) || (user_y == 1 && user_x == 3) || (user_y == 3 && user_x == 1) ||
        (user_y == 4 && user_x == 4)) {
        cout << "���� �������ϴ�. HP�� 2 �پ��ϴ�" << endl;
        myHP.DecreaseHP();
        if (dynamic_cast<Magician*>(&myHP)) {
            dynamic_cast<Magician*>(&myHP)->doAttack();
        }

        else if (dynamic_cast<Warrior*>(&myHP)) {
            dynamic_cast<Warrior*>(&myHP)->doAttack();
        }
    }
    // ������ ���� ���
    else if ((user_y == 3 && user_x == 2) || (user_y == 4 && user_x == 0)) {
        cout << "������ �������ϴ�. HP�� 2 �þ�ϴ�" << endl;
        myHP.IncreaseHP();

    }
}

bool checkUser(User& user) {
    if (user.GetHP() <= 0) {
        cout << "����!! ü���� ��� �����Ͽ����ϴ�" << endl;
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
                cout << "  M   |";  // magician�� ��ġ
            }
            if (i == warrior.getY() && j == warrior.getX()) {
                cout << "  W   |";  // warrior�� ��ġ
            }
            else {
                int posState = map[i][j];
                switch (posState) {
                case 0:
                    cout << "      |";  // 6ĭ ����
                    break;

                case 2:
                    cout << "  ��  |";  // �� �� 2ĭ ����
                    break;
                case 3:
                    cout << " ���� |";  // �� �� 1ĭ ����
                    break;
                case 4:
                    cout << "������|";
                    break;
                }
            }
        }
        cout << endl;
        cout << " -------------------------------- " << endl;
    }
}