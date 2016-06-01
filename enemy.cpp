#include "enemy.hpp"
#include "globals.hpp"
#include <vector>
#include <cmath>
#include "filemanager.hpp"

Enemy::Enemy(double x, double y, double rotation, File_Manager * fm)
{
    this->file_manager=fm;
    this->setTexture(file_manager->enemy_text);
    this->setPosition(x,y);
    this->setRotation(rotation);
    this->setOrigin(CAR_LENGTH/2,CAR_HEIGHT/2);
    this->set_vertices();
    this->speed=0;
    this->track_counter=0;
}

void Enemy::drive(int permission)
{
    sf::Vector2f track[]={{ENEMY_START_X,353},{1050,450},{953,734},{573,1003},{531,1212},{777,1168},{1030,1063},{1063,1247}
    ,{696,1818},{631,2138},{550,2229},{530,2518},{667,2649},{1237,3064},{1227,3259},{1218,3557},{1334,3714},{1171,3953},{671,4598}
    ,{671,4598},{916,5003},{1466,5218},{1350,5570},{410,5652},{217,5750},{322,5940},{325,6240},{620,6270},{853,6411}
    ,{1077,6654},{1102,6805},{1058,7061},{777,7257},{558,7120},{370,7110},{184,7366},{182,7616}};
    int i=this->track_counter;
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
    if (angle >1 && angle < 365)
    {
        if (angle > 180)
            this->setRotation(this->getRotation() + ROTATION_ANGLE);
        if (angle <= 180)
            this->setRotation(this->getRotation() - ROTATION_ANGLE);
    }
    this->speed+=0.1;
    if (this->speed>=MAX_SPEED_FORWARD) this->speed=MAX_SPEED_FORWARD;
    if (permission==0 || permission==1 || permission==4)
    {
        speed=0;
    }
    this->move(speed * cos(this->getRotation() * M_PI / 180), this->speed * sin(this->getRotation() * M_PI / 180));
    if (this->take_point(track[i]))
    {
        if (track[i].x==ENEMY_START_X && track[i].y==ENEMY_START_Y)
            track_counter=0;
        else
            this->track_counter++;
    }
    this->set_vertices();
}

bool Enemy::take_point(sf::Vector2f point)
{
    if (this->getRotation() == 0 || this->getRotation()==90 || this->getRotation()==180 || this->getRotation()==270)
    {
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
    else
    {
        double a[4],b[4];
        for (int i = 0; i <= 3; i++)
        {
            int n;
            if (i==0) n=3;
            else n=i-1;
            double x1=this->vertices[i].x;
            double x2=this->vertices[n].x;
            double y1=this->vertices[i].y;
            double y2=this->vertices[n].y;
            a[i]=(y1-y2)/(x1-x2);
            b[i]=y1-a[i]*x1;
        }
        double x = point.x;
        double y = point.y;
        if (y<a[0]*x+b[0] && y<a[1]*x+b[1] && y>a[2]*x+b[2] && y>a[3]*x+b[3]) return true;
        if (y>a[0]*x+b[0] && y>a[1]*x+b[1] && y<a[2]*x+b[2] && y<a[3]*x+b[3]) return true;
        if (y<a[0]*x+b[0] && y>a[1]*x+b[1] && y>a[2]*x+b[2] && y<a[3]*x+b[3]) return true;
        if (y>a[0]*x+b[0] && y<a[1]*x+b[1] && y<a[2]*x+b[2] && y>a[3]*x+b[3]) return true;
    }
    return false;
}