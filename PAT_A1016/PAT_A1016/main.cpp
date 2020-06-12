//
//  main.cpp
//  PAT_A1016
//
//  Created by VachelChen on 2020/6/9.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <iostream>
#include <sstream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int s2i(string str){
    int x;
    stringstream ss;
    ss << str;
    ss >> x;
    return x;
}

const int maxn = 1010;
int cost[30];
int n;
struct record{
    string name;
    int mm1;
    int dd;
    int hh;
    int mm2;
    string word;
}r[maxn];

struct timerecord{
    int month;
    int startd,starth,startm;
    int endd,endh,endm;
    int costtime;
    double costmoney;
    timerecord(){
        costtime = 0;
        costmoney = 0;
    }
};

map<string,vector<timerecord>> pr;

bool cmp(record a, record b){
    if (a.name != b.name) return a.name < b.name;
    else if(a.dd != b.dd) return a.dd < b.dd;
    else if(a.hh != b.hh) return a.hh < b.hh;
    else return a.mm2 < b.mm2;
}

int main(int argc, const char * argv[]) {
    for (int i=0; i<24; i++) {
        cin >> cost[i];
    }
    cin >> n;
    for (int i=0; i<n; i++) {
        string name,date,state;
        cin >> name >> date >> state;
        int a,b,c,d;
        a = s2i(date.substr(0,2));
        b = s2i(date.substr(3,2));
        c = s2i(date.substr(6,2));
        d = s2i(date.substr(9,2));
        r[i].name = name;
        r[i].mm1 = a;   r[i].dd = b;    r[i].hh = c;    r[i].mm2 = d;
        r[i].word = state;
    }
    sort(r, r+n, cmp);
    for (int i=0; i<n-1; i++) {
        if(r[i].name == r[i+1].name && r[i].word == "on-line" && r[i+1].word == "off-line"){
            timerecord temp;
            temp.month = r[i].mm1;
            temp.startd = r[i].dd;  temp.starth = r[i].hh;  temp.startm = r[i].mm2;
            temp.endd = r[i+1].dd;  temp.endh = r[i+1].hh;  temp.endm = r[i+1].mm2;
            int starttime = temp.startd*10000 + temp.starth*100 + temp.startm;
            int endtime = temp.endd*10000 + temp.endh*100 + temp.endm;
            while (starttime != endtime) {
                temp.costtime++;
                starttime++;
                temp.costmoney += cost[starttime/100%100]*0.01;
                if(starttime%100 == 60){
                    starttime = starttime/100*100+100;
                }
                if (starttime/100%100 == 24) {
                    starttime = starttime/10000*10000+10000;
                }
            }
            pr[r[i].name].push_back(temp);
        }
        
    }
    for (map<string,vector<timerecord>>::iterator it=pr.begin(); it!=pr.end(); it++) {
        cout<<it->first<<" ";
        printf("%02d\n",it->second.front().month);
        double total = 0;
        for (int i=0; i<it->second.size(); i++) {
            printf("%02d:%02d:%02d ",it->second[i].startd,it->second[i].starth,it->second[i].startm);
            printf("%02d:%02d:%02d ",it->second[i].endd,it->second[i].endh,it->second[i].endm);
            cout<<it->second[i].costtime<<" ";
            printf("$%.2f\n",it->second[i].costmoney);
            total += it->second[i].costmoney;
        }
        printf("Total amount: $%.2f\n",total);
    }
    
    return 0;
}
