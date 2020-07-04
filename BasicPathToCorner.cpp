#include<iostream>
using namespace std;
bool getpath(int Maze[][10],bool Vis[][10],int r,int c)
{
    if(Vis[r][c]==true || Maze[r][c]==0)
        return false;
    Vis[r][c]=true;
    if(r==4 && c==9)
        return true;
    if(getpath(Maze,Vis,r+1,c)||getpath(Maze,Vis,r,c+1))
        cout<<r<<" "<<c<<"\n";
}
int main()
{
    int Maze[5][10]={ {1,1,1,1,1,1,1,1,1,0},
                       {0,0,1,0,1,0,1,1,0,1},
                       {1,1,1,1,0,0,1,1,1,0},
                       {0,0,1,1,1,1,1,0,1,1},
                       {1,0,0,1,1,1,1,1,1,1} };
    bool Vis[5][10]{};
    cout<< Vis[0][0]<<" "<<Vis[0][1];
    if(getpath(Maze,Vis,0,0))
        cout<<"\n True";
}
