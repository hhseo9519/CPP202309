#include <iostream>
using namespace std;

int main() {
	//���� ����
	int number;
	//"���ڸ� �Է��Ͻÿ�"�� ���
	cout << "���ڸ� �Է��Ͻÿ�";
	//���ڸ� �Է¹ޱ�
	cin >> number;
	//number�� 1���� ������ zero�� ���
	if (number < 1)
		cout << "zero\n";
	//number�� 1�� ������ one�� ���
	else if (number == 1)
		cout << "one\n";
	//�������� many�� ���
	else
		cout << "many\n";
	return 0;
}