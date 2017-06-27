#include "DungeonMap.h"

signed int cst(const std::string& number)
{
    signed int var = 0;
    for (int m = 0; m < number.size(); m++)
    {
        var = var + static_cast<signed int> (number.at(m));
    }
    return var;
}

class PathSegment
{
public:
    position pos;
    PathSegment* neighbor;
    int distance;

    PathSegment();

    PathSegment(position me, PathSegment* nghbr, int dist)
    {
        this->pos = me;
        this->neighbor = nghbr;
        this->distance = dist;
    }

    //goes through neigbors till nullptr

    /* std::vector<position> getPath() const
     {
         PathSegment* jungle = neighbor;
         std::vector<position> way{jungle->pos};

         //  std::vector<position> way;
         // PathSegment* jungle = neighbor;
         while (jungle != nullptr)
         {
            
             way.push_back(jungle->pos);
             jungle = jungle->neighbor;
         }
         return way;
     }*/

    std::vector<position> getPath() const
    {
        PathSegment* jungle = neighbor;
        std::vector<position> way{this->pos};

        //  std::vector<position> way;
        // PathSegment* jungle = neighbor;
        while (jungle->neighbor != nullptr)
        {

            way.push_back(jungle->pos);
            jungle = jungle->neighbor;
        }
        return way;
    }

    int getLength() const
    {
        int ctr = 0;
        PathSegment* jungle = nullptr;
        while (jungle != nullptr)
        {
            jungle = neighbor;
            ctr++;
        }
        return ctr;
    }

    ~PathSegment()
    {
    };

};
//for standart sort function

bool Pathhelper(const PathSegment* lhs, const PathSegment* rhs)
{
    if (lhs->distance < rhs->distance)
        return true;
    return false;
}

DungeonMap::DungeonMap(const int& weite, const int& hoehe) : height(hoehe), width(weite)
{
    tiles = new Tile** [height];
    for (int i = 0; i < height; i++)
    {
        tiles[i] = new Tile* [width];
    }
    for (int i = 0; i < width; i++)
    {
        for (int k = 0; k < height; k++)
        {
            tiles[i][k] = nullptr;
        }
    }
}

DungeonMap::DungeonMap(const int& weite, const int& hoehe,
                       const std::vector<std::string>& data) : height(hoehe), width(weite)
{
    if (data.size() != 0)
    {
        std::string var, error;

        tiles = new Tile** [height];
        for (int i = 0; i < height; i++)
        {
            tiles[i] = new Tile* [width];
        }
        for (int i = 0; i < height; i++)
        {
            var = data.at(i);
            for (int k = 0; k < width; k++)
            {
                if (var.at(k) == ' ')
                    tiles[i][k] = new Floor{nullptr, nullptr};
                else if (var.at(k) == '#')
                    tiles[i][k] = new Wall{nullptr};
                else if (var.at(k) == '?')
                    tiles[i][k] = nullptr;
                else if (var.at(k) == 'X')
                    tiles[i][k] = nullptr;
                else if (var.at(k) == '*')
                    tiles[i][k] = new Floor{nullptr, nullptr}; //sets item in mkrelate()
                else if (var.at(k) == 'T' || var.at(k) == 't')
                    tiles[i][k] = new Trap;
            }
        }
    }
    else throw "DungeonMap::DungeonMap(): Empty vector data";
}

