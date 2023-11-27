#include<iostream>
#include<string>
using namespace std;

class User {

public:
	int hp;
	
	User(int hp);
	void DecreaseHP();
	int GetHP();
	void IncreaseHP();
	void useHP();
	void doAttack();

};
class Magician : public User {
public: 
	Magician(int hp);
	void doAttack() {
		cout << "마법 사용" << endl;
	}
};
class Warrior : public User {
public:
	void doAttack() {
		cout << "베기 사용" << endl;
	}
};