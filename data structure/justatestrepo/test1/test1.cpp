#include "test1.h"
using namespace std;

void bag::num_bag()
{

  cout << bagg.size() << endl;

}

void bag::remake(int x)
{
  for(x; x<bagg.size()-1; x++)
  {
    bagg[x] = bagg[x+1];
  }
}

void bag::add_num(int x)
{
  bagg.push_back(x);
}


void bag::del_num(int x)
{
  for(int t = 0; t<bagg.size(); t++)
  {  
    if(bagg[t] == x)
    {  
      remake(t);
      return;
    }

  }
}


void bag::numofnum(int x)
{
  int count=0;

  for(int t = 0; t<bagg.size(); t++)
  {  
    if(bagg[t] == x)
      count++;

  }

  cout << "Number of " << x << ": " << count<<endl;
}

  

      


