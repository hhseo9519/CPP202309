#include <iostream>
using namespace std;

int main() {

	int a, b, c, smallest;
	//3���� ������ �Է��Ͻÿ��� ȭ�鿡 ���
	cout << "3���� ������ �Է��Ͻÿ�:";
	//a��b��c�� �Է¹ޱ�
	cin >> a >> b >> c ;
	// ���� a�� b�� c���� �۴ٸ� a�� ���� �۴�
	if (a < b && a < c)
		smallest = a;
	//���� b�� a���� �۴ٸ� c ���� �۴�
	else if (b < a && b < c)
		smallest = b;
	//���� c�� a�� b���� ũ�ٸ� c�� ���� ũ�� 
	else
		smallest = c;

	cout << "���� ���� ������" << smallest << endl;
	return 0;
}