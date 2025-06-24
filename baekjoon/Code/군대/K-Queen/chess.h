#include <iostream>
#include <vector>
#define QUEEN 1
#define EMPTY 0
#define QUEEN_ATTACK 2
//#define KING 3
//#define KING_DANGER 4
//#define BLOCKED_BY_QUEEN 5

using namespace std;

class chess
    {
        public:

        chess(int size)
        {
            save = new vector<int>(size*size, EMPTY);
            chess_size = size;
            king = false;
        }

        ~chess()
        {
            delete save;
        }

        void queen_input(int x_t, int y_t);
        void king_input(int x_t, int y_t);
        void chess_check(int x_t, int y_t, int status);
        int chess_status(int x_t, int y_t);
        void answer();
        void refresh();


        private:
        
        vector<int> * save;
        int chess_size;
        bool king;
        int king_x;
        int king_y;



    };