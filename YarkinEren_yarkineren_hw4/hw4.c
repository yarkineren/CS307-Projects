#include <iostream>
#include <fstream>
#include <chrono>
#include <time.h>

using namespace std;
int main ()
{
    clock_t begin= clock();
    unsigned int count=0 ;
    char letter;
    ifstream file("loremipsum.txt");
    if(file.is_open())
    {
        
        while(file >> letter)
        {
            if(letter == 'a')
                count++;

        }
        file.close();
        cout<<count<<endl;;
    }
    else
        cout<<"cant do "<<endl;;
    clock_t end=clock();
    float time = float(end-begin);
    cout<<time/CLOCKS_PER_SEC<<endl;
    
    

    return 0;
}