void DungeonMap::mkrelate(const std::vector<std::string>& relate)
{
    if (relate.size() != 0)
    {
        for (int i = 0; i < relate.size(); i++)
        {
            std::string active;
            std::stringstream data(relate[i]);
            data>>active;

            //Creating Switch-Door Relation

            if (active == "S" || active == "Switch")
            {
                signed int sx, sy, dx, dy;
                std::string passive;
                data >> sx >> sy >> passive >> dx >> dy;

                if (passive == "D" || passive == "Door")
                {
                    Passive* door_ptr = new Door{nullptr};
                    Active* switch_ptr = new Switch{door_ptr};
                    tiles [dx][dy] = door_ptr;
                    tiles[sx][sy] = switch_ptr;
                }
                else throw "/DungeonMap::mkrelate(relate): Wrong Syntax";
            }

                //Creating Lever-Door Relation

            else if (active == "L" || active == "Lever")
            {
                signed int sx, sy, dx, dy;
                std::string passive;
                data >> sx >> sy >> passive >> dx >> dy;

                if (passive == "D" || passive == "Door")
                {
                    Passive* door_ptr = new Door{nullptr};
                    Active* lever_ptr = new Lever{door_ptr};
                    tiles [dx][dy] = door_ptr;
                    tiles [sx][sy] = lever_ptr;
                }
                else throw "/DungeonMap::mkrelate(relate): Wrong Syntax";
            }

                //Sets Items on Floortiles

            else if (active == "Item" || active == "item")
            {
                int ix, iy;
                std::string itemtyp;
                data >> itemtyp >> ix >> iy;

                if (itemtyp == "Armingsword")
                {
                    Item* itm_ptr = new ArmingSword;
                    Floor* floor_ptr = dynamic_cast<Floor*> (tiles [ix][iy]);
                    floor_ptr->getItem(itm_ptr);
                }
                if (itemtyp == "Greatsword")
                {
                    Item* itm_ptr = new GreatSword;
                    Floor* floor_ptr = dynamic_cast<Floor*> (tiles [ix][iy]);
                    floor_ptr->getItem(itm_ptr);
                }
                if (itemtyp == "Club")
                {
                    Item* itm_ptr = new Club;
                    Floor* floor_ptr = dynamic_cast<Floor*> (tiles [ix][iy]);
                    floor_ptr->getItem(itm_ptr);
                }
                if (itemtyp == "Rapier&Dagger")
                {
                    Item* itm_ptr = new RapierNDagger;
                    Floor* floor_ptr = dynamic_cast<Floor*> (tiles [ix][iy]);
                    floor_ptr->getItem(itm_ptr);
                }
                if (itemtyp == "Gambeson")
                {
                    Item* itm_ptr = new Gambeson;
                    Floor* floor_ptr = dynamic_cast<Floor*> (tiles [ix][iy]);
                    floor_ptr->getItem(itm_ptr);
                }
                if (itemtyp == "Mailarmour")
                {
                    Item* itm_ptr = new MailArmour;
                    Floor* floor_ptr = dynamic_cast<Floor*> (tiles [ix][iy]);
                    floor_ptr->getItem(itm_ptr);
                }
                if (itemtyp == "Fullplatearmour")
                {
                    Item* itm_ptr = new FullPlateArmour;
                    Floor* floor_ptr = dynamic_cast<Floor*> (tiles [ix][iy]);
                    floor_ptr->getItem(itm_ptr);
                }
            }
        }
    }
    else throw "/DungeonMap::mkrelate(relate): Empty vector";
}

void DungeonMap::place(position pos, Character * c)
{
    if (pos.x < 0 || pos.x > width)
        throw "DungeonMap::place(pos,c): False x value";
    if (pos.y < 0 || pos.y > height)
        throw "DungonMap::place(pos,c): False y value";
    this->tiles[pos.x][pos.y]->setprsn(c);
}

position DungeonMap::findTile(Tile * t) const
{
    for (int i = 0; i < height; i++)
    {
        for (int k = 0; k < width; k++)
        {
            if (tiles[i][k] == t)
            {
                position truevalue = {i, k};
                return truevalue;
            }
        }
    }
    position falsevalue = {-1, -1};
    return falsevalue;
}

Tile * DungeonMap::findTile(position p) const
{
    if (p.x < 0 || p.x > height)
        throw "DungeonMap::findTile(p): False x value";
    if (p.y < 0 || p.y > width)
        throw "DungeonMap::findTile(p): False y value";
    return tiles[p.x][p.y];
}

position DungeonMap::findCharacter(Character * c)
{
    for (int i = 0; i < height; i++)
    {
        for (int k = 0; k < width; k++)
        {
            if (tiles[i][k]->getprsn() == c)
            {
                position truevalue{i, k};
                return truevalue;
            }
        }
    }
    position falsevalue{-1, -1};
    return falsevalue;
}
//Standart ouput function

void DungeonMap::print(Character* c)
{
    position charview = findCharacter(c);
    //actual print
    for (int i = 0; i < height; i++)
    {
        for (int k = 0; k < width; k++)
        {
            if (LineOfSight(charview, findTile(tiles[i][k])) == true)
                std::cout << tiles[i][k]->print();
            else
                std::cout << '.';
        }
        std::cout << std::endl;
    }
}

//Attack print, prints one time % signs for battleing Characters

