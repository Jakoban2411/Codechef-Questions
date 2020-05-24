#include<iostream>
using namespace std;
int strlength(char* arr)
{
    int num=0;
    while(*arr!='\0')
    {
        arr++;
        num++;
    }
    return num;
}
int setchar(char* arr,int n,int _Currindex)
{
    int _ncopy=n;
    int _num=0;
    //cout<<_ncopy<<" "<<arr<<"\n";
    while(_ncopy>0)
    {
        _ncopy/=10;
        _num++;
    }
    
    for(int i=_Currindex+_num;i>_Currindex;i--,n/=10)
    {   //cout<<n%10<<" "<<i<<" "; 
        arr[i]=('0'+(n%10)); 
        //cout<<arr<<"\n";
    }
    return _num;
}
int main()
{
    char _String[1000];
    char _CString[1000]="";
    cout<<"Enter String: ";
    cin>>_String;
    int _charcount=1;
    cout<<"\n";
    int _Cindex=0;
    int _Ostrlen=strlength(_String);
    for(int i=0;i<_Ostrlen;i++)
    {
        if(_String[i]!=_String[i+1])
        {
            _CString[_Cindex]=_String[i];
            _Cindex+=setchar(_CString,_charcount,_Cindex)+1;
            if(_Cindex>_Ostrlen)
                break;
            _charcount=1;
            continue;
        }
        _charcount++;
    }
    if(_Cindex>=_Ostrlen)
        {_CString[++_Cindex]='\0';cout<<_String;}
    else
        cout<<_CString;
}
