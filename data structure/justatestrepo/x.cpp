#include "x.h"


using namespace std;

int main()
{
    
    class chess
    {
        public:
        chess(int a, int b)
        :x{a}, y{b}
        {}

        private:
        int x, y;

    };


    stack<chess> test1;

    test1.push(chess(1,2));

    return 0;







}
