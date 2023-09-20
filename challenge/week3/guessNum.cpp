#include <iostream>
#include <time.h>
using namespace std;

int main() {
	srand(time(null)); // random 함수 관련 설정

	int answer = rand() % 100; //정답
	int tries = 0; // 시도 횟수 저장하는 변수

	int guess; // 사용자 입력 저장하기 위한 변수
	//숫자를 맞춰보시오를 먼저 출력
	do {
		cout << "숫자를 맞춰보시오";
		cin >> guess;
		tries++;
		//guess가 answer보다 크다면 제시한 정수가 높습니다를 출력
		if (guess > answer)
			cout << "제시한 정수가 높습니다" << endl;
		//guess가 answer보다 작다면 제시한 정수가 낮습니다를 출력
		if (guess < answer)
			cout << "제시한 정수가 낮습니다" << endl;
		//guess와 answer가 같다면 종료
	} while (guess != answer);
	//위에 do while문 종료 후 아래와 같이 출력
	cout << "축하합니다. 시도 횟수=" << tries << endl;
	return 0;
}