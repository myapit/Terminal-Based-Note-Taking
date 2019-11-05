#include <iostream>
#include <iomanip>
#include <string>
// include termminal color from  ikalnytskyi-termcolor (github) 
#include "termcolor.hpp"

namespace tc = termcolor;

/* Variabled Declaration */
extern char   __BUILD_DATE;
extern char   __BUILD_VERSION;

extern const std::string TBNT_VERSION = "v0.1";
extern const auto BOLD = tc::bold;
extern const auto RST = tc::reset;
char intChoice;

/* Function Decleration */
bool MainMenu();

void ClearScreen()
{
    std::cout.flush();
    std::cout << "\033[2J\033[1;1H";
    std::cout << "\033[2J\033[1;1H";
}

void DisplayLogo()
{
    std::cout.flush();
    std::cout << "\033[2J\033[1;1H";
    std::cout << "\033[2J\033[1;1H";

    std::ostringstream ss;
    ss << std::setfill(' ');

	std::cout << ss.str() << std::setw(15) << tc::cyan << BOLD << " ╔╦╗╔╗ ╔╗╔╔╦╗ " << RST << std::endl
              << ss.str() << std::setw(15) << tc::cyan << BOLD << "  ║ ╠╩╗║║║ ║  " << RST << std::endl
	          << ss.str() << std::setw(15) << tc::cyan << BOLD << "  ╩ ╚═╝╝╚╝ ╩  " << TBNT_VERSION << RST << std::endl;
    std::cout << ss.str() << std::setw(10) << tc::magenta << BOLD <<"Terminal-Based Note Taking" << RST << std::endl << std::flush;  
    std::cout << std::endl;
}


void SubScreen()
{
    ClearScreen();
    DisplayLogo();
}

void ListNotes()
{
    ClearScreen();
    DisplayLogo();
    std::cout << "Listing Notes....\n";
    
    do {
        std::cout << "Press [q] to return to main menu. Choice ? >\n";
        std::cin >> intChoice;
        
        switch (intChoice)
        {
            case '1':
                std::cout << "Forward Page\n";
                break;

            case 'q':
                exit;
                break;   
            default:
                std::cout << "Choice Entered :" << intChoice << std::endl;
                break;
        }
     } while (intChoice != 'q');
    std::cout << "Never Run\n";
    exit;
}

bool MainMenu()
{
    ClearScreen();
    DisplayLogo();
    std::cout << BOLD
              << tc::yellow << "[1]" << tc::cyan << " List Notes\n"
              << tc::yellow << "[2]" << tc::cyan << " Add New Note\n" 
              << tc::yellow << "[3]" << tc::cyan << " Search Note\n" 
              << tc::yellow << "[4]" << tc::cyan << " Help\n"
              << tc::red    << "[0] Quit\n\n" << RST;

    std::cout << BOLD << "Your Choice (0 to quit) ? >" << RST ;
    std::cin >> intChoice;
    
    switch (intChoice)
    {
    case '1':
        ListNotes();
        return false;
        break;
    

    case '0':
        exit;
        break;
    default:
        std::cout << tc::red << "Wrong Choice ! Choose again.\n";
        return false;
        break;
    }
    return true;
}

int main()
{
   while(!MainMenu())
    {
        //std::cout << "Program Terminated.\n";
        ClearScreen();
        DisplayLogo();
    }
    std::cout << "N/D : " << (unsigned long)&__BUILD_VERSION << "/" <<  (unsigned long) &__BUILD_DATE << std::endl;
    //std::ostringstream ss;
    //ss << std::left << std::setfill(' ') << std::setw(10) << 123;
    //std::cout << BOLD << tc::red << "work or not\n";
    //std::cout << tc::red << BOLD  << "this is text" << RST << std::endl;
    //std::cout << ss.str() << "test\n";
    //std::cout << "\xDB\xDB\xDB\xDB\xB2  INFORMATION ABOUT PRODUCTS  \xB2\xDB\xDB\xDB\xDB";
	return 0;
}
