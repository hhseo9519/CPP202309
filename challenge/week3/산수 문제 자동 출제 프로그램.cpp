#include <iostream>
#include <time.h>
using namespace std;

int main() {
	int i;
	int ans;
	cout << "��� ������ �ڵ����� �����մϴ�." << endl;

	while (true) {
		//firstnum�� secondnum�� �����ϴ� �Լ�
		int firstnum = rand() % 100;
		int secondnum = rand() % 100;

		cout << firstnum << "+" << secondnum << "=";
		cin >> ans;
		//firstnum�� secondnum�� ���Ѱ��� ans�Ͱ����� �¾ҽ��ϴ� ���
		if (firstnum + secondnum == ans) {
			cout << "�¾ҽ��ϴ�." << endl;
			break;
		}
		//�������� Ʋ�Ƚ��ϴ� ���
		else {
			cout << "Ʋ�Ƚ��ϴ�." << endl;
		}
		return 0;
	}
}