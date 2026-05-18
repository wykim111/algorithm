/*
    < 구현 >

 @@@   @@@ 
@   @ @   @
@    @    @
@         @
 @       @ 
  @     @  
   @   @   
    @ @    
     @    
*/

#include <iostream>
#include <algorithm>

using namespace std;

int N;

void input()
{
    cin >> N;
}

void print_serca()
{
    /*
 @@@   @@@ 
@   @ @   @
@    @    @
@         @
 @       @ 
  @     @  
   @   @   
    @ @    
     @    
*/

    cout << " @@@   @@@ \n";
    cout << "@   @ @   @\n";
    cout << "@    @    @\n";
    cout << "@         @\n";
    cout << " @       @ \n";
    cout << "  @     @  \n";
    cout << "   @   @   \n";
    cout << "    @ @    \n";
    cout << "     @     \n";
}

void solution()
{
    for(int i=0; i < N;i++)
    {
        print_serca();
    }
}

int main()
{
    input();
    solution();

    return 0;
}
