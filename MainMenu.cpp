#include <iostream>
#include <iomanip>
#include <string>


extern const std::string TBNT_VERSION = "v0.1";

void MainMenu()
{
	//std::cout << std::setfill('=') << std::setw(80) << std::flush << std::endl;
    //std::cout << "\n";
	std::cout << std::setfill(' ') << std::setw(65) << " ╔╦╗╔╗ ╔╗╔╔╦╗ " << std::endl
              << std::setfill(' ') << std::setw(59) << "  ║ ╠╩╗║║║ ║  " << std::endl
	          << std::setfill(' ') << std::setw(59) << "  ╩ ╚═╝╝╚╝ ╩  " << TBNT_VERSION << std::endl;
    std::cout << std::setfill(' ') << std::setw(50) << "Terminal-Based Note Taking" << std::endl << std::flush;
}

int main()
{
	MainMenu();

	return 0;
}
