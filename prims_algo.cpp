
#include <bits/stdc++.h>
using namespace std;
int n;
int maxKey(vector<int>key,vector<bool>mstSet) 
{ 
	int max = INT_MIN, max_index; 
	for (int v = 0; v < n; v++) 
		if (mstSet[v] == false && key[v] > max) 
			max = key[v], max_index = v; 

	return max_index; 
}
void printMST(vector<int>parent,vector<vector<int>>graph) 
{  
    int sum=0;
	for (int i = 1; i < n; i++) 
		sum+=graph[i][parent[i]]; 
    cout<<sum<<"\n";
} 
void primMST(vector<vector<int>>graph) 
{ 
    vector<int>parent(n); 
	vector<int>key(n); 
	vector<bool>mstSet(n); 
	for (int i = 0; i < n; i++) 
		key[i] = INT_MIN, mstSet[i] = false; 
	key[0] = 0;
	parent[0] = -1;
	for (int count = 0; count < n - 1; count++)
	{ 
		int u = maxKey(key, mstSet); 
		mstSet[u] = true; 
		for (int v = 0; v < n; v++) 
			if (graph[u][v] && mstSet[v] == false && graph[u][v] > key[v]) 
				parent[v] = u, key[v] = graph[u][v]; 
	} 

	printMST(parent, graph); 
} 

int main() 
{ 
    int d,i,j,k,sum=0;
    cin>>n>>d;
    int pts[n][d];
    vector<vector<int>>graph(n,vector<int>(n,0)); 
    for(i=0;i<n;i++)
    {
        for(j=0;j<d;j++)
        {
            cin>>pts[i][j];
        }
    }
     for(i=0;i<n;i++)
    {
        for(j=i;j<n;j++)
        {
            sum=0;
            for(k=0;k<d;k++)
            {
                sum+=abs(pts[i][k]-pts[j][k]);
            }
            graph[i][j]=sum;
            graph[j][i]=sum;
        }
    }
    /*for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cout<<graph[i][j]<<" ";
        }
        cout<<"\n";
    }*/
	primMST(graph); 
	return 0; 
} 

