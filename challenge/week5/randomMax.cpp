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

	int max = 0; //큰 값 저장을 위한 변수
	int maxI; // 큰 값이 있는 i 를 저장하기 위한 변수
	int maxJ; // 큰 값이 있는 j 를 저장하기 위한 변수
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
	cout << "가장 큰 값은" << max << "이고";
	cout << "i와 j는 각각" << maxI << "," << maxJ << "입니다." << endl;
	cout << "검증 결과:" << numList[maxI][maxJ] << endl;

	return 0;


}