void DungeonMap::print(position atckone, position atcktwo)
{
    std::cout << std::endl;
    std::cout << "FIGHT!";
    for (int i = 0; i < height; i++)
    {
        for (int k = 0; k < width; k++)
        {
            position pos{i, k};
            if (pos == atckone || pos == atcktwo)
                std::cout << '%';
            else std::cout << tiles[i][k]->print();
        }
        std::cout << std::endl;
    }
    std::cout << "FIGHT!";
    std::cout << std::endl;
}
//from == character, to == tiles to check 

bool DungeonMap::LineOfSight(position from, position to)
{
    double deltaX = to.x - from.x;
    double deltaY = to.y - from.y;
    double len = std::sqrt((deltaX * deltaX) + (deltaY * deltaY));
    if (!len) return true;
    double unitX = deltaX / len;
    double unitY = deltaY / len;
    deltaX = from.x;
    deltaY = from.y;
    for (double i = 1; i < round(len); i++)
    {
        if (tiles[static_cast<int> (round(deltaX))][static_cast<int> (round(deltaY))]->isTransparent() == false)
        {
            return false;
        }
        deltaX += unitX;
        deltaY += unitY;
    }
    return true;
}

double DungeonMap::round(double x)
{
    if (x > 0)
    {
        x += 0.5;
    }
    if (x < 0)
    {
        x -= 0.5;
    }
    return x;
}

void findset(std::vector<PathSegment*>& grph, position pos, PathSegment* bro)
{
    for (int i = 0; i < grph.size(); i++)
    {
        if (grph[i]->pos == pos)
        {
            grph[i]->neighbor = bro;
            grph[i]->distance = bro->distance + 1;
        }
    }
}

std::vector<position> DungeonMap::getPathTo(position eny, position chr)
{
    position pos;
    int ctr = 0;
    std::vector<PathSegment*> graph;
    std::vector<position> done; //Already Checket position
    std::vector<position> way; //get init from PathSegmentclass getPath()
    PathSegment * popy;

    PathSegment* start = new PathSegment(eny, nullptr, 0);
    graph.push_back(start); //insert start position


    while (!graph.empty())
    {
        std::sort(graph.begin(), graph.end(), Pathhelper); //sorted by distance

        popy = graph[0];
        graph.erase(graph.begin());
        pos = popy->pos; //position for modulation
        done.push_back(pos); //save already done positions

        //end
        if (popy->pos == chr)
        {
            way = popy->getPath();
            for (int i = 0; i < graph.size(); i++)
            {
                delete graph[i];
            }
            return way;
        }
            //if standart if not end ^.^
        else
        { //every neighbor
            pos.x++;
            if (!contains(pos, done) && findTile(pos)->EnemyAcces())
            {
                graph.push_back(new PathSegment(pos, popy, popy->distance + 1));
            }
            pos.y--;
            if (!contains(pos, done) && findTile(pos)->EnemyAcces())
            {
                graph.push_back(new PathSegment(pos, popy, popy->distance + 1));
            }
            pos.x--;
            if (!contains(pos, done) && findTile(pos)->EnemyAcces())
            {
                graph.push_back(new PathSegment(pos, popy, popy->distance + 1));
            }
            pos.x--;
            if (!contains(pos, done) && findTile(pos)->EnemyAcces())
            {
                graph.push_back(new PathSegment(pos, popy, popy->distance + 1));
            }
            pos.y++;
            if (!contains(pos, done) && findTile(pos)->EnemyAcces())
            {
                graph.push_back(new PathSegment(pos, popy, popy->distance + 1));
            }
            pos.y++;
            if (!contains(pos, done) && findTile(pos)->EnemyAcces())
            {
                graph.push_back(new PathSegment(pos, popy, popy->distance + 1));
            }
            pos.x++;
            if (!contains(pos, done) && findTile(pos)->EnemyAcces())
            {
                graph.push_back(new PathSegment(pos, popy, popy->distance + 1));
            }
            pos.x++;
            if (!contains(pos, done) && findTile(pos)->EnemyAcces())
            {
                graph.push_back(new PathSegment(pos, popy, popy->distance + 1));
            }
        }
        ctr++;
    }
    way = popy->getPath();
    return way;
}

//Helper 4 GetPathTo() //geht nicht als Anonyme funktion??why

bool DungeonMap::contains(position pos, std::vector<position> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {

        if (vec[i] == pos)
            return true;
    }
    return false;
}

DungeonMap::~DungeonMap()
{
    for (int i = 0; i < width; i++)
    {
        for (int k = 0; k < height; k++)
        {
            delete tiles[k][i];
        }
    }
    for (int i = 0; i < height; i++)
    {
        delete tiles[i];
    }
    delete tiles;
}

