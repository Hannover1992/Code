#include <iostream>
#include <string>
#include <vector>
#include <memory>

int main (){
	std::unique_ptr<std::string> p = std::make_unique<std::string>("Hellow Wordl");
	std::cout<<p.get()<<": "<<*p<<" <"<<p->size()<<")\n";
}
