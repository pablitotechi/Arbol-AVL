#include <iostream>
#include "AvlTree.h"
using namespace std;

// Test program
int main()
{
    AvlTree<int> t;
    int NUMS = 40;
    const int GAP = 3;
    int i;
 

    cout << "Checking... (no more output means success)" << endl;

    for (i = GAP; i != 0; i = (i + GAP) % NUMS)
        t.insert(i);
    t.remove(0);
    for (i = 1; i < NUMS; i += 2)
        t.remove(i);

    if (NUMS <= 40)
        t.printTree();
    if (t.findMin() != 2 || t.findMax() != NUMS - 2)
        cout << "FindMin or FindMax error!" << endl;

    for (i = 2; i < NUMS; i += 2)
        if (!t.contains(i))
            cout << "Find error1!" << endl;

    for (i = 1; i < NUMS; i += 2)
    {
        if (t.contains(i))
            cout << "Find error2!" << endl;
    }

    AvlTree<int> t2;
    t2 = t;

    for (i = 2; i < NUMS; i += 2)
        if (!t2.contains(i))
            cout << "Find error1!" << endl;

    for (i = 1; i < NUMS; i += 2)
    {
        if (t2.contains(i))
            cout << "Find error2!" << endl;
    }

    cout << "End of test..." << endl;
    return 0;


}