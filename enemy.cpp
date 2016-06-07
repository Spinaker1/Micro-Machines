#include "enemy.hpp"
#include "globals.hpp"
#include <vector>
#include <cmath>
#include "filemanager.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

//Zwraca liczbe pseudolosowa z zakresu (x,y)
int rand(int x, int y) {
    return (std::rand() % (y + 1 - x)) + x;
}

Enemy::Enemy(double x, double y, double rotation, File_Manager *fm) {
    this->file_manager = fm;
    this->setTexture(file_manager->enemy_text);
    this->setPosition(x, y);
    this->setRotation(rotation);
    this->setOrigin(CAR_LENGTH / 2, CAR_HEIGHT / 2);
    this->set_vertices();
    this->speed = 0;
    this->track_counter = 0;
    srand(time(NULL));
    track = {{rand(153, 266),   rand(7352, 7357)},
             {rand(353, 430),   rand(7045, 7170)},
             {rand(580, 584),   rand(7035, 7152)},
             {rand(883, 923),   rand(7128, 7250)},
             {rand(1050, 1131), rand(6927, 7026)},
             {rand(1072, 1221), rand(6735, 6754)},
             {rand(810, 933),   rand(6363, 6468)},
             {rand(720, 737),   rand(6212, 6393)},
             {rand(374, 485),   rand(6156, 6320)},
             {285,              6159},
             {336,              5913},
             {264,              5625},
             {rand(1217, 1296), rand(5430, 5565)},
             {rand(1271, 1521), rand(5226, 5340)},
             {rand(1174, 1235), rand(4945, 5137)},
             {rand(919, 977),   rand(4890, 5102)},
             {rand(510, 748),   rand(4716, 4728)},
             {rand(532, 756),   rand(4532, 4582)},
             {rand(1242, 1410), rand(3800, 3866)},
             {rand(1230, 1420), rand(3636, 3718)},
             {rand(986, 1266),  rand(3452, 3512)},
             {rand(1182, 1272), rand(3226, 3234)},
             {rand(1138, 1292), rand(2922, 3054)},
             {rand(760, 826),   rand(2658, 2810)},
             {rand(357, 606),   rand(2400, 2424)},
             {rand(513, 762),   rand(2166, 2169)},
             {rand(504, 825),   rand(1827, 1839)},
             {rand(924, 1179),  rand(1330, 1356)},
             {1089,             1050},
             {rand(639, 702),   rand(1119, 1323)},
             {408,              1086},
             {rand(627, 843),   rand(732, 822)},
             {rand(879, 1047),  rand(594, 615)},
             {993,              372},
             {993,              0}
    };
}


void Enemy::drive(int permission) {
    int i = this->track_counter;
    float angle;
    angle = atan((this->getPosition().y - track[i].y) / (this->getPosition().x - track[i].x)) * 180 / M_PI;
    if (this->getPosition().x == track[i].x && this->getPosition().y > track[i].y)
        angle = 270;
    if (this->getPosition().x == track[i].x && this->getPosition().y < track[i].y)
        angle = 90;
    if (this->getPosition().x > track[i].x)
        angle += 180;
    if (angle < 0)
        angle += 360;
    angle = this->getRotation() - angle;
    if (angle < 0)
        angle += 360;
    if (angle > 1 && angle < 365) {
        if (angle > 180)
            this->setRotation(this->getRotation() + ROTATION_ANGLE);
        if (angle <= 180)
            this->setRotation(this->getRotation() - ROTATION_ANGLE);
    }
    this->speed += 0.1;
    if (this->speed >= MAX_SPEED_FORWARD) this->speed = MAX_SPEED_FORWARD;
    if (permission == 0 || permission == 1 || permission == 4) {
        speed = 0;
    }
    this->move(speed * cos(this->getRotation() * M_PI / 180), this->speed * sin(this->getRotation() * M_PI / 180));
    if (this->take_point(track[i])) {
        if (track[i].x == ENEMY_START_X && track[i].y == ENEMY_START_Y)
            track_counter = 0;
        else
            this->track_counter++;
    }
    this->set_vertices();
}

//Sprawdza czy samochod natrafil na kolejny punkt trasy.
bool Enemy::take_point(sf::Vector2f point) {
    if (this->getRotation() == 0 || this->getRotation() == 90 || this->getRotation() == 180 ||
        this->getRotation() == 270) {
        double A = this->vertices[UPPER_RIGHT].x;
        double B = this->vertices[DOWN_LEFT].x;
        double C = this->vertices[UPPER_RIGHT].y;
        double D = this->vertices[DOWN_LEFT].y;
        double x = point.x;
        double y = point.y;
        if (this->getRotation() == 0 && x < A && x > B && y < C && y > D) return true;
        if (this->getRotation() == 90 && x > A && x < B && y < C && y > D) return true;
        if (this->getRotation() == 180 && x > A && x < B && y > C && y < D) return true;
        if (this->getRotation() == 270 && x < A && x > B && y > C && y < D) return true;
    }
    else {
        double a[4], b[4];
        for (int i = 0; i <= 3; i++) {
            int n;
            if (i == 0) n = 3;
            else n = i - 1;
            double x1 = this->vertices[i].x;
            double x2 = this->vertices[n].x;
            double y1 = this->vertices[i].y;
            double y2 = this->vertices[n].y;
            a[i] = (y1 - y2) / (x1 - x2);
            b[i] = y1 - a[i] * x1;
        }
        double x = point.x;
        double y = point.y;
        if (y < a[0] * x + b[0] && y < a[1] * x + b[1] && y > a[2] * x + b[2] && y > a[3] * x + b[3]) return true;
        if (y > a[0] * x + b[0] && y > a[1] * x + b[1] && y < a[2] * x + b[2] && y < a[3] * x + b[3]) return true;
        if (y < a[0] * x + b[0] && y > a[1] * x + b[1] && y > a[2] * x + b[2] && y < a[3] * x + b[3]) return true;
        if (y > a[0] * x + b[0] && y < a[1] * x + b[1] && y < a[2] * x + b[2] && y > a[3] * x + b[3]) return true;
    }
    return false;
}