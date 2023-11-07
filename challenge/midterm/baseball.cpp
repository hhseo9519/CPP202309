#include <iostream>
#include <string>
using namespace std;
bool checkNumber(int firstNum, int secondNum, int thirdNum, bool same) {

	if (firstNum != secondNum && firstNum != thirdNum && secondNum != thirdNum) {
		same = true;
	}
	return same;
}



int main() {
	int randomNum; // ����� �ϴ� 3�ڸ����� ���� ���� ����
	int firstNum; // ������ ù��° �ڸ���
	int secondNum; // ������ �ι�° �ڸ���
	int thirdNum; // ������ ����° �ڸ���

	while (1) {
		randomNum = rand() % 900 + 100; // ������ 3�ڸ��� ����

		bool same = false; // ��� ���� �ٸ� ��� true�� ���� ����

		// TODO 1: 3�ڸ� ������ �ڸ����� �����ϰ�, ��� ���� �ٸ��� üũ�ϴ� �ڵ��� �ۼ�
		//���� 2�� �ڵ����� �Լ�ȭ �ϰ� ȣ��
		firstNum = randomNum / 100;
		secondNum = randomNum % 100 / 10;
		thirdNum = randomNum % 100 % 10;
		same = checkNumber(firstNum, secondNum, thirdNum, same);

		if (same == true) {
			break;
		}
	}

	int turn = 0;
	while (1) {
		cout << turn + 1 << "��° �õ��Դϴ�. " << endl;

		int userNumber; // ����ڰ� �Է��� ���ڸ��� ���� ����
		int guessFirst; // ������ ������ ù��° �ڸ���
		int guessSecond; // ������ ������ �ι�° �ڸ���
		int guessThird; // ������ ������ ����° �ڸ���


		// ����ڿ��� ���ڸ� ���� �Է¹޴� �ڵ� ���
		while (1) {
			cout << "���ڸ� ���� �Է����ּ���: ";
			cin >> userNumber;

			bool same = false; // ��� ���� �ٸ� ��� true�� ���� ����
			// TODO 1: 3�ڸ� ������ �ڸ����� �����ϰ�, ��� ���� �ٸ��� üũ�ϴ� �ڵ��� �ۼ�
			guessFirst = userNumber / 100;
			guessSecond = userNumber % 100 / 10;
			guessThird = userNumber % 100 % 10;
			if (guessFirst != guessSecond && guessFirst != guessThird && guessSecond != guessThird) {
				same = true;
			}





			if (to_string(userNumber).length() != 3) {
				cout << "�Էµ� ���ڰ� 3�ڸ� ���� �ƴմϴ�. �ٽ� �Է��ϼ���." << endl;
				continue;
			}

			if (same == true) {
				break;
			}
		}


		int strike = 0; // ��Ʈ����ũ ������ �����ϴ� ����
		int ball = 0; // �� ������ �����ϴ� ����

		// TODO 2: ����� ������ ������ �ڸ����� ���ڸ� ���ϸ� ��Ʈ�� �ֱ� ���� �ڵ��� �ۼ�
		int userNumbers[3] = { guessFirst,guessSecond,guessThird };
		int randomNumbers[3] = { firstNum, secondNum, thirdNum };
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (randomNumbers[i] == userNumbers[j]) {
					if (i == j) {
						strike++;
					}
					else {
						ball++;
					}
				}
			}
		}
		//out�� ��쿡�� out�� ����ϰ� ������ ���̽��ڵ� �ǵ帮�� �ȵǱ� ������ �̷��� out�� ����ϰڽ��ϴ�
		if (strike == 0 && ball == 0) {
			cout << "out" << endl;
		}


		cout << userNumber << "�� ��� : " << strike << " ��Ʈ����ũ, " << ball << "�� �Դϴ�." << endl;

		if (strike == 3) {

			cout << "������ ������ϴ�. �����մϴ�.";
			break;
		}

		turn += 1;
	}

	return 0;
}
