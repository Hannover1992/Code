#include <vector>
#include <iostream>
#include <string>

using namespace std;
int main(){
	vector<int> s(10,10);
	s.insert(s.begin() + 0,666);

	for(int i = 0; i < s.size(); i++){
		cout << s[i] << " ";
	}
}

class Test
{
int i ;
 
public:
Test(int ii):i(ii) { } //constructor
 
int get const() { return i; }
 
~Test( ) { }
};
 
int main( )
{
vector<int> vec={ 21 , 45 };
 
vec.push_back( Test(34) ) ; //Appending Test object by passing Test object
 
vec.push_back( 901 ) ; //Appending Test object but int data is passed,work fine
 
vec.emplace_back( Test(7889) ); //work fine
 
vec.emplace_back( 4156 ) ; //work fine
 
for( auto elem:vec )
{
cout<< elem.get() << ” ” ;
}
 
cin.get( );
return 0;
}


class New
{
int i;
string st;
public:
New(int ii, string s):i(ii) , st(s) { }
 
int getInt const() { return i; }
 
string getString const () { return st; }
 
~New( ) { }
};
 
int main( )
{
vector<int> vec={ {21,”String”} , New{45 , “tinger”} } ;
 
vec.push_back( New(34 , “Happy” ) ) ; //Appending Test object
 
vec.push_back( 901 , “Doer” ) ; //Error!!
 
vec.emplace_back( New(78 , “Gomu gomu” ) ); //work fine
 
vec.emplace_back( 41 , “Shanks” ) ; //work fine
 
for( auto elem:vec )
{
cout<< elem.getInt( ) << ” ” << elem.getString( ) << endl ;
}
 
cin.get( ) ;
return 0 ;
}
