#include<iostream>
using namespace std;

int main() {
	int userInput;

	cout << "������ 10�� �Է��ϼ��� (0�� �Է��ϸ� ����):";
	// i=0 ���� �����ؼ� i<10�̶�� �Ʒ� cout ���� �� i�� 1�� ���ϰ� �ٽ� i�� 10�� ��
	for (int i = 0; i < 10; i++) {
		cin >> userInput;
		if (userInput == 0) {
			break;
		}
		cout << "�Է°�:" << userInput << "Ƚ�� :" << i << endl;
	}
	cout << "���� �Ǿ����ϴ�";
	return 0;
}