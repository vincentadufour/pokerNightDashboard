#include <map>
#include <string>
#include <list>
#include <iostream>



class Player
{
    public:
        std::string name {};
        float cash {0};
        std::map<std::string, int> chips {};
};


void printConsole()
{
    std::string bar         {"#############################################################"};
    std::string hollowBar   {"#                                                           #"};
    
    // std::cout << "\033[2J";
    // std::cout << "\033[H";
    std::cout << bar << '\n';

    // top spacing
    std::cout << hollowBar << '\n';

    // title
    std::cout <<        "#                   POKER NIGHT DASHBOARD                   #" << '\n';



    // bottom spacing
    for (int i {0}; i < 10; i++)
    {
        std::cout <<    "#                                                           #" << '\n';
    }
    
    std::cout << bar << "\n\n";
}

std::list<std::string> playerCreation (std::list<std::string> playerList, int players)
{    
    std::cout << "\033[H";

    for (int i {players}; i > 0; i--)
    {
        Player player[i];
        
        // name
        std::string input {};
        std::cout << "Player name: ";
        std::cin >> input;
        player[i].name = input;

        // starting cash

        int amount {};
        std::cout << "How much cash?: ";
        std::cin >> amount;
        player[i].cash = amount;

    }

    std::cout << player1.name;

    return playerList;
}




int main()
{
    // chip map
    std::map<std::string, int> chipMap
    {
        {"black", 100},
        {"red", 50},
        {"blue", 25},
        {"white", 10}
    };

    
    // preps player creation subroutine
    bool playerCreationRoutine { true };

    // clears terminal
    // std::cout << "\033[2J";

    // player creation start
    int input {};
    std::cout << "How many players would you like to add?: ";
    std::cin >> input;


    std::list<std::string> playerList {};
    playerList = playerCreation(playerList, input);

    






    return 0;
}
