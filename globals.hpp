#ifndef globals_hpp
#define globals_hpp

const double MAX_SPEED_FORWARD=5;
const double MAX_SPEED_BACK=2;
const double ROTATION_ANGLE=3;
const double PLAYER_START_X=1000;
const double PLAYER_START_Y=120;
const double PLAYER_START_ROTATION=90;
const double ENEMY_START_X=950;
const double ENEMY_START_Y=120;
const double ENEMY_START_ROTATION=90;
const double WINDOW_LENGTH=800;
const double WINDOW_HEIGHT=600;
const int CAR_LENGTH=64;
const int CAR_HEIGHT=30;
const double FRAMERATE_LIMIT=64;

enum
{
    NONE = -1,
    UPPER_RIGHT,
    UPPER_LEFT,
    DOWN_LEFT,
    DOWN_RIGHT,
    UP,
    DOWN
};

typedef enum
{
    up=1,
    down,
} Direction;


#endif