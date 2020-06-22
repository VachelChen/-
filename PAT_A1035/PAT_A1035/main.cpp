//
//  main.cpp
//  PAT_A1035
//
//  Created by VachelChen on 2020/6/19.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
const int maxn = 1010;

struct user{
    string name,password;
}u[maxn];

vector<user> c;

int n;
int main(int argc, const char * argv[]) {
    cin >> n;
    for (int i=0; i<n; i++) {
        string a,b;
        cin >> a >> b;
        bool f = false;
        for (int j=0; j<b.size(); j++) {
            if (b[j] == '1') {
                f = true;
                b[j] = '@';
            }
            if (b[j] == '0') {
                f = true;
                b[j] = '%';
            }
            if (b[j] == 'l') {
                f = true;
                b[j] = 'L';
            }
            if (b[j] == 'O') {
                f = true;
                b[j] = 'o';
            }
        }
        if (f) {
            user x;
            x.name = a;
            x.password = b;
            c.push_back(x);
        }
        u[i].name = a;
        u[i].password = b;
    }
    if (c.size()>0) {
        cout<<c.size()<<endl;
        for (int i=0; i<c.size(); i++) {
            cout<<c[i].name<<" "<<c[i].password<<endl;
        }
    }
    else{
        if (n == 1) {
            cout<<"There is 1 account and no account is modified"<<endl;
        }
        else
            cout<<"There are "<<n<<" accounts and no account is modified"<<endl;
    }
        
    return 0;
}
