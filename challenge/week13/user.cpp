// user.cpp ����

#include "user.h"




int User::GetHP() {
    return hp;
}


void User::useHP() {
    hp -= 1;
}

void User::doAttack() {
    std::cout << "�����մϴ�" << std::endl;
}


void Magician::doAttack() {
    std::cout << "���� ���" << std::endl;
}

void Warrior::doAttack() {
    std::cout << "���� ���" << std::endl;
}

