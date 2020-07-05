#include<iostream>
#include<stack> 
using namespace std;
void MoveTo(int SDisks,int EDisks,int InputTow,int OutputTow)
{
    cout<<"\n Moving Disks "<<SDisks<<" through "<< EDisks<<" from "<<InputTow<<" to "<<OutputTow;
    if(SDisks==EDisks)
    {
        return;
    }
    MoveTo(SDisks,EDisks-1,InputTow,6-(InputTow+OutputTow));
    MoveTo(EDisks,EDisks,InputTow,OutputTow);
    MoveTo(SDisks,EDisks-1,6-(InputTow+OutputTow),OutputTow);
}
void TowerOfHanoi(int Disks)
{
    MoveTo(1,Disks-1,1,2);
    MoveTo(Disks,Disks,1,3);
    MoveTo(1,Disks-1,2,3);
}

int main()
{
   int NDisks;
   cin>>NDisks;
   cout<<"\n Tower Of Hanoi with "<<NDisks<<" disks";
   TowerOfHanoi(NDisks);
}
