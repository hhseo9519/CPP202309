#include <iostream>
#include <string>
using namespace std;

int main()
{//�л��� ���� �迭�� �� ĭ �� ���ϱ�
	const int student = 5;
	const int subject = 3;
	//�л��� ������ �迭�� ���ؼ� �Է¹ޱ�
	int scores[student][subject];
	string studentNames[student]
		= { "����","����","ö��","�̹�","����" };
	string subjectNames[student]
		= { "����","����","cpp" };
	//for���� ����Ͽ� �л��� ������ �ϳ��� studentNames�� �Է¹ޱ�
	for (int i = 0; i < student; i++) {
		cout << studentNames[i]
			<< "�� ������ �ϳ��� �Է��ϼ���." << endl;
		//for���� ����Ͽ� ���� ���� ������ �ϳ��� �Է¹ޱ�
		for (int j = 0; j < subject; j++) {
			cout << subjectNames[j] << ":";
			cin >> scores[i][j];
		}
	}
	//for���� ����Ͽ� �� �л����� ��������� ����ϱ�
	for (int i = 0; i < student; i++) {
		cout << studentNames[i] << "�� ��� ������";
		double sum = 0;
		double average = 0;
		for (int j = 0; j < subject; j++) {
			sum += scores[i][j];
		}
		//����� sum�� subject�� ���� ��
		average = sum / subject;
		cout << average << "�Դϴ�" << endl;
	}
	return 0;
}