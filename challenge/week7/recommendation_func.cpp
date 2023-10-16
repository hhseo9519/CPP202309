#include <iostream>
using namespace std;

const int NUM_USER = 3;
const int NUM_ITEMS = 3;
int userPreferences[NUM_USER][NUM_ITEMS];

//������� ��ȣ���� �Է¹޴� �Լ� ����
void initializePreferences(int Preferences[NUM_USER][NUM_ITEMS]) {
	for (int i = 0; i < NUM_USER; ++i) {
		cout << "����� " << (i + 1) << "�� ��ȣ���� �Է��ϼ��� (";
		cout << NUM_ITEMS << "���� �׸� ���� ):";
		for (int j = 0; j < NUM_ITEMS; j++)
			cin >> Preferences[i][j];
	}
}
//����� �� ��õ �׸��� ã�� �Լ� ����
void findRecommendedItems(const int Preferences[NUM_USER][NUM_ITEMS]) {
	//��õ �׸� ã��
	for (int i = 0; i < NUM_USER; ++i) {
		int maxPreferenceIndex = 0;
		for (int j = 1; j < NUM_ITEMS; ++j) {
			if (userPreferences[i][j] > userPreferences[i][maxPreferenceIndex]) {
				maxPreferenceIndex = j;
			}
		}



		// ����ڿ��� ��õ�ϴ� �׸� ���
		cout << "����� " << (i + 1) << "���� ��õ�ϴ� �׸�: ";
		cout << (maxPreferenceIndex + 1) << endl;
	}
}
int main() {
	//��ȣ���� �ʱ�ȭ�ϰ� ����ڿ��� ��õ�� �׸� ã��
	initializePreferences(userPreferences);
	findRecommendedItems(userPreferences);
}