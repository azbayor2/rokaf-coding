#include "link.h"

using namespace std;


int main()
{

    nodes * cursor;


    nodes * headnode = new nodes(10);
    append_nodes(headnode, 100);

    cursor = headnode->returnnodes();
    append_nodes(cursor, 1000);

    cursor = headnode->returnnodes();
    delete_nodes(cursor);



    cursor = headnode;


    for(int i =0; i<2; i++)
    {
        cout << cursor->returnval() << " #" << i << endl;
        cursor = cursor->returnnodes();

    }

    return 0;

    



}