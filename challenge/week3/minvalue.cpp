#include <iostream>
using namespace std;

int main() {

	int a, b, c, smallest;
	//3개의 정수를 입력하시오를 화면에 출력
	cout << "3개의 정수를 입력하시오:";
	//a와b와c를 입력받기
	cin >> a >> b >> c ;
	// 만약 a가 b와 c보다 작다면 a가 가장 작다
	if (a < b && a < c)
		smallest = a;
	//만약 b와 a보다 작다면 c 가장 작다
	else if (b < a && b < c)
		smallest = b;
	//만약 c가 a와 b보다 크다면 c가 가장 크다 
	else
		smallest = c;

	cout << "가장 작은 정수는" << smallest << endl;
	return 0;
}