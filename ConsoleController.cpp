#include "ConsoleController.h"

ConsoleController::ConsoleController()
{
}

int ConsoleController::move()
{

    char input;
    std::cout << "Input>> 1-9 - Direction <<>> 0=Info <<>> x=Stop";
    std::cout << std::endl;
    std::cout << ":";
    std::cin >> input;
    std::cin.ignore(200, '\n');


    if (isdigit(input))
    {

        int val = input - 48;
        //  val = static_cast<int> (input);
        return val;
    }
    else if (input == 'x')
        return -1;

    else return -1;

}

ConsoleController::~ConsoleController()
{
//    this->~Controller();
}
