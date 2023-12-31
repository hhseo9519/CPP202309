#include<iostream>
using namespace std;

int main() {
	const int numCell = 3;
	char board[numCell][numCell]{};
	int x, y; // 사용자에게 입력받는 x,y 좌표를 저장할 변수

	//보드판 초기화
	for (x = 0; x < numCell; x++) {
		for (y = 0; y < numCell; y++) {
			board[x][y] = ' ';
		}
	}
	//게임하는 코드
	int k = 0;// 누구 차례인지 체크하기 위한 변수
	char currentUser = 'X'; //현재 유저의 돌을 저장하기 위한 문자 변수
	while (true) {
		//1. 누구차례인지 출력
		switch (k % 2) {
		case 0:
			cout << k % 2 + 1 << "번 유저 (X)의 차례입니다 ->";
			currentUser = 'X';
			break;

		case 1:
			cout << k % 2 + 1 << "번 유저(0)의 차례입니다 ->";
			currentUser = '0';
			break;

		}

		//2.좌표 입력 받기
		cout << "(x,y) 좌표를 입력하세요 :";
		cin >> x >> y;

		//3. 입력받은 좌표의 유효성 체크
		//정해진 칸 이외에 칸을 입력한 경우
		if (x >= numCell || y >= numCell) {
			cout << x << ", " << y << ": ";
			cout << "x 와 y 둘 중 하나가 칸을 벗어납니다." << endl;
			continue;

		}//돌이 차 있는 경우
		if (board[x][y] != ' ') {
			cout << x << ", " << y << ":이미 돌이 차있습니다." << endl;
			continue;
		}
		//4. 입력받은 좌표에 현재 유저의 돌 놓기
		board[x][y] = currentUser;

		//5. 현재 보드 판 출력
		for (int i = 0; i < numCell; i++) {
			cout << "---l---l---" << endl;
			for (int j = 0; j < numCell; j++) {
				cout << board[i][j];
				if (j == numCell - 1) {
					break;
				}
				cout << "  l";
			}
			cout << endl;
		}
		cout << "---l---l---" << endl;
		k++;

		//6. 빙고 시 승자 출력 후 종료
		int checked = 0;
		for (int i = 0; i < numCell; i++) {
			for (int j = 0; j < numCell; j++) {
				if (board[i][j] == ' ') {
					checked++;
				}
			}
		}
		if (checked == 0) {
			cout << "모든 칸이 다 찼습니다. 종료합니다" << endl;
			break;
		}
		//7. 승자 체크하기
		bool isWin = false;
		//7.1 가로/세로돌 체크하기
		for (int i = 0; i < numCell; i++) {
			if (board[i][0] == currentUser && board[i][1] == currentUser && board[i][2] == currentUser) {
				cout << "가로에 모두 돌이 놓였습니다! : ";
				isWin = true;
			}
			if (board[0][i] == currentUser && board[1][i] == currentUser && board[2][i] == currentUser) {
				cout << "세로에 모두 돌이 놓였습니다! :";
				isWin = true;
			}
		}
		//7.2 대각선돌 체크하기
		if (board[0][0] == currentUser && board[1][1] == currentUser && board[2][2] == currentUser) {
			cout << "왼쪽 위에서 오른쪽 아래 대각선으로 모두 돌이 놓였습니다!: ";
			isWin = true;
		}
		if (board[0][2] == currentUser && board[1][1] == currentUser && board[2][0] == currentUser) {
			cout << "오른쪽 위에서 왼쪽 아래 대각선으로 모두 돌이 놓였습니다!: ";
			isWin = true;
		}
		if (isWin == true) {
			cout << k % 2 + 1 << "번 유저(" << currentUser << ") 의 승리입니다!" << endl;
			cout << "종료합니다" << endl;
			break;
		}

	}
	return 0;
}