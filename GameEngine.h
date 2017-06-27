#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include "DungeonMap.h"

class GameEngine
{
public:
    GameEngine(const int& weite, const int& hoehe,
               const std::vector<std::string>& data,
               const std::vector<std::string>& parse);

    bool finished();
    void turn();        //Calls (schlupfi) move function
    void run();
    position randompos();
    void print() const;
    position newpos(position old, int direction);
    void parser(const std::vector <std::string>& parse);
    virtual ~GameEngine();
private:
    DungeonMap* Map;
    std::vector <Character*> characters;
    bool kill;
};

#endif /* GAMEENGINE_H */

