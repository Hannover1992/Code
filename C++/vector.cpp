#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){

   std::vector<int> old = {5,4,2,2,4,5,5,3,2};   
   std::vector<int> neu(old.size() + 1, 0);

   std::copy(old.begin(), old.end(), neu.begin());
   std::for_each(neu.begin(), neu.end(), [](int a){std::cout<<a<<" ";});


}



/*
void old(){
vector<int> vec={ {21,”String”} , New{45 , “tinger”} } ;
 
vec.push_back( New(34 , “Happy” ) ) ; //Appending Test object
 
vec.push_back( 901 , “Doer” ) ; //Error!!
 
vec.emplace_back( New(78 , “Gomu gomu” ) ); //work fine
 
vec.emplace_back( 41 , “Shanks” ) ; //work fine
 
for( auto elem:vec )
{
cout<< elem.getInt( ) << ” ” << elem.getString( ) << endl ;
}
 

}
 
 */
