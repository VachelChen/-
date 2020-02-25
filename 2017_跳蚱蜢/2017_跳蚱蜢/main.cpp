//
//  main.cpp
//  2017_跳蚱蜢
//
//  Created by VachelChen on 2020/2/24.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <iostream>
#include <queue>
#include <map>
using namespace std;

string start = "012345678";
string over = "087654321";

struct state{
    int deep;
    string str;
    state(int _deep,string _str){
        deep = _deep;
        str = _str;
    }
};

string swap1(string str){
    string s = str;
    int zero = s.find("0");
    int change = (zero - 2 + 9)%9;
    char temp;
    temp = s[zero];
    s[zero] = s[change];
    s[change] = temp;
    return s;
}

string swap2(string str){
    string s = str;
    int zero = s.find("0");
    int change = (zero - 1 + 9)%9;
    char temp;
    temp = s[zero];
    s[zero] = s[change];
    s[change] = temp;
    return s;
}

string swap3(string str){
    string s = str;
    int zero = s.find("0");
    int change = (zero + 1 + 9)%9;
    char temp;
    temp = s[zero];
    s[zero] = s[change];
    s[change] = temp;
    return s;
}

string swap4(string str){
    string s = str;
    int zero = s.find("0");
    int change = (zero + 2 + 9)%9;
    char temp;
    temp = s[zero];
    s[zero] = s[change];
    s[change] = temp;
    return s;
}

queue <state> q;
map <string,int> visit;

int main(int argc, const char * argv[]) {
    q.push(state(0,start));
    int ans = 0;
    while(!q.empty()){
        
        state temp = q.front();
        q.pop();
        cout<<temp.deep<<endl;
        if(temp.str == over) {ans = temp.deep; break;}
        
        visit[temp.str]++;
        
        if(!visit.count(swap1(temp.str)))   q.push(state(temp.deep+1,swap1(temp.str)));
        if(!visit.count(swap2(temp.str)))   q.push(state(temp.deep+1,swap2(temp.str)));
        if(!visit.count(swap3(temp.str)))   q.push(state(temp.deep+1,swap3(temp.str)));
        if(!visit.count(swap4(temp.str)))   q.push(state(temp.deep+1,swap4(temp.str)));
        
    }
    cout<<"The ans is :"<<ans<<endl;
    return 0;
}
