#include <iostream>
#include <stack>
#define SIZE1 0

using namespace std;

class test
{
    public:

    test(int input)
    :save{input}
    {};

    int out()
    {
        return save;
    };

    int out2()
    {
        return (int)SIZE1;
    };
    


    private:
    int save;
};

