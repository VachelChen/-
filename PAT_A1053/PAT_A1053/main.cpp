//
//  main.cpp
//  PAT_A1053
//
//  Created by VachelChen on 2020/3/19.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn = 110;
int n,m,s,weight;
vector<vector<int> > ans;

struct node{
    int val;
    vector<int> v;
}tree[maxn];

bool cmp(vector<int> a, vector<int>  b){
    //要记得判断a，b有一方为空的情况，否则会出现段错误
    if(a.empty() || b.empty()){
        return a.empty();
    }
    int i = 0;
    int j = 0;
    while (i<a.size() && j<b.size() && a[i] == b[j]) {
        i++;j++;
    }
    if(a[i]>b[j])
        return  true;
    if(a[i] == b[j] && a.size()>b.size())
        return true;
    
    return false;
}

void dfs(node t, int total, vector<int> subAns){
    if(t.val + total > s)   return;
    if(t.val + total == s && t.v.size())  return ;
    if(t.val + total == s){
        subAns.push_back(t.val);
        ans.push_back(subAns);
        return ;
    }
    //正常找
    subAns.push_back(t.val);
    for (int i=0; i<t.v.size(); i++) {
        dfs(tree[t.v[i]], total+t.val, subAns);
    }
    subAns.pop_back();
}

int main(int argc, const char * argv[]) {
    cin >> n >> m >> s;
    for(int i=0; i<n; i++){
        cin >> weight;
        tree[i].val = weight;
    }
    
    int id,kids,weight;
    for(int i=0; i<m; i++){
        cin >> id >> kids;
        for(int j=0; j<kids; j++){
            cin >> weight;
            tree[id].v.push_back(weight);
        }
    }
    
    vector<int> subAns;
    dfs(tree[0], 0, subAns);
    
    sort(ans.begin(),ans.end(),cmp);
    
    for(int i=0; i<ans.size(); i++){
        for(int j=0;j<ans[i].size();j++){
            if(j == 0)
                cout<<ans[i][j];
            else
                cout<<" "<<ans[i][j];
        }
        cout<<endl;
    }
    
    return 0;
}
