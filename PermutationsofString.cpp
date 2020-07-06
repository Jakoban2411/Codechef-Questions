#include<iostream>
#include<string>
#include<vector>
using namespace std;
vector<string> permutation(string BaseString,int length)
{
    vector<string> Perms ;
    if(BaseString.length()==1)
    {
        Perms.push_back(BaseString); 
        return Perms;
    }
    char FirstChar=BaseString[0];
    string RemainderString=BaseString.substr(1,length-1);
    vector<string> RemPerms=permutation(RemainderString,length-1);
    for(string word:RemPerms)
    {
        Perms.push_back(FirstChar+word);
        for(int j=0;j<word.length();j++)
        {
            string LHS=word.substr(0,j+1);
            string RHS=word.substr(j+1,word.length());
            string permword=LHS+FirstChar+RHS;
            Perms.push_back(permword);
        }
    }
    return Perms;
}
int main()
{
    string base;
    cin>>base;
    vector<string>Permutations=permutation(base,base.length());
    cout<<"\n Total permutations: "<<Permutations.size();
    cout<<"\n All perms:";
    for(string word:Permutations)
    {
        cout<<"\n"<<word;
    }
}
