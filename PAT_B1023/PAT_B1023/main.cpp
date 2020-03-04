//
//  main.cpp
//  PAT_B1023
//
//  Created by VachelChen on 2020/3/4.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <iostream>
#include <sstream>
using namespace std;

string i2s(int x){
    string str;
    stringstream ss;
    ss << x;
    ss >> str;
    return str;
}

int main(int argc, const char * argv[]) {
    int value[10];
    string ans="";
    for (int i=0; i<10; i++) {
        cin >> value[i];
    }
    for (int i=0; i<10; i++) {
        for(int j=0;j<value[i];j++)
            ans += i2s(i);
    }
    if(ans[ans.size()-1]==0){
        cout<<"0"<<endl;
        return 0;
    }
    if(ans.find('0') == 0){
        for(int i=1;i<10;i++){
            if(ans.find(i+'0') != string::npos){
                char temp;
                temp = ans[ans.find(i+'0')];
                ans[ans.find(i+'0')] = '0';
                ans[0] = temp;
                break;
            }
        }
        
    }
    cout<<ans<<endl;
    return 0;
}
