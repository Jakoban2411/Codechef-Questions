#include<iostream>
#define alpha 26
using namespace std;
int strlen(char* word)
{
    int len=0;
    while(*word!='\0')
    {   
        len++;
        word++;
    }
    return len;
}
struct TrieNode
{
    TrieNode* ptrs[alpha];
    bool EOW=false;
};
TrieNode* root=nullptr;
TrieNode* NewNode()
{
    TrieNode* newNode=new TrieNode;
    for(int i=0;i<alpha;i++)
    {
        newNode->ptrs[i]=nullptr;
    }
    return newNode;
}
char* lowercase(char* word,int length)
{
    for(int i=0;i<length;i++)
    {
        word[i]=tolower(word[i]);
    }
    return word;
}
void insert(char* word,int length)
{
    word=lowercase(word,length);
    TrieNode* nxt;
    TrieNode* Pnxt;
    nxt=root;
    for(int i=0;i<length;i++)
    {
        int alphabet=word[i]-97;
        Pnxt=nxt;
        nxt=nxt->ptrs[alphabet];
        if(!nxt)
        {
            nxt=NewNode();
            Pnxt->ptrs[alphabet]=nxt;
        }
    }
    nxt->EOW=true;
}
bool search(char* word,int length)
{
    word=lowercase(word,length);
    TrieNode* nxt=root;
    int i=0;
    while(i<length && nxt)
    {
        int alphabet=word[i]-97;
        nxt=nxt->ptrs[alphabet];
        i++;
    }
    if(nxt)
    {
        return ((nxt->EOW)? (true) : (false));
    }
    return false;
}
int main()
{
    root=NewNode();
    char ans='y';
    char word[10000];
    int size=0;
    while(ans=='y')
    {
        cin>>word;
        size=strlen(word);
        insert(word,size);
        cout<<"\n More?";
        cin>>ans;
        ans=tolower(ans);
    }
    ans='y';
    while(ans=='y')
    {
        cin>>word;
        size=strlen(word);
        if(search(word,size))
            cout<<"FOUND";
        else
            cout<<"Nope";   
        cout<<"More?";
        cin>>ans;
        ans=tolower(ans);
    }
}
