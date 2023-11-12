#include<iostream>
#include<string>
using namespace std;

class User {
public:
	int hp;
	void DecreaseHP(int &hp);
	int GetHP(int HP);
};
