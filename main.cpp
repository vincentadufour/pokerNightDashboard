#include <map>
#include <string>
#include <list>
#include <iostream>


int getUserInt();

class Player
{
    public:
        std::string name {};
        int cash {};
        std::map<std::string, int> chips
        {
            {"red", 0},
            {"white", 0},
            {"green", 0},
            {"black", 0}
        };
        std::string history {};

        void recordHistory(std::string record)
        {
            history = history + record;
        }

        void printHistory()
        {
            std::cout << name << "'s History:\n" << history;
        }

        // chip map
        std::map<std::string, int> chipMap
        {
            {"red", 1},
            {"white", 5},
            {"green", 20},
            {"black", 50}
        };


        std::map<std::string, int> buyChips()
        {
            if ((cash % 100) != 0)
            {
                std::cout << "Please only buy chips in $100 denominations." << '\n';
                return chips;
            }

            // how many purchases of $100 worth of chips to buy?
            int purchases { cash / 100 };

            // buying the chips
            chips["red"] += 25 * purchases;
            chips["white"] += 6 * purchases;
            chips["green"] += 2 * purchases;

            std::string message {name + " bought $" + std::to_string(cash) + " worth of chips.\n"};
            recordHistory(message);

            cash = 0;

            return chips;
        }


        int buyCash()
        {
            cash = getUserInt();

            std::string message {name + " invested $" + std::to_string(cash) + ".\n"};
            recordHistory(message);

            return cash;
        }


        void printChips()
        {
            std::cout << name << "'s chips:\n";
            for (auto chip: chips)
            {
                std::cout << chip.first << ": " << chip.second << '\n';
            }
            std::cout << '\n';
        }

        void printCash()
        {
            std::cout << name << "'s cash:\n$" << cash << "\n\n";
            
        }
};


int getUserInt()
{
    std::cout << "Please enter a value: " << '\n';
    int input {};
    std::cin >> input;

    return input;
}


// void printConsole()
// {
//     std::string bar         {"#############################################################"};
//     std::string hollowBar   {"#                                                           #"};
    
//     // std::cout << "\033[2J";
//     // std::cout << "\033[H";
//     std::cout << bar << '\n';

//     // top spacing
//     std::cout << hollowBar << '\n';

//     // title
//     std::cout <<        "#                   POKER NIGHT DASHBOARD                   #" << '\n';



//     // bottom spacing
//     for (int i {0}; i < 10; i++)
//     {
//         std::cout <<    "#                                                           #" << '\n';
//     }
    
//     std::cout << bar << "\n\n";
// }

// std::list<std::string> playerCreation (std::list<std::string> playerList, int players)
// {    
//     std::cout << "\033[H";

//     for (int i {players}; i > 0; i--)
//     {
//         Player player[i];
        
//         // name
//         std::string input {};
//         std::cout << "Player name: ";
//         std::cin >> input;
//         player[i].name = input;

//         // starting cash

//         int amount {};
//         std::cout << "How much cash?: ";
//         std::cin >> amount;
//         player[i].cash = amount;

//     }

//     std::cout << player1.name;

//     return playerList;
// }




int main()
{
    
    // preps player creation subroutine
    bool playerCreationRoutine { true };

    Player Lian;
    Lian.name = "Lian";
    Lian.buyCash();
    Lian.printCash();
    Lian.buyChips();
    Lian.printChips();
    Lian.printCash();

    Lian.printHistory();


    return 0;
}


/*
Steps:
Player class with class functions:
- buy chips
- sell chips
- show stats
- show all player's stats

*/