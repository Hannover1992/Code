#include <iostream>
#include <string>
#include <ctime>
using namespace std;

void foo (string x){}
void bar (const string& x){}
const int iter = 1000000000;
int main(){
	string x("this ais a testlskd");
	time_t current_time;
	time_t new_time;
	time(&current_time);
	for(long long i = 0; i < iter; ++i){ 
//		cout << i << endl;
		foo(x);
	}
	time(&new_time);
	cout << new_time - current_time << endl;

	time(&current_time);
	for(long long i = 0; i < iter; ++i){ 
//		cout << i << endl;
		bar(x);
	}
	time(&new_time);
	cout << new_time - current_time << endl;
}
