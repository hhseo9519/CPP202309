#include<iostream>
using namespace std;

int main() {
	//���� ����
	int userInput;
	//������ �Է¹ޱ�
	cout << "������ 10�� �Է��ϼ��� (0�� �Է��ϸ� ����):";
	// ���ǹ��� ���� for�� ����
	for (int i = 0; i < 10; i++) {
		cin >> userInput;
		if (userInput == 0) {
			break;
		}
		//�������� �Է°��� Ƚ�� ���
		cout << "�Է°�:" << userInput << "Ƚ�� :" << i << endl;
	}
	cout << "���� �Ǿ����ϴ�";
	return 0;
}