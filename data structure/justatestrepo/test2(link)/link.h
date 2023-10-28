#include <iostream>
#include <string>
#include <vector>



using namespace std;


class nodes
{
    public:
    typedef double val;   //make new type "val"
    
    void num_entry(val input);    //enter value
    void next_address_entry(nodes * newnodes);    //enter the next address of the node

    nodes * returnnodes();    //return the next address of the node
    val returnval();     //return the value of the current node

    nodes(val input)       //creator
    :num{input}, next_address{NULL}
    {}

    

    private:
    nodes * next_address;    //save the "node" address
    val num;         //save the value of the current node

};


void append_nodes(nodes * prev_nodes, nodes::val input);    //insertion of a node
void delete_nodes(nodes * prev_nodes);