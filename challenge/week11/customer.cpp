#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    // ���� ����
    vector<string> names;
    vector<int> ages;

    // for ���� ���� ������� �̸��� ���̸� �Է¹ޱ�
    char continueInput;
    do {
        string name;
        int age;

        cout << "����� �̸�: ";
        cin >> name;
        names.push_back(name);

        cout << "����� ����: ";
        cin >> age;
        ages.push_back(age);

        cout << "�� �Է��Ͻðڽ��ϱ�? (0/X): ";
        cin >> continueInput;
    } while (continueInput == '0');

    // Ư�� ������ ageThreshold ���� �� �Է¹ޱ�
    int ageThreshold;
    cout << "Ư�� ���� �̻��� ����� ã������ ���̸� �Է��ϼ���: ";
    cin >> ageThreshold;

    cout << ageThreshold << "�� �̻��� ����:\n";
    // ����� ������� ���ϴ� ���� detectedPeople ����
    int detectedPeople = 0;
    // for ���� ���� Ư������ �̻��� ������� ����
    for (size_t i = 0; i < names.size(); i++) {
        if (ages[i] >= ageThreshold) {
            cout << names[i] << "(" << ages[i] << "��)\n";
            detectedPeople++;
        }
    }

    // ���� Ư�� ���� �̻��� ����� ���ٸ� �Ʒ��� cout ���
    if (detectedPeople == 0) {
        cout << ageThreshold << "�̻��� ���̸� ���� ���� �����ϴ�";
    }

    return 0;
}