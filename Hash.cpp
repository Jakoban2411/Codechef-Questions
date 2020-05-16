#include <iostream>
#define min(a,b)  (a<b)? (a) : (b)
using namespace std;

int countdigits(int data)
{
    int num=0;
    while(data>0)
    {
        data/=10;
        num++;
    }
    return num;
}
template<typename T>
struct HashEntries
{
    T data;
    HashEntries<T>* next=nullptr;
};
template<typename T>
HashEntries<T>* newEntry(T data)
{
    HashEntries<T>* NewEnt=new HashEntries<T>();
    NewEnt->data=data;
    NewEnt->next=nullptr;
    return NewEnt;
};
template<typename T>
struct HashTable
{
    HashEntries<T>** Nodes;
    int modby=1;
    int* chainsize;
    int size;
    int num_digits;
    HashTable<T>(int size)
    {
        if(size%2==0)
            size=size+1;
        num_digits=countdigits(size);
        for(int i=0;i<num_digits-1;i++)
            modby*=10;
        Nodes=new HashEntries<T>*[2*size]();
        for(int i=0;i<2*size;i++)
            Nodes[i]=new HashEntries<T>();    
        chainsize=new int[2*size]();
        this->size=size;
    }
    void insert(T data)
    {
        int hash=gethash(data);
        int index;
        HashEntries<T>* Store=newEntry(data);
        if(chainsize[hash]==0||chainsize[size+hash]==0)
        {
            index=((chainsize[hash]==0)?hash:(size+hash));
            Nodes[index]=Store;
            chainsize[index]++;
            return;
        }
        index=hash;
        if(chainsize[index]>chainsize[index+size])
            index=hash+size;
        HashEntries<T>* ListMove=Nodes[index];
        while(ListMove->next)
        {
            ListMove=ListMove->next;
        }
        chainsize[index]++;
        ListMove->next=Store;
    }
    HashEntries<T>* search(T data)
    {
        int hash=gethash(data);
        HashEntries<T>* MoveInSize=Nodes[hash];
        HashEntries<T>* MoveInExtra=Nodes[size+hash];
        while(MoveInSize || MoveInExtra)
        {
            if(MoveInSize->data==data)
                return MoveInSize;
            if(MoveInExtra->data==data)
                return MoveInExtra;
            if(MoveInSize)
                MoveInSize=MoveInSize->next;
            if(MoveInExtra)
                MoveInExtra=MoveInExtra->next;
        }
        return nullptr;
    }
    int gethash(T data)
    {
        int square=data*data;
        int num_digit_square=countdigits(square);
        int shiftby=0;
        cout<<"\n Count for square: "<<num_digit_square;
        if(num_digit_square>num_digits)
            shiftby=num_digit_square-num_digits;
        if(shiftby%2!=0)
            shiftby++;
        for(int i=0;i<shiftby/2;i++)
        {
            square/=10;
            cout<<" "<<square<<" ";
        }
        int hash=square % modby;
        cout<<"\n"<<hash<<"\n";
        return hash;
    }
};
int main()
{
    HashTable<int> _Hash(10);
    _Hash.insert(4);
    _Hash.insert(156);
    _Hash.insert(47);
    _Hash.insert(7);
    _Hash.insert(27);
    _Hash.insert(92);
    HashEntries<int>* Wi=_Hash.search(125);
    if(Wi)
        cout<<"Found 125";
    if(Wi==nullptr)
        cout<<"\n Didn't Find 125\n";
    Wi=_Hash.search(156);
    if(Wi)
        cout<<"Found 156";
    if(Wi==nullptr)
        cout<<"\n NOPE for 156 too";
    //cout<<"\n"<<_Hash.Nodes[5]->data;
}
