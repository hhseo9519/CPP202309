// user.cpp 파일

#include "user.h"




int User::GetHP() {
    return hp;
}


void User::useHP() {
    hp -= 1;
}

void User::doAttack() {
    std::cout << "공격합니다" << std::endl;
}


void Magician::doAttack() {
    std::cout << "마법 사용" << std::endl;
}

void Warrior::doAttack() {
    std::cout << "베기 사용" << std::endl;
}

