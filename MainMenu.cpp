#include <iostream>
#include <iomanip>
#include <string>
// include termminal color from  ikalnytskyi-termcolor (github) 
#include "termcolor.hpp"

namespace tc = termcolor;

extern const std::string TBNT_VERSION = "v0.1";
extern const auto BOLD = tc::bold;
extern const auto RST = tc::reset;


void MainMenu()
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
    
    std::cout << BOLD
              << tc::yellow << "[1]" << tc::cyan << " List Note\n"
              << tc::yellow << "[2]" << tc::cyan << " Add New Note\n" 
              << tc::yellow << "[3]" << tc::cyan << " Search Note\n" 
              << tc::yellow << "[4]" << tc::cyan << " Help\n"
              << tc::red    << "[0] Quit\n\n" << RST;
    
}

int main()
{
    int intChoice;
    //std::ostringstream ss;
    //ss << std::left << std::setfill(' ') << std::setw(10) << 123;

    do {
        MainMenu();
        std::cout << BOLD << "Your Choice (0 to quit) ? >";
        std::cin >> intChoice;
        RST;
     } while (intChoice != 0);


    //std::cout << BOLD << tc::red << "work or not\n";
    //std::cout << tc::red << BOLD  << "this is text" << RST << std::endl;
    //std::cout << ss.str() << "test\n";
	return 0;
}
