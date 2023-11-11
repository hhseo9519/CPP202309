#include <iostream>
using namespace std;
const int numCell = 3;
bool isValid(int x, int y, char board[][3]) {
	if (x >= numCell || y >= numCell) {
		cout << x << "," << y << ": x�� y �� �ϳ��� ĭ�� ����ϴ�." << endl;
		return false;
	}
	if (board[x][y] != ' ') {
		cout << x << "," << y << ": �̹� ���� ���ֽ��ϴ�." << endl;
		return false;
	}
	return true;
}
bool checkWin(char board[][numCell], char currentUser, int numCell) {
	bool isWin = false;

	// 6.1. ����/���� �� üũ�ϱ�
	for (int i = 0; i < numCell; i++) {
		if (board[i][0] == currentUser && board[i][1] == currentUser && board[i][2] == currentUser) {
			cout << "���ο� ��� ���� �������ϴ�!!";
			isWin = true;
			break;
		}
		if (board[0][i] == currentUser && board[1][i] == currentUser && board[2][i] == currentUser) {
			cout << "���ο� ��� ���� �������ϴ�!!";
			isWin = true;
			break;
		}
	}

	// 6.2. �밢���� üũ�ϱ�
	bool diagonal1 = true;
	bool diagonal2 = true;

	for (int i = 0; i < numCell; i++) {
		if (board[i][i] != currentUser) {
			diagonal1 = false;
		}

		if (board[i][numCell - 1 - i] != currentUser) {
			diagonal2 = false;
		}
	}

	if (diagonal1) {
		cout << "���� ������ ������ �Ʒ� �밢������ ��� ���� �������ϴ�!" << endl;
		isWin = true;
	}

	if (diagonal2) {
		cout << "������ ������ ���� �Ʒ� �밢������ ��� ���� �������ϴ�!" << endl;
		isWin = true;
	}

	return isWin;
}

int main() {
	// ������ �����ϴ� �� �ʿ��� ���� ����

	const int numCell = 3; // �������� ���� ���� ����
	int k = 0; // ���� �������� üũ�ϱ� ���� ����
	char currentUser = 'X'; // ���� ������ ���� �����ϱ� ���� ����
	char board[numCell][numCell]{}; // �������� ��Ÿ���� 2���� �迭
	int x, y = 0; // ����ڿ��� xy��ǥ���� �Է¹ޱ� ���� ����

	// ������ �ʱ�ȭ
	for (int i = 0; i < numCell; i++) {
		for (int j = 0; j < numCell; j++) {
			board[i][j] = ' ';
		}
	}

	// ������ ���� �ݺ�
	while (true) {
		// 1. ���� �������� ���
		// TODO 1.1: 3�ο� �������� ����
		switch (k % 3) {
		case 0:
			currentUser = 'X';
			break;
		case 1:
			currentUser = 'O';
			break;
		case 2:
			currentUser = 'H';
			break;
		}
		cout << k % 3 + 1 << "�� ����(" << currentUser << ")�� �����Դϴ�. -> ";

		// 2. ��ǥ �Է� �ޱ�
		cout << "(x, y) ��ǥ�� �Է��ϼ���: ";
		int x, y;
		cin >> x >> y;

		// 3. �Է¹��� ��ǥ�� ��ȿ�� üũ
		// TODO FUNC 1: isValid �Լ� ���� �� ȣ��
		if (!isValid(x, y, board)) {
			continue;
		}



		// 4. �Է¹��� ��ǥ�� ���� ������ �� ����
		board[x][y] = currentUser;

		// 5. ���� ���� �� ���
		// TODO 1.2: numCell ���ڿ� ���� ������ ���
		for (int i = 0; i < numCell; i++) {
			cout << "---l";
			for (int j = 0; j < numCell; j++) {
				cout << "---";
				if (j == numCell - 2) {
					break;
				}
				cout << "l";
			}
			cout << endl;

			for (int j = 0; j < numCell; j++) {
				cout << board[i][j];
				if (j == numCell - 1) {
					break;
				}
				cout << "  l";
			}
			cout << endl;
		}



		bool isWin = false; // �¸� ����
		// TODO FUNC2: 6.1���� 6.2���� checkWin �Լ� ���� �� ȣ��
		isWin = checkWin(board, currentUser, numCell);


		// �¸��ڰ� �����Ǿ����� �ش� �÷��̾ ����ϰ� ������ �����Ѵ�.
		if (isWin == true) {
			cout << k % 2 + 1 << "�� ����(" << currentUser << ")�� �¸��Դϴ�!" << endl;
			break;
		}

		// 7. ��� ĭ �� á���� üũ�ϱ�
		int checked = 0;
		for (int i = 0; i < numCell; i++) {
			for (int j = 0; j < numCell; j++) {
				if (board[i][j] == ' ') {
					checked++;
				}
			}
		}
		if (checked == 0) {
			cout << "��� ĭ�� �� á���ϴ�.  �����մϴ�. " << endl;
			break;
		}

		k++;
	}

	return 0;
}