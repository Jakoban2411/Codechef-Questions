#include<iostream>
#include<new>
using namespace std;
template<typename T>
struct Node
{
    T data;
    Node* next;
};
template<typename T>
Node<T>* NewNode(T data)
{
    Node<T>* _newNode=new Node<T>;
    _newNode->data=data;
    _newNode->next=nullptr;
    return _newNode;
}
template<typename T>
struct HashedLinkList
{
    int _maxsize=1;
    int _currsize=0;
    Node<T>** array;
    HashedLinkList()
    {
        array=new Node<T>*[_maxsize];
        for(int i=0;i<_maxsize;i++)
            array[i]=nullptr;
    }
    bool insertNode(T data)
    {
        try
        {
            if(_currsize>=_maxsize-1)
            {
               _maxsize*=2;
               Node<T>** temparray=array;
               array=new Node<T>*[_maxsize];
                for(int i=0;i<_maxsize;i++)
                {    
                    if(i<=_currsize)
                        array[i]=temparray[i];
                    else
                        array[i]=nullptr;
                }
                delete(temparray);
            }
        }
        catch(bad_alloc &ba)
        {
            return false;
        }
        Node<T>* _newNode=NewNode(data);
        array[_currsize]=_newNode;
        if(_currsize!=0)
            array[_currsize-1]->next=array[_currsize];
        _currsize++;
        return true;
    }
    Node<T>* operator [](int num)
    {
        if(num<=_currsize)
            return (array[num]);
        else return nullptr;
    }
    void DeleteNode(int num)
    {
        for(int i=num;i<_currsize;i++)
        {
            array[i]=array[i+1];
        }
        
        array[_currsize]=nullptr;
    }
};
int main()
{
    HashedLinkList<int> m_MyList;
    m_MyList.insertNode(10);
    cout<<"\n"<<m_MyList._currsize<<" Max: "<<m_MyList._maxsize<<"\n";
    m_MyList.insertNode(156);
    cout<<"\n"<<m_MyList._currsize<<" Max: "<<m_MyList._maxsize<<"\n";
    cout<<m_MyList[0]->data;
    cout<<"\n"<<m_MyList._currsize<<" Max: "<<m_MyList._maxsize<<"\n";
    cout<<m_MyList[1]->data;
    m_MyList.insertNode(121);
    cout<<"\n"<<m_MyList._currsize<<" Max: "<<m_MyList._maxsize<<"\n";
    m_MyList.insertNode(20);
    cout<<"\n"<<m_MyList._currsize<<" Max: "<<m_MyList._maxsize<<"\n";
    m_MyList.insertNode(860);
    cout<<"\n"<<m_MyList._currsize<<" Max: "<<m_MyList._maxsize<<"\n";
    cout<<"\n"<<m_MyList[4]->data;
}
