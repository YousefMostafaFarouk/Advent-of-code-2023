#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

const int N = 1e5 +5;
const int dx8[8] = {0, 0, 1, -1, 1, -1, -1, 1};
const int dy8[8] = {1, -1, 0, 0, 1, -1, 1, -1};
const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};
char direction[4] = {'r', 'l', 'd', 'u'};

bool visited[N];
vector<int> adj[N];
bool arr[N];

void dfs(int v, int& coun, int k, int xd )
{
    for(auto i : adj[v])
    {
        if(!visited[i])
        {
            visited[i] = true;
            dfs(i, coun, k, xd);
        }
    }
}

int main()
{   
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    std::ifstream inputFile("input.txt");

    std::string line;
    long long val = 0;

    while (std::getline(inputFile, line)) 
    {
        int firstNum = -1;
        int secondNum = -1;

        int left = 0;
        int right = line.size()-1;

        while(firstNum < 0 || secondNum < 0)
        {
            if(firstNum < 0 && (line[left] >= '0' && line[left] <= '9'))
                firstNum = line[left] - '0';
            
            if(secondNum < 0 && (line[right] >= '0' && line[right] <= '9'))
                secondNum = line[right] - '0';
            
            ++left;
            --right;
        }
        val += firstNum*10 + secondNum;
    }

    cout<<val<<endl;

    return 0;
}
