#include <iostream>
#include <string>
using namespace std;

int main() {
	//���� s1�� s2����
	string s1, s2;
	int count = 0;
	//s1�� s2�� �Է¹��� ���ڿ��� �Ҵ�
	cout << "DNA!: ";
	cin >> s1;
	cout << "DNA2 : ";
	cin >> s2;
	// ���� s1�� ���̰� s2�� ���̿� �ٸ��ٸ� ������ ���
	if (s1.length() != s2.length())
		cout << "����: ���̰� �ٸ�" << endl;
	//s1��s2�� ���̰� �ٸ��� �ʴٸ� �عְŸ��� ����Ͽ� ���
	else {
		for (int i = 0; i < s1.length(); i++) {
			if (s1[i] != s2[i])
				count += 1;
		}
		cout << " �ع� �Ÿ��� " << count << endl;
	}
	return 0;
}
