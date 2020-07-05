#include<iostream>
using namespace std;
int main()
{
   char n1[]="999";
   char n2[]="999";
   int n2size=sizeof(n2)-1;
   int n1size=sizeof(n1)-1;
   int* product=new int[n1size+n2size]{};
   for(int i=n2size-1;i>=0;i--)
   {
       for(int j=n1size-1;j>=0;j--)
        product[i+j+1]+=(n1[i]-'0')*(n2[j]-'0');
   }
   for(int i=0;i<n1size+n2size;i++)
    {
        std::cout << product[i] << std::endl;
    }
}
