#include <iostream>
#include <vector>

using namespace std;

vector<char> t[27];

void preorder(char node)
{
    if(node == '.')
        return;

    cout << node;
    preorder(t[(int)node-'A'][0]);
    preorder(t[(int)node-'A'][1]);

    return;
}

void inorder(char node)
{
    if(node == '.')
        return;

    inorder(t[(int)node-'A'][0]);
    cout << node;
    inorder(t[(int)node-'A'][1]);

    return;

}

void postorder(char node)
{
    if(node == '.')
        return;

    postorder(t[(int)node-'A'][0]);
    postorder(t[(int)node-'A'][1]);
    cout << node;

    return;

}


int main()
{
    int nodes;
    cin >> nodes;

    char c1, c2, c3;

    for(int i =0; i<nodes; i++)
    {
        cin >> c1 >> c2 >> c3;
        t[(int)c1-'A'].push_back(c2);
        t[(int)c1-'A'].push_back(c3);

    }

    preorder('A');
    cout << "\n";
    inorder('A');
    cout << "\n";
    postorder('A');
    cout << "\n";

    return 0;
}