#include<iostream>
using namespace std;
int Representation(int Cent,int* arr,int* Denoms,int index,int nDenoms)
{
    if(Cent==0)
        return 0;
    arr[0]=1;
    for(int i=0;i<nDenoms;i++)
    {
        for(int j=S[i];j<=Cent;j++)
            arr[j]+=arr[j-S[i]];
    }
}
int main()
{
    cout<<"Cents? ";
    int nCents;
    cin>>nCents;
    cout<<"\n Total Denoms avail: ";
    int nDenoms;
    cin>>nDenoms;
    int *Denoms=new int[nDenoms]();
    for(int i=0;i<nDenoms;i++)
        cin>>Denoms[i];
    int *Reptable=new int[nCents+1]();
    cout<<Representation(nCents,Reptable,Denoms,0,nDenoms);
}
