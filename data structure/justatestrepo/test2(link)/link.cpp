
#include "link.h"


using namespace std;


void nodes::num_entry(val input)      //save the value to the current node
{
    num = input;
}

void nodes::next_address_entry(nodes * newnodes)  //save the address of the next node
{
    next_address=newnodes;
}

nodes *nodes::returnnodes()    //return the address of the next node
{
    return next_address;
}

nodes::val nodes::returnval()    //return the value of the current node
{
    return num;
}

///////////////////////////////////////////////////////////////////

void append_nodes(nodes * prev_nodes, nodes::val input)
{
    nodes *temp = new nodes(input);
    prev_nodes->next_address_entry(temp);
    return;

}

void delete_nodes(nodes * prev_nodes)
{
    nodes * temp = (prev_nodes->returnnodes())->returnnodes();
    delete (prev_nodes->returnnodes());
    prev_nodes->next_address_entry(temp);

}