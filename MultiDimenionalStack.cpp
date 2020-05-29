#include<iostream>
#include<cassert>
using namespace std;
template<typename T>
class multiDimensionalStack
{
    int StackCap;
    int CurrStackSize;
    int TotalStacksFormed;
    struct Node
    {
        T data;
        T* next;
        Node(T value,Node* points_to)
        {
            data= value;
            next=points_to;
        }
    };
    struct sizeCapNode
    {
        Node<T>* add;
        int size;
        sizeCapNode* next;
        sizeCapNode(sizeCapNode* points_to)
        {
            add=nullptr;
            next=points_to;
        }
    };
    sizeCapNode<T>* StackIndexhead;
    Node<T>* head;
    multiDimensionalStack(int size)
    {
        StackCap=size;
        head=nullptr;
        StackIndexhead=new sizeCapNode<T>();
        CurrStackSize=0;
        TotalStacksFormed=0;
    }
    public:
    void push(T data)
    {
        try
        {
            head=new Node<T>(data,head);
            CurrStackSize++;
            if(CurrStackSize>StackCap)
            {    
                StackIndexhead= new StackIndexhead(StackIndexhead);
                CurrStackSize=1;
                TotalStacksFormed++;
            }
            StackIndexhead->add=head;
        }
        catch(bad_alloc &ex)
        {
            assert("OUT OF MEMORY");
        }
            
    }
    T pop()
    {
        head=head->next;
        delete(StackIndexhead->add);
        if(CurrStackSize==1)
        {
            sizeCapNode* Temp=StackIndexhead;
            StackIndexhead=StackIndexhead->next;
            delete(Temp);
            CurrStackSize=StackCap;
            TotalStacksFormed--;
        }
        else
        {
            StackIndexhead->add=head;
            CurrStackSize--;
        }
        return head;
        
    }
    T pop(int index)
    {
        assert(index>TotalStacksFormed,"Index is more than total stacks formed");
        sizeCapNode* Temp=StackIndexhead->next;
        for(int i=1;i<TotalStacksFormed-index;i++)
        {
            Temp=Temp->next;
        }
    }
};
