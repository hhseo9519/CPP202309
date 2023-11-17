#include "user.h"

void User::DecreaseHP() {
	hp -= 2;
}
int User::GetHP()
{
	return hp;
}
void User::IncreaseHP() {
	hp += 2;
}
void User::useHP() {
	hp -= 1;
}
User::User(int hp) {
	this->hp = hp;
}