#ifndef globals_hpp
#define globals_hpp

const double MAX_SPEED_FORWARD=4;
const double MAX_SPEED_BACK=2;
const double ROTATION_ANGLE=5;
const double PLAYER_START_X=500;
const double PLAYER_START_Y=500;
const double PLAYER_START_ROTATION=0;
const double ENEMY_START_X=400;
const double ENEMY_START_Y=400;
const double ENEMY_START_ROTATION=0;
const double WINDOW_LENGTH=800;
const double WINDOW_HEIGHT=600;
const int CAR_LENGTH=24;
const int CAR_HEIGHT=16;
const double FRAMERATE_LIMIT=24;
//Pozwolenie na ruch samochodzika.
//PERMISSION RIDE-pozwolenie na jazde do przodu i do tylu, oraz na skrecanie.
//PERMISSION_RIDE_FORWARD-pozwolenie na jazde jedynie do przodu.
//PERMISSION_RIDE_BACK-pozwolenie na jazde jedynie do tylu
enum {PERMISSION_RIDE,PERMISSION_RIDE_FORWARD,PERMISSION_RIDE_BACK};

#endif