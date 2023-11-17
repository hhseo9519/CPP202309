#include<iostream>
#include<string>
using namespace std;

class User {
private:
	int hp;
	
public:
	User(int hp);
	void DecreaseHP();
	int GetHP();
	void IncreaseHP();
	void useHP();

};

