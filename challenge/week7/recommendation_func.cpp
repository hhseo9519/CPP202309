#include <iostream>
using namespace std;

const int NUM_USER = 3;
const int NUM_ITEMS = 3;
int userPreferences[NUM_USER][NUM_ITEMS];

//사용자의 선호도를 입력받는 함수 생성
void initializePreferences(int Preferences[NUM_USER][NUM_ITEMS]) {
	for (int i = 0; i < NUM_USER; ++i) {
		cout << "사용자 " << (i + 1) << "의 선호도를 입력하세요 (";
		cout << NUM_ITEMS << "개의 항목에 대해 ):";
		for (int j = 0; j < NUM_ITEMS; j++)
			cin >> Preferences[i][j];
	}
}
//사용자 별 추천 항목을 찾는 함수 생성
void findRecommendedItems(const int Preferences[NUM_USER][NUM_ITEMS]) {
	//추천 항목 찾기
	for (int i = 0; i < NUM_USER; ++i) {
		int maxPreferenceIndex = 0;
		for (int j = 1; j < NUM_ITEMS; ++j) {
			if (userPreferences[i][j] > userPreferences[i][maxPreferenceIndex]) {
				maxPreferenceIndex = j;
			}
		}



		// 사용자에게 추천하는 항목 출력
		cout << "사용자 " << (i + 1) << "에게 추천하는 항목: ";
		cout << (maxPreferenceIndex + 1) << endl;
	}
}
int main() {
	//선호도를 초기화하고 사용자에게 추천할 항목 찾기
	initializePreferences(userPreferences);
	findRecommendedItems(userPreferences);
}