#include <iostream>
using namespace std;
struct BitVector
{
    int *arr;
    int sizeofint=sizeof(int);
    int bitsize=sizeofint*8;
    BitVector(int n)
    {
        arr=new int[n>>sizeof(int)]();
    }
    void insert(int number)
    {
        int index=(number)>>(1+sizeofint);
        int pos=index&(bitsize-1);
        arr[index]|=pos;
    }
    bool check(int number)
    {
        int index=(number)>>(1+sizeofint);
        int pos=1<<(sizeofint+1);
        if(arr[index]&pos>=1)  
            return true;
        return false;
    }
};
int main()
{
    BitVector Vect(32000);
    Vect.insert(1259);
    if(Vect.check(1259))
        cout<<"\n 1259 True";
    if(Vect.check(1000))
        cout<<"\n 1000 True";
    else
        cout<<"\n 1000 false";
}
