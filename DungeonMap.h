#ifndef DUNGEONMAP_H
#define DUNGEONMAP_H

#include "Floor.h"
#include "Wall.h"
#include "Switch.h"
#include "Door.h"
#include "Trap.h"
#include <sstream>
#include "Item.h"
#include "Lever.h"
#include "stdlib.h"
#include <math.h>
#include <map>
#include <utility>  //std::pair
#include <algorithm>

struct position
{
    int x;
    int y;

    bool operator<(const position& rsh) const
    {
        if (this->y < rsh.y)
            return true;
        else if (this->y > rsh.y)
            return false;
        else if (this->y == rsh.y)
        {
            if (this->x < rsh.x)
                return true;
            else if (this->x > rsh.x)
                return false;
            else return false;
        }
        return false;
    }

    bool operator==(const position& rsh) const
    {
        if (this->x == rsh.x && this->y == rsh.y)
            return true;
        else return false;
    }

    bool operator!=(const position& rsh) const
    {
        if (this->x == rsh.x && this->y == rsh.y)
            return false;
        else return true;
    }
};

class DungeonMap
{
public:
    DungeonMap(const int& weite, const int& hoehe);
    DungeonMap(const int& weite, const int& hoehe,
               const std::vector<std::string>& data);

    signed int getwidth() const
    {
        return width;
    };

    signed int getheight() const
    {
        return height;
    };
    void place(position pos, Character* c);
    position findTile(Tile* t)const;
    Tile* findTile(position p) const;
    position findCharacter(Character* c);
    void mkrelate(const std::vector <std::string>& relate);
    void print(Character* c);
    void print(position atckone, position atcktwo);

    bool LineOfSight(position from, position to);
    double round(double x);
    std::vector<position> getPathTo(position eny, position chr);
    bool contains(position pos, std::vector<position> vec);

    virtual ~DungeonMap();
private:
    Tile*** tiles;
    const signed int height; //y
    const signed int width; //x
};

#endif /* DUNGEONMAP_H */

