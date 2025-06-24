#include <iostream>
#include <vector>
#include <cmath>

#define EMPTY -1
#define WALL -2
#define INACTIVE_VIRUS -3
#define ACTIVE_VIRUS -4


using namespace std;

class puzzle
{
    public:
    puzzle(int size);
    void solve();

    private:
    int room_size;
    int num_active_virus;
    int num_total_virus;

    vector<int> room;
    vector<int> virus_loc;    //전체 바이러스 위치

    int calculate(vector<int> & ptr);
    void input(int x_t, int y_t, int i, vector<int> &ptr);
    int output(int x_t, int y_t, vector<int> &ptr);
};