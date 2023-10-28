#include <iostream>
#include <string>
#include <vector>

using namespace std;

class bag
{
  public:
  void num_bag();
  void add_num(int x);
  void del_num(int x);
  void numofnum(int x);


  private:
  vector<int> bagg;
  void remake(int x);

};
  
