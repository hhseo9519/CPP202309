// user.h 파일
#include <iostream>
using namespace std;
class User {
protected:
    
    int x, y;
    char shape;
public:
    int hp = 20;
    User(int x, int y, char shape, int hp) : x{ x }, y{ y }, shape{ shape }, hp{hp} {}
    virtual ~User() {}
    virtual void move(char d) {
        if (d == 'a') { x -= 1; }
        else if (d == 'w') { y -= 1; }
        else if (d == 's') { y += 1; }
        else if (d == 'd') { x += 1; }
    }
    // 게터 및 세터
    char getShape() { return shape; }
    int getX() { return x; }
    int getY() { return y; }
    int getHP() { return hp; }
    bool checkCollision(User* other) {
        if (x == other->getX() && y == other->getY()) {
            return true;
        }
        else
            return true;
    }
    void SetX(int newX) { x = newX; }
    void SetY(int newY) { y = newY; }

    // 체력 조작 메서드
    void DecreaseHP() { hp -= 2; }
    void IncreaseHP() { hp += 2; }


   
    int GetHP();

    void useHP();
    void doAttack();
};

class Magician : public User {
public:
    Magician(int x, int y, char shape,int hp):User(x,y,'M',hp) {}
    void doAttack();
    void move(char d) override {
        User::move(d);
    }
   
};

class Warrior : public User {
public:
    Warrior(int x, int y, char shape, int hp):User(x,y,'W',hp) {}
    void doAttack();
    void move(char d) override {
        User::move(d);
    }
    
};
class Treasure : public User {
public:
    Treasure(int x, int y) : User(x, y, 'T',hp) { }
    void move(char d) {
    }
};
class Enemy : public User {
public:
    Enemy(int x, int y) : User(x, y, 'E', hp) { }
    void move(char d) {
    }
};