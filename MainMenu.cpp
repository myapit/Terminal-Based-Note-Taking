#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <vector>

// include terminal color from  ikalnytskyi-termcolor (github) 
#include "termcolor.hpp"
#include "sqlitelib/sqlite3.h"


namespace tc = termcolor;

/* Variabled Declaration */
extern char __BUILD_DATE;
extern char __BUILD_VERSION;

const char* DBName = "example.db";

extern const std::string TBNT_VERSION = "v0.1";
extern const auto BOLD = tc::bold;
extern const auto RST = tc::reset;
char intChoice;


sqlite3* DB;
char* messaggeError;
int exitSQL = sqlite3_open(DBName, &DB);


/* Function Declaretion */
bool MainMenu();
void ClearScreen();
void DisplayLogo();
void SubScreen();
void ListNotes();
int insertSQL(std::string);
bool string_compare(const std::string& , const std::string&);
int case_insensitive_match(std::string , std::string);


/* Function Definitions */
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

bool string_compare(const std::string& a, const std::string& b)
{
        return std::equal(a.begin(), a.end(), b.begin(), b.end(),
                [](char a, char b) {
                    return tolower(a) == tolower(b);
                });
}

int case_insensitive_match(std::string s1, std::string s2) 
{
	// Credit : https://www.tutorialspoint.com/case-insensitive-string-comparison-in-cplusplus
   //convert s1 and s2 into lower case strings
    std::transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
    std::transform(s2.begin(), s2.end(), s2.begin(), ::tolower);
   if(s1.compare(s2) == 0)
      return 1; //The strings are same
   return 0; //not matched
}

int insertSQL(std::string sqlText)
{
    std::string sqlQuery("INSERT INTO notes(note) VALUES('" + sqlText + "')");
    exitSQL = sqlite3_exec(DB, sqlQuery.c_str(), NULL, 0, &messaggeError);
    if (exitSQL != SQLITE_OK) 
    {
        std::cerr << "Error Insert" << std::endl;
        sqlite3_free(messaggeError);
    }
    return 0;
}

void newNote()
{
    std::string line;
    //std::vector<std::string> v;
    std::string data="";
	while(std::getline(std::cin, line)){
    	if (std::cin.eof())//line.empty()){
        	break;
    	
        data.append(line+"\n");
    	//v.push_back(line);
	}
    
    
    //std::vector<std::string>::iterator it;

	//for (it = v.begin(); it != v.end(); it++)
    //	std::cout << *it << '\n';
	
    //std::cout << data;
    insertSQL(data);
    std::cout << ">> end new note\n";
    /*
    std::string note;
    std::cin.ignore();
    while(getline(std::cin, note))
    {
        if (std::cin.eof())
            break;
    }
    std::cout << note << std::endl;
    */
}


/* Main Program */
int main(int argc, char* argv[])
{
    if (argc == 1 )
    {
        while(!MainMenu())
        {
            //std::cout << "Program Terminated.\n";
            ClearScreen();
            DisplayLogo();
        }
    } else {
        std::string argMenu(argv[1]);
        if ( string_compare(argMenu, "list"))
		{
            std::cout << "List all notes\n";
            newNote();
        }
        
        if ( string_compare(argMenu, "new"))
        {
            std::cout << "New Note\n";
            newNote();
        }
        
    }
    
    /* BEGIN : Footer */
    std::cout << "N/D : " << (unsigned long)&__BUILD_VERSION << "/" <<  (unsigned long) &__BUILD_DATE << std::endl;
    //std::ostringstream ss;
    //ss << std::left << std::setfill(' ') << std::setw(10) << 123;
    //std::cout << BOLD << tc::red << "work or not\n";
    //std::cout << tc::red << BOLD  << "this is text" << RST << std::endl;
    //std::cout << ss.str() << "test\n";
    //std::cout << "\xDB\xDB\xDB\xDB\xB2  INFORMATION ABOUT PRODUCTS  \xB2\xDB\xDB\xDB\xDB";
	return 0;
}
