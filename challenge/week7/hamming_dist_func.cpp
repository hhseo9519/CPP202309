#include <iostream>
#include <string>
using namespace std;
//���ڿ��� �ҹ��ڷ� �ٲٴ� �Լ� ���� (tolower�Լ� ���)
string toLowerStr(string str) {
	string newstr = str;
	for (char& c : newstr) {
		c=tolower(c)
	}
	return newstr;
}
//���ڿ��� �빮�ڷ� �ٲٴ� �Լ� ���� (toupper�Լ� ���)
string toUpperStr(string str) {
	string newstr = str;
	for (char& c : newstr) {
		c = toupper(c)
	}
	return newstr;
}
//�� ���ڿ��� �ҹ��ڷ� �ٲٰ� �عְŸ��� ����ϴ� �Լ��� ����
int calcHammingdist(string s1, string s2) {
	s1 = toLowerstr(s1);
	s2 = toLowerstr(s2);
	int count = 0;
	for (int i = 0; i < s1.length(); i++) {
		if (s1[i] != s2[i])
			count += 1;
	}
	return 0;
}

int main() {
	string s1, s2;
	//��� �ݺ��ϴ� while ���� ����Ͽ� ���ڿ��� �Է¹ް�
	while (true) {
		cout << "DNA1: ";
		cin >> s1;
		cout << "DNA2: ";
		cin >> s2;
		//���̰� �ٸ��ٸ� ������ ���, ���̰� ���ٸ� �عְŸ� ����� �عְŸ� ���
		if (s1.length() != s2.length()) {
			cout << "����: ���̰� �ٸ�" << endl;
			continue;
		}
		else {
			int count = calcHammingdist(s1, s2);
			cout << "�ع� �Ÿ��� " << count << endl;
			break;
		}
	}
	return 0;
}