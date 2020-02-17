#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <cstring>
#include <cstdlib>
#include <cmath>
using namespace std;
//Remove invalid characters such as spaces and tabs in strings

int player[12][12];
int firstPublish=1;
map <string,int>m;

string Trim(string& str)
{
    //str.find_first_not_of(" \t\r\n"),Starting at index 0 in the string str, returning the first mismatched position "\t\r\n"
    str.erase(0,str.find_first_not_of(" \t\r\n"));
    str.erase(str.find_last_not_of(" \t\r\n") + 1);
    return str;
}

//Convert the string into float
float s2i(string str){
    stringstream ss;
    float x;
    ss << str;
    ss >> x;
    return x;
}

void output(){
    cout<<"Passing Matrix:"<<endl;
    for(int i=1;i<=11;i++){
        for(int j=1;j<=11;j++){
            cout<<player[i][j]<<"\t";
        }
    cout<<endl;
    }
}

int main()
{
    ifstream fin("fullevents.csv"); //Open file stream operation
    string line;
    while (getline(fin, line))   //Read the entire line
    {
        istringstream sin(line); //Read an entire line of string line into the string stream istringstream
        vector<string> fields;
        string field;
        while (getline(sin, field, ','))
        {
            fields.push_back(field);
        }
        string matchID = Trim(fields[0]);   //get MatchID
        string teamID = Trim(fields[1]);    //get TeamID
        string oID = Trim(fields[2]);       //get OriginPlayerID
        string dID = Trim(fields[3]);       //get DestinationPlayerID
        string MP = Trim(fields[4]);        //get MatchPeriod
        string eventTime = Trim(fields[5]); //get EventTime
        string type = Trim(fields[6]);      //get EventType
        string subtype = Trim(fields[7]);   //get EventSubType
        string ox = Trim(fields[8]);        //get EventOrigin_x
        string oy = Trim(fields[9]);        //get EventOrigin_y
        string dx = Trim(fields[10]);       //get EventDestination_x
        string dy = Trim(fields[11]);       //get EventDestination_y
        
        if(matchID != "1")    continue;
        if(teamID != "Huskies" ) continue;
    
        if(type == "Substitution"){
            m[dID] = m[oID];
            cout<<"Substitution: "<<oID<<"->"<<dID<<endl;
        }
        
        if(m.count(oID)<1 && m.size()<11){
            m[oID]=firstPublish++;
            cout<<"No."<<m.size()<<"\tPlayer:"<<oID<<endl;
        }
        if(dID=="")  continue;
        if(m.count(dID)<1 && m.size()<11){
            m[dID]=firstPublish++;
            cout<<"No."<<m.size()<<"\tPlayer:"<<dID<<endl;
        }
        player[m[oID]][m[dID]]++;
    
    }
    output();
    
    return EXIT_SUCCESS;
}

