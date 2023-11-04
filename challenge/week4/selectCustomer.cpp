#include <iostream>
#include <string>
using namespace std;

int main() {
	//변수 선언
	const int maxPeople = 3;
	string names[maxPeople];
	int ages[maxPeople];
	//for 문을 통해 사람들의 이름과 나이를 입력받기
	for (int i = 0; i < maxPeople; i++) {
		cout << "사람" << i + 1 << "의 이름:";
		cin >> names[i];
		cout << "사람" << i + 1 << "의 나이:";
		cin >> ages[i];
	}
	//특정나이인 ageThreshold 선언 후 입력받기
	int ageThreshold;
	cout << "특정 나이 이상인 사람을 찾으려면 나이를 입력하세요:";
	cin >> ageThreshold;

	cout << ageThreshold << "세 이상인 고객들:\n";
	//검출된 사람들을 뜻하는 변수 detectedPeople 선언
	int detectedPeople = 0;
	//for 문을 통해 특정나이 이상의 사람들을 추출
	for (int i = 0; i < maxPeople; i++) {
		if (ages[i] >= ageThreshold) {
			cout << names[i] << "(" << ages[i] << "세)\n";
			detectedPeople++;
		}
	}
	//만약 특정 나이 이상의 사람이 없다면 아래의 cout 출력
	if (detectedPeople == 0) {
		cout << ageThreshold << "이상의 나이를 가진 고객이 없습니다";
	}
}
