#include <iostream>
#define MAX 1000
using namespace std;
int BTree[MAX];
void update_BTree(int index,int size,int update)
{
    index++;
    while(index<=size)
    {
        BTree[index]+=update;
        index+=(index & (-index));
    }
        
}
void construct_BIndexTree(int* arr,int n)
{
    for(int i=0;i<=n;i++)
        BTree[i]=0;
    for(int i=0;i<n;i++)
    {
        update_BTree(i,n,arr[i]);
    }
}
int main()
{
    int arr[]={10,50,12,-3,69,1,420,4,2,0};
    int n=sizeof(arr)/sizeof(int);
    construct_BIndexTree(arr,n);
    std::cout<<n<<std::endl;
    for(int i=0;i<=n;i++)
        std::cout<<" "<<BTree[i];
    std::cout <<std::endl;
    arr[5]+=7;
    update_BTree(5,n,7);
    for(int i=0;i<=n;i++)
        std::cout<<" "<<BTree[i];
}
