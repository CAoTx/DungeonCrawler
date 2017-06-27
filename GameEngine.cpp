#include "GameEngine.h"
#include "StanionaryController.h"
#include "AttackController.h"

GameEngine::GameEngine(const int& weite, const int& hoehe, const std::vector<std::string>& data,
                       const std::vector <std::string>& parse)
{
    this->kill = false;
    try
    {
        Map = new DungeonMap(weite, hoehe, data);
        parser(parse);
    }
    catch (const char* maperr)
    {
        std::cerr << "GameEnginge() Error:" << maperr << std::endl;
    }
}

void GameEngine::parser(const std::vector<std::string>& parse)
{
    std::vector <std::string> APrelation;
    if (parse.size() > 0)
    {
        for (int i = 0; i < parse.size(); i++)
        {
            std::stringstream stream(parse[i]);
            std::string initval;
            stream>>initval;

            if (initval == "Character")
            {
                std::string ctrltyp;
                int ix, iy, strn, stam;
                char sign;
                stream >> sign >> strn >> stam >> ctrltyp >> ix >> iy;
                position pos{ix, iy};
                if (ctrltyp == "ConsoleController")
                {
                    Controller* cptr = new ConsoleController;
                    characters.push_back(new Character{sign, cptr, stam, stam}); //creats Char
                    Map->findTile(pos)->setprsn(characters[characters.size() - 1]);
                }
                else if (ctrltyp == "StationaryController")
                {
                    Controller* cptr = new StanionaryController;
                    characters.push_back(new Character{sign, cptr, stam, stam});
                    Map->findTile(pos)->setprsn(characters[characters.size() - 1]);
                }
                else if (ctrltyp == "AttackController")
                {
                    Controller* cptr = new AttackController;
                    characters.push_back(new Character{sign, cptr, stam, stam});
                    Map->findTile(pos)->setprsn(characters[characters.size() - 1]);
                }
            }
            else if (initval == "Switch" || initval == "S")
            {
                APrelation.push_back(parse[i]);
            }
            else if (initval == "Lever" || initval == "L")
            {
                APrelation.push_back(parse[i]);
            }
            else if (initval == "Item" || initval == "item")
            {
                APrelation.push_back(parse[i]);
            }
            else throw "GameEngine/parser() Syntax Error or no given value:";
        }
    }
    else
    {
        std::cout << "No Parse ?";
    }
    Map->mkrelate(APrelation);

}

bool GameEngine::finished()
{
    if (kill == true)
        return true;
    else if (characters.size() == 0)
        return true;
    return false;
}

