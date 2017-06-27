#include <fstream>
#include "GameEngine.h"

int main()

{
    std::vector <std::string> map{};
    std::ifstream MapInFile("MapInFile.txt");
    if (MapInFile.is_open())
    {
        while (MapInFile.good())
        {
            std::string MapInFileStream;
            getline(MapInFile, MapInFileStream);
            map.push_back(MapInFileStream);
        }
    }
    signed int x = map.at(0).size(); //Actual y
    signed int y = map.size(); //Actual x

    std::vector<std::string> parse{};
    std::ifstream ParseInFile("ParseInFile.txt");
    if (MapInFile.is_open())
    {
        while (ParseInFile.good())
        {
            std::string ParseInFileStream;
            getline(ParseInFile, ParseInFileStream);
            parse.push_back(ParseInFileStream);
        }
    }
    GameEngine Engn = {x, y, map, parse};
    Engn.print();
    Engn.run();

    return 0;
}