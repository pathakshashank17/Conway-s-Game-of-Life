#include<bits/stdc++.h>
#include<windows.h>

using namespace std;

// Count AliveNeighbours
long countAliveNeighbours (long i,long j,long row,long col,long **state) {
    long count=0;
    if (i-1>=0 && j-1>=0 && state[i-1][j-1]==1)
        count++;
    if (i-1>=0 && state[i-1][j]==1)
        count++;
    if (i-1>=0 && j+1<=col-1 && state[i-1][j+1]==1)
        count++;
    if (j+1<=col-1 && state[i][j+1]==1)
        count++;
    if (i+1<=row-1 && j+1<=col-1 && state[i+1][j+1]==1)
        count++;
    if (i+1<=row-1 && state[i+1][j]==1)
        count++;
    if (i+1<=row-1 && j-1>=0 && state[i+1][j-1]==1)
        count++;
    if (j-1>=0 && state[i][j-1]==1)
        count++;
    return count;
}
// Generate NextState using game rules
void genNextState (long row,long col,long **state) {
    long neighbours,neighbourArray[row][col];
    for (long i=0;i<row;i++) {
        for (long j=0;j<col;j++) {
            neighbourArray[i][j]=countAliveNeighbours(i,j,row,col,state);
        }
    }
    for (long i=0;i<row;i++) {
        for (long j=0;j<col;j++) {
            if (state[i][j]==1) {
                if (neighbourArray[i][j]<2 || neighbourArray[i][j]>3)
                    state[i][j]=0;
                else if (neighbourArray[i][j]==2 || neighbourArray[i][j]==3)
                    continue;
            }
            else {
                if (neighbourArray[i][j]==3)
                    state[i][j]=1;
            }
        }
    }
}
// Driver
int main() {

    long row,col; cout<<"Enter Number of rows : "; cin>>row; cout<<"Enter Number of columns : "; cin>>col;
    
    long **state=new long *[row];
    
    for (long i=0;i<row;i++)
        state[i]=new long[col];

    // User input for initial state
    cout<<"Enter initial state : \n";
    for (long i=0;i<row;i++) {
        for (long j=0;j<col;j++) {
            cin>>state[i][j];
        }
    }
    long generations; cout<<"Enter number of Generations : "; cin>>generations;
    
    // Running Game
    while (generations--) {
        for (long i=0;i<row;i++) {
            for (long j=0;j<col;j++) {
                if (state[i][j]==1)
                    cout<<"|O|";
                else 
                    cout<<"|-|";
            }
            cout<<endl;
        }
        genNextState(row,col,state);
        Sleep(250);
        system("CLS");
        }
    return 0;
}