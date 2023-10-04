#include <iostream>
#include <string>
using namespace std;

int main()
{//학생과 과목 배열에 들어갈 칸 수 정하기
	const int student = 5;
	const int subject = 3;
	//학생과 과목을 배열을 통해서 입력받기
	int scores[student][subject];
	string studentNames[student]
		= { "영수","영희","철수","미미","쥬쥬" };
	string subjectNames[student]
		= { "수학","영어","cpp" };
	//for문을 사용하여 학생의 성적을 하나씩 studentNames에 입력받기
	for (int i = 0; i < student; i++) {
		cout << studentNames[i]
			<< "의 성적을 하나씩 입력하세요." << endl;
		//for문을 사용하여 과목에 따른 점수를 하나씩 입력받기
		for (int j = 0; j < subject; j++) {
			cout << subjectNames[j] << ":";
			cin >> scores[i][j];
		}
	}
	//for문을 사용하여 각 학생들의 평균점수를 계산하기
	for (int i = 0; i < student; i++) {
		cout << studentNames[i] << "의 평균 점수는";
		double sum = 0;
		double average = 0;
		for (int j = 0; j < subject; j++) {
			sum += scores[i][j];
		}
		//평균은 sum을 subject로 나눈 값
		average = sum / subject;
		cout << average << "입니다" << endl;
	}
	return 0;
}