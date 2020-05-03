#include <iostream>
namespace name_space {
	int x = 100;
	int y = 200;

	int value(){
		return x*x;
	}
}
class c{
	int x = 100;
	int value(){
		return x*x;
	}
}

int main (){
	int x = 0;
	std::cout << "bla" << std::endl;
	std::cout << x << std::endl;
	std::cout << name_space::x << std::endl;
	std::cout << name_space::value() << std::endl;
}
