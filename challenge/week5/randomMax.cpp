#include <iostream>
#include <stdlib.h>
using namespace std;

int main() {
	const int numCell = 10;
	int numList[numCell][numCell];

	for (int i = 0; i < numCell; i++) {
		for (int j = 0; j < numCell; j++) {
			int elem = rand() % 1000;
			numList[i][j] = elem;
			cout << i << "," << j << ":" << elem << endl;
		}
	}
	cout << endl;

	int max = 0; //ū �� ������ ���� ����
	int maxI; // ū ���� �ִ� i �� �����ϱ� ���� ����
	int maxJ; // ū ���� �ִ� j �� �����ϱ� ���� ����
	for (int i = 0; i < numCell; i++) {
		int j = 0;
		for (auto value : numList[i]){
			if (max < value) {
				max = value;
				maxI = i;
				maxJ = j;
			}
			j++;
		}
	}
	cout << "���� ū ����" << max << "�̰�";
	cout << "i�� j�� ����" << maxI << "," << maxJ << "�Դϴ�." << endl;
	cout << "���� ���:" << numList[maxI][maxJ] << endl;

	return 0;


}