#include <iostream>
#include <string>
using namespace std;

int main() {
	//���� ����
	const int maxPeople = 3;
	string names[maxPeople];
	int ages[maxPeople];
	//for ���� ���� ������� �̸��� ���̸� �Է¹ޱ�
	for (int i = 0; i < maxPeople; i++) {
		cout << "���" << i + 1 << "�� �̸�:";
		cin >> names[i];
		cout << "���" << i + 1 << "�� ����:";
		cin >> ages[i];
	}
	//Ư�������� ageThreshold ���� �� �Է¹ޱ�
	int ageThreshold;
	cout << "Ư�� ���� �̻��� ����� ã������ ���̸� �Է��ϼ���:";
	cin >> ageThreshold;

	cout << ageThreshold << "�� �̻��� ����:\n";
	//����� ������� ���ϴ� ���� detectedPeople ����
	int detectedPeople = 0;
	//for ���� ���� Ư������ �̻��� ������� ����
	for (int i = 0; i < maxPeople; i++) {
		if (ages[i] >= ageThreshold) {
			cout << names[i] << "(" << ages[i] << "��)\n";
			detectedPeople++;
		}
	}
	//���� Ư�� ���� �̻��� ����� ���ٸ� �Ʒ��� cout ���
	if (detectedPeople == 0) {
		cout << ageThreshold << "�̻��� ���̸� ���� ���� �����ϴ�";
	}
}
