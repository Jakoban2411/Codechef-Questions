#include<iostream>
using namespace std;
void ConvertToBST(int* arr,int size,int* tree,int index,int start,int end)
{
    if(index>size)
        return;
    if((end-start)<2)
    {
            tree[index]=arr[end];
            int left=index*2+1;
            if(left>=size)
                left=size-1;
            tree[left]=arr[start];
            return;
    }
    int mid=(end-start)/2;
    tree[index]=arr[start+mid];
    if(end-start+1==3)
    {
        int left=2*index+1;
        if(left>=size-1)
        {left=size-2;}    
        tree[left]=arr[start];
        tree[left+1]=arr[end];
        return;
    }
    ConvertToBST(arr,size,tree,2*index+1,start,mid-1);
    ConvertToBST(arr,size,tree,2*index+2,mid+1,end);
}
int main()
{
    int size=0;
    int X[100];
    cout<<"Enter size: ";
    cin>>size;
    cout<<"Enter sorted array: ";
    for(int index=0;index<size;index++)
        cin>>X[index];
    int Tree[100];
    ConvertToBST(X,size,Tree,0,0,size-1);
    for(int index=0;index<size;index++)
        cout<<"\n"<<Tree[index];
}
