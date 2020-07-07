#include<iostream>
using namespace std;
int Representation(int Cent,int** arr,int* Denoms,int index)
{
    if(index<0)
        return 0;
    if(Cent==0)
        return 1;
    if(Cent<0)
        return 0;
    if(arr[Cent][index]==0)
        arr[Cent][index]=Representation(Cent-Denoms[index],arr,Denoms,index)+Representation(Cent,arr,Denoms,index-1);
    return arr[Cent][index];
}
int main()
{
    cout<<"Cents? ";
    int nCents;
    cin>>nCents;
    cout<<"\n Total Denoms avail: ";
    int nDenoms;
    cin>>nDenoms;
    int **CentArr=new int*[nCents+1]{};
    for(int i=0;i<=nCents;i++)
        CentArr[i]=new int[nDenoms]{};
    cout<<"\nEnter Denoms: ";
    int *Denoms=new int[nDenoms]{};
    for (int i=0;i<nDenoms;i++)
        cin>>Denoms[i];
    cout<<endl<<Representation(nCents,CentArr,Denoms,nDenoms-1);
    delete(CentArr);
}
