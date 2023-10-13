#ifndef SNAKE_H
#define SNAKE_H

#include "domain/contracts/Ilist.h"
#include "domain/models/Coordinate.h"
#include "domain/models/DataNode.h"
#include "application/builder/SnakeBuilder.h"

#define DIR_UP 1
#define DIR_BOTTOM 2
#define DIR_LEFT 3
#define DIR_RIGHT 4

class Snake {
public:
    Snake(Ilist& body) : body(body) { 
        builder.BuildBody(this->body);
    }
    void stepForward();

    void changeDirection_up();
    void changeDirection_bottom();
    void changeDirection_left();
    void changeDirection_right();

    void print();
private:
    Ilist& body;
    int direction = DIR_UP;

    SnakeBuilder builder;
};

#endif // SNAKE_H