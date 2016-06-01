#ifndef player_hpp
#define player_hpp
#include "car.hpp"

class Background;
class Player : public  Car
{
private:
	Background* background;

public:
    Player(double x, double y, double rotation, Background* background, File_Manager * fm);
    void drive(int permission);
};
#endif
