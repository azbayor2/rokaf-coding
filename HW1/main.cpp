#include "MyBoolVector.h"


int main()
{

    MyBoolVector test1;

    test1.push_back(true);
    test1.push_back(true);
    test1.push_back(false);
    test1.push_back(false);
    test1.push_back(true);
    test1.push_back(false);


    for(int i =0; i<test1.size() ; i++)
        cout << test1[i] << endl;




    test1.pop_back();
    
    for(int i =0; i<test1.size() ; i++)
        cout << test1[i] << endl;

    return 0;

}