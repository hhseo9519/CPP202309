#include <iostream>
using namespace std;

int main() {

	int a, b, c, largest;
	//3���� ������ �Է��Ͻÿ��� ȭ�鿡 ���
	cout << "3���� ������ �Է��Ͻÿ�:";
	//a��b��c�� �Է¹ޱ�
	cin >> a >> b >> c;
	// ���� a�� b�� c���� ũ�ٸ� a�� ���� ũ��
	if (a > b && a > c)
		largest = a;
	//���� b�� a�� ũ�ٸ� c ���� ũ��
	else if (b > a && b > c)
		largest = b;
	//���� c�� a�� b���� ũ�ٸ� c�� ���� ũ�� 
	else
		largest = c;

	cout << "���� ū ������" << largest << endl;
	return 0;
}