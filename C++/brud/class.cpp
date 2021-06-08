#include <iostream>

class foo
{
	public:
	int x = 123;
	int value(){
		return x + x;
	}
};

		

int main(){
	foo temp;
	temp.x = 321;

	std::cout << temp.value() << std::endl;
}
