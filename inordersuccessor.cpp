#include<iostream>
#define max(a,b) (a>b?a:b)
using namespace std;
node* successor(node* start)
{
    if(!start->right)
    {
        node* parent=start->parent;
        while(parent!=nullptr && start==parent->right)
        {start=parent; parent=start->parent;}
        return parent;
    }
    node* succ=start->right;
    while(succ->left)
        succ=succ->left;
    return succ;
}
