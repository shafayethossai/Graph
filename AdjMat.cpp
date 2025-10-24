#include<iostream>

using namespace std;
int main()
{
    int n;
    cout<< "Enter number of nodes:";
    cin>>n;
    int graph[n][n];

     for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j)
                graph[i][j]=0;
            else
                graph[i][j]=-1;
        }
    }
    int e;
    cout<< "Enter the number of Edges:";
    cin>>e;
    for (int i=0;i<e;i++){
        int n1,n2;
        cin>>n1>>n2;
        graph[n1][n2]=1;
        graph[n2][n1]=1;
    }

    for (int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<graph[i][j]<<"\t";
        }
        cout<< "\n";
    }



}
