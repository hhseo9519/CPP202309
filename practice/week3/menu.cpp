#include <iostream>
using namespace std;

int main() {
	int choice;
	//�Ʒ��� choice���� ���
	cout << "1. ��������" << endl;
	cout << "2. ���� ���� �ݱ�" << endl;
	cout << "3. ����" << endl;
	cin >> choice;
	//switch���� ����Ͽ� �Ʒ� 4���� ����ڰ� �ϳ��� ������ �� cout�� ������ ����ϰ� ����
	switch (choice) {
	case 1:
		cout << "���� ������ �����߽��ϴ�." << endl;
		break;
	case 2:
		cout << "���� �ݱ⸦ �����߽��ϴ�." << endl;
		break;
	case 3:
		cout << "���α׷��� �����մϴ�." << endl;
		break;
	default:
		cout << "�߸��� �����Դϴ�." << endl;
		break;

	}
	return 0;
}