void GameEngine::turn()
{
    if (characters.size() > 0)
    {
        //check if there is a controlable Character left
        int ctr = 0;
        for (int i = 0; i < characters.size(); i++)
        {
            if (characters[i]->getSign() != '$')
                ctr++;
        }

        //Check no more movable Character
        if (ctr == 0)
        {
            std::cout << "No Character?!";
            this->kill = true;
            return;
        }

            //0< movable character
        else if (ctr > 0)
        {
            int mv = 0;
            position oldp;
            position newp;

            //calls move function of every element(Enemy or Character)
            for (int i = 0; i < characters.size(); i++)
            {
                mv = characters[i]->move();

                // Moving Character (Console Controller)
                if (mv > 0 && mv < 10)
                {
                    //Calculation new position with oldposition and input
                    oldp = Map->findCharacter(characters[i]);
                    newp = newpos(oldp, mv);

                    try
                    {
                        //Check of newp=free Tile
                        if (Map->findTile(newp)->getprsn() == nullptr && newp != oldp)
                        {
                            Map->findTile(oldp)->onLeave(Map->findTile(newp));
                        }
                            //Check if there is an Enemy [$] on newTile 
                        else if (Map->findTile(newp)->getprsn()->getSign() == '$' && newp != oldp)
                        {
                            int atckone = Map->findTile(newp)->getprsn()->getstrength();
                            int atcktwo = Map->findTile(oldp)->getprsn()->getstrength();
                            Map->findTile(newp)->getprsn()->hit(atckone);
                            Map->findTile(oldp)->getprsn()->hit(atcktwo);
                            Map->print(oldp, newp); //prints fight
                        }
                    }

                    catch (const char* message)
                    {
                        std::cout << std::endl;
                        std::cerr << "GameEngine/turn() Error: " << message << std::endl << std::endl;
                    }
                }

                    //Character Infocard (Console Controller
                else if (mv == 0)
                {
                    characters[i]->showInfo();
                }


                    //pressed stop (Console Controller)
                else if (mv == -1)
                {
                    kill = true;
                    return;
                }


                    //Enemy find way, attack (Attack Controller)//Dijkstra
                else if (mv == -69)
                {
                    position enyoldpos, enynewpos, charpos;
                    std::vector<position> way;

                    //Locating Character //whos called first
                    for (signed int c = 0; c < characters.size(); c++)
                    {
                        if (characters[c]->getSign() != '$')
                        {
                            charpos = Map->findCharacter(characters[c]);
                            c = characters.size();
                        }
                    }
                    //Set old & new Enemy position by getPathTo()
                    enyoldpos = Map->findCharacter(characters[i]);
                    way = Map->getPathTo(enyoldpos, charpos); //Djikstra
                    enynewpos = way[way.size() - 1];

                    try
                    {
                        //Check of newp=free Tile
                        if (Map->findTile(enynewpos)->getprsn() == nullptr && enynewpos != enyoldpos)
                        {
                            Map->findTile(enyoldpos)->onLeave(Map->findTile(enynewpos));
                        }
                            //Check if there is an Enemy [$] on newTile 
                        else if (Map->findTile(enynewpos)->getprsn()->getSign() != '$' && enynewpos != enyoldpos)
                        {
                            int atckone = Map->findTile(enynewpos)->getprsn()->getstrength();
                            int atcktwo = Map->findTile(enyoldpos)->getprsn()->getstrength();
                            Map->findTile(enynewpos)->getprsn()->hit(atckone);
                            Map->findTile(enyoldpos)->getprsn()->hit(atcktwo);
                            Map->print(enyoldpos, enynewpos); //prints fight
                        }
                    }

                    catch (const char* message)
                    {
                        std::cout << std::endl;
                        std::cerr << "GameEngine/turn() Error: " << message << std::endl << std::endl;
                    }
                }
                //Check if any Character is dead after Battle
                if (characters[i]->getHP() < 0)
                {
                    position pos = Map->findCharacter(characters[i]);
                    Map->findTile(pos)->setprsn(nullptr);
                    delete characters[i];
                    for (int k = i; k < characters.size(); k++)
                        characters[k] = characters[k + 1];
                    characters.pop_back();
                    break;
                }
            }
        }
    }
    //if (characters.size()==0) kill==true;
}

void GameEngine::print() const
{
    for (int k = 0; k < characters.size(); k++)
    {
        if (characters[k]->getSign() != '$')
            Map->print(characters.at(k));
    }
}

void GameEngine::run()
{
    //Game is running
    while (!finished())
    {
        turn();
        print();
    }

    //Game Stop - pass lines
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "Nice Game --See you next Time--" <<
            std::endl << std::endl;
}

//Creating random numbers for positioning
//Characters in allowed spectrum

position GameEngine::randompos()
{
    bool ok = false;
    position fpos{1, 1};
    signed int ix, iy, height, width;
    height = Map->getheight();
    width = Map->getwidth();
    srand(time(NULL));
    int ctr = 0;
    try
    {
        while (ok == false)
        {
            std::cout << ctr++;
            ix = rand() % (width - 1);
            if (ix == 0)
                ix++;
            else if (ix == (width - 1))
                ix--;
            iy = rand() % (height - 1);
            if (iy == 0)
                iy++;
            else if (iy == (height - 1))
                iy--;
            fpos.x = ix;
            fpos.y = iy;

            if (Map->findTile(fpos)->print() == ' ')
                ok = true; //Check of correct placement
        }
    }
    catch (const char* errmssg)
    {
        std::cout << std::endl;
        std::cerr << "GameEngine/randompos() Error" << errmssg << std::endl;
    }
    return fpos;
}

position GameEngine::newpos(position nw, int direction)
{
    if (direction == 1 || direction == 2 || direction == 3)
        nw.x++;
    if (direction == 1 || direction == 4 || direction == 7)
        nw.y--;
    if (direction == 3 || direction == 6 || direction == 9)
        nw.y++;
    if (direction == 7 || direction == 8 || direction == 9)
        nw.x--;
    return nw;
}

GameEngine::~GameEngine()
{
    delete Map;
    for (int i = 0; i < characters.size(); i++)
    {
        delete characters[i];
    }
}