//
//  main.cpp
//  2015_手链样式
//
//  Created by VachelChen on 2020/2/20.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector <string> v;

int main(int argc, const char * argv[]) {
    string s = "rrrwwwwyyyyy";
    int ans=0;
    do{
        int i;
        for(i=0;i<v.size();i++){
            if(v[i].find(s)!=string::npos)  break;
        }
        if(i!=v.size()) continue;
        ans++;
        string s2=s+s;
        v.push_back(s2);
        reverse(s2.begin(), s2.end());
        v.push_back(s2);
    }while(next_permutation(s.begin(),s.end()));
    cout<<ans<<endl;
    return 0;
}
