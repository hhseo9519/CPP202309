#include <iostream>
#include <time.h>
using namespace std;

int main() {
	srand(time(null)); // random �Լ� ���� ����

	int answer = rand() % 100; //����
	int tries = 0; // �õ� Ƚ�� �����ϴ� ����

	int guess; // ����� �Է� �����ϱ� ���� ����
	//���ڸ� ���纸�ÿ��� ���� ���
	do {
		cout << "���ڸ� ���纸�ÿ�";
		cin >> guess;
		tries++;
		//guess�� answer���� ũ�ٸ� ������ ������ �����ϴٸ� ���
		if (guess > answer)
			cout << "������ ������ �����ϴ�" << endl;
		//guess�� answer���� �۴ٸ� ������ ������ �����ϴٸ� ���
		if (guess < answer)
			cout << "������ ������ �����ϴ�" << endl;
		//guess�� answer�� ���ٸ� ����
	} while (guess != answer);
	//���� do while�� ���� �� �Ʒ��� ���� ���
	cout << "�����մϴ�. �õ� Ƚ��=" << tries << endl;
	return 0;
}