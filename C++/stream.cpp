#include <iostream>
#include <vector>
#include <fstream>

unsigned int calcLineCount(std::istream& is)
{
	char next_char;
	while(1){
		if(is){
			is.get(next_char);
			std::cout << next_char;
		} else {
			break;
		}
	}
	unsigned int lineCount = 0;
	std::string line;
	while(std::getline(is, line))
		++lineCount;
	return lineCount;;
}

int main(int argv, char** argc)
{

	std::vector<std::string> arguments(argc, argc + argv);
	std::ifstream fs(arguments[1]);
	std::cout << calcLineCount(fs) << "\n";
	return 0;
}
