#include <iostream>
using namespace std;

int main() {
	//���� ����
	int choice;
	//ȭ�鿡 �Ʒ��� ���� ���
	cout << "1.��������" << endl;
	cout << "2. ���� ���� �ݱ�" << endl;
	cout << "3. ����" << endl;
	cin >> choice;
	//choice�� 1�̸� ���������� �����߽��ϴٸ� ���
	if (choice == 1)
		cout << "���� ������ �����߽��ϴ�." << endl;
	//1�� �ƴҶ� choice�� 2��� ���ϴݱ⸦ �����߽��ϴٸ� ���
	else if (choice == 2)
		cout << "���� �ݱ⸦ �����߽��ϴ�." << endl;
	//1,2�� �ƴ� �� choice�� 3�̶�� ���α׷��� �����մϴٸ� ���
	else if (choice == 3)
		cout << "���α׷��� �����մϴ�." << endl;
	//�������� �߸��� �����Դϴٸ� ���
	else
		cout << " �߸��� �����Դϴ�." << endl;
	return 0;
}