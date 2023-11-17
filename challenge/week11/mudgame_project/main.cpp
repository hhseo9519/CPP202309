#include <iostream>
#include <string>
#include "user.h"
using namespace std;

const int mapX = 5;
const int mapY = 5;
int HP = 20;
// ���� ������ �ʿ��� �Լ� ����
bool checkXY(int user_x, int mapX, int user_y, int mapY);
void displayMap(int map[][mapX], int user_x, int user_y);
bool checkGoal(int map[][mapX], int user_x, int user_y);
void checkState(int map[][mapX], int user_x, int user_y,User& myHP);
bool checkUser(User user);
// ����  �Լ�
int main() {
	// ���ӿ� �ʿ��� 2���� �迭 ����
	//0 = �����,  2 = ��, 3 = ����, 4 = ������ 
	int map[mapY][mapX] = { {0, 0, 2, 0, 4},
					{0, 0, 0, 2, 0},
					{0, 0, 0, 0, 0},
					{0, 2, 3, 0, 0},
					{3, 0, 0, 0, 2} };
	//Ŭ���� ����
	//�����ڸ� hp=20���� �ʱ�ȭ
	User myHP{ 20 };

	// ������ ��ġ�� ������ ����
	int user_x = 0; // ���� ��ȣ
	int user_y = 0; // ���� ��ȣ



	// ���� ����
	while (1) { // ����ڿ��� ��� �Է¹ޱ� ���� ���� ����

		// ������� �Է��� ������ ����
		string user_input = "";
		cout << "���� ü���� :" << myHP.GetHP() << endl;
		cout << "��ɾ �Է��ϼ��� (��,��,��,��,����,����): ";
		cin >> user_input;


		if (user_input == "��") {
			// ���� �� ĭ �ö󰡱�
			user_y -= 1;
			bool inMap = checkXY(user_x, mapX, user_y, mapY);
			if (inMap == false) {
				cout << "���� ������ϴ�. �ٽ� ���ư��ϴ�." << endl;
				user_y += 1;
			}
			else {
				cout << "���� �� ĭ �ö󰩴ϴ�." << endl;
				displayMap(map, user_x, user_y);
				myHP.useHP();
			}
		}
		else if (user_input == "��") {
			// �Ʒ��� �� ĭ ��������
			user_y += 1;
			bool inMap = checkXY(user_x, mapX, user_y, mapY);
			if (inMap == false) {
				cout << "���� ������ϴ�. �ٽ� ���ư��ϴ�." << endl;
				user_y -= 1;
			}
			else {
				cout << "�Ʒ��� �� ĭ �������ϴ�." << endl;
				displayMap(map, user_x, user_y);
				myHP.useHP();
			}
		}
		else if (user_input == "��") {
			// �������� �̵��ϱ�
			user_x -= 1;
			bool inMap = checkXY(user_x, mapX, user_y, mapY);

			if (inMap == false) {
				cout << "���� ������ϴ�. �ٽ� ���ư��ϴ�." << endl;
				user_x += 1;
			}
			else {
				cout << "�������� �̵��մϴ�." << endl;
				displayMap(map, user_x, user_y);
				myHP.useHP();
			}
		}
		else if (user_input == "��") {
			// ���������� �̵��ϱ�
			user_x += 1;
			bool inMap = checkXY(user_x, mapX, user_y, mapY);
			if (inMap == false) {
				cout << "���� ������ϴ�. �ٽ� ���ư��ϴ�." << endl;
				user_x -= 1;
			}
			else {
				cout << "���������� �̵��մϴ�." << endl;
				displayMap(map, user_x, user_y);
				myHP.useHP();
			}
		}
		else if (user_input == "����") {
			// ���� �����ֱ� �Լ� ȣ��
			displayMap(map, user_x, user_y);
		}
		else if (user_input == "����") {
			cout << "�����մϴ�.";
			break;
		}
		else {
			cout << "�߸��� �Է��Դϴ�." << endl;
			continue;
		}
		//ü�¿� ���� ����
		checkState(map, user_x, user_y,myHP);

		// ������ ���� Ȯ�� �ϴ� �Լ�
		bool finish = checkGoal(map, user_x, user_y);
		if (finish == true) {
			cout << "�������� �����߽��ϴ�! �����մϴ�!" << endl;
			cout << "������ �����մϴ�." << endl;
			break;
		}
		//HP�� 0�̵Ǹ� ����-->checkUser �Լ� ����
		if (checkUser(myHP) == false)
		{
			break;
		}

	}
	return 0;
}


// ����� ��ġ�� ���Ե� ������ ����ϴ� �Լ�
void displayMap(int map[][mapX], int user_x, int user_y) {
	for (int i = 0; i < mapY; i++) {
		for (int j = 0; j < mapX; j++) {
			if (i == user_y && j == user_x) {
				cout << " USER |"; // �� �� 1ĭ ����
			}
			else {
				int posState = map[i][j];
				switch (posState) {
				case 0:
					cout << "      |"; // 6ĭ ����
					break;

				case 2:
					cout << "  ��  |"; // �� �� 2ĭ ����
					break;
				case 3:
					cout << " ���� |"; // �� �� 1ĭ ����
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

// �̵������� ĭ���� üũ�ϴ� �Լ�
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
//���� �������� ������ ��������� ������ HP ������ ��Ÿ���� �Լ�
void checkState(int map[][mapX], int user_x, int user_y, User& myHP) {
	//���� ���� ���
	if (user_y == 0 && user_x == 2 || user_y == 1 && user_x == 3 || user_y == 3 && user_x == 1 ||
		user_y == 4 && user_x == 4) {
		cout << "���� �������ϴ�. HP�� 2 �پ��ϴ�" << endl;
		myHP.DecreaseHP();
	}
	// ������ �������
	else if (user_y == 3 && user_x == 2 || user_y == 4 && user_x == 0) {
		cout << "������ �������ϴ�. HP�� 2 �þ�ϴ�" << endl;
		myHP.IncreaseHP();
	}



}
bool checkUser(User user) {
	if (user.GetHP() <= 0) {
		cout << "����!! ü���� ��� �����Ͽ����ϴ�" << endl;
		return false;
	}
	else {
		return true;
	}
}
