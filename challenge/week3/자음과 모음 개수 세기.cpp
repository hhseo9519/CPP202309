#include <iostream>
using namespace std;

int main() {
	int vowel = 0;
	int consonant = 0;
	cout << "�����ڸ� �Է��ϰ� crtl+z�� ġ����" << endl;

	char ch; // ����� �Է� �����ϱ� ���� ����
	while (cin >> ch)
	{
		switch (ch)
		{
			//a,e,i,o,u �ΰ�� break�ϱ�
		case 'a': case 'i': case'e':case'o':case'u':
			vowel++; break;
			//�������� �������� ���
		default:
			consonant++;
			break;
		}
		}
	cout << "����: " << vowel << endl;
	cout << "����: " << consonant << endl;
	return 0;
}