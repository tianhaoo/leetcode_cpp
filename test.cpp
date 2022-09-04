#include"utils.h"

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

struct Node{
    char c;
    int id;
    Node(){
        c = 'a';
        id = 0;
    }
    Node(char a, int i){
        c = a;
        id = i;
    }
};


string traverse(vector<vector<Node>> &graph, Node node, vector<int> &ans){

    string res;
    for(auto neighbour: graph[node.id]){
        string neiRes = traverse(graph, neighbour, ans);
        res += neiRes;
    }
    res.push_back(node.c);
    unordered_set<char> s(res.begin(), res.end());
    ans[node.id] = s.size();
    return res;

}



int main(){
    int n;
    while(cin >> n){
        vector<vector<Node>> graph(n+1, vector<Node>());
        vector<int> parents(n+1);
        for(int i=2; i<n+1; ++i){
            cin >> parents[i];
        }
        string letters;
        cin >> letters;
        for(int i=2; i<n+1; ++i){
            graph[parents[i]].emplace_back(letters[i-1], i);
        }
        vector<int> ans(n+1);
        traverse(graph, Node(letters[0], 1), ans);
        for(int i=1; i<ans.size();++i){
            cout << ans[i];
            if(i !=n){
                cout << ' ';
            }
        }
        cout <<endl;










    }
    return 0;
}