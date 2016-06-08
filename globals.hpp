#ifndef globals_hpp
#define globals_hpp

const double MAX_SPEED_FORWARD=4;
const double MAX_SPEED_BONUS=10;
const double MAX_SPEED_BACK=2;
const double ROTATION_ANGLE=3;
const double PLAYER_START_X=150;
const double PLAYER_START_Y=7550;
const double PLAYER_START_ROTATION=270;
const double ENEMY_START_X=230;
const double ENEMY_START_Y=7550;
const double ENEMY_START_ROTATION=270;
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
