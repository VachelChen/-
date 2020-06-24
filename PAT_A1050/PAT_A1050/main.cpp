//
//  main.cpp
//  PAT_A1050
//
//  Created by VachelChen on 2020/6/24.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <iostream>
using namespace std;


int main(int argc, const char * argv[]) {
    string s1,s2;
    getline(cin,s1);
    getline(cin,s2);
    for (int i=0; i<s2.size(); i++) {
        for (int j=0; j<s1.size(); j++) {
            while (s1[j] == s2[i]) {
                s1.erase(s1.begin()+j);
                //j++;
            }
        }
    }
    cout<<s1<<endl;
    return 0;
}
