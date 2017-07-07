//
// Created by 孙启龙 on 2016/11/20.
//

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <sstream>
#include <fstream>
#include <stack>

using namespace std;

map<string, long long> array_table;
map<string,map< long long, long long>> array_value_table;


void partition(string origin,string &left,string &right)
{
    int index = origin.find_first_of('=',0);
    if(index!=-1)
    {
        left = origin.substr(0,index);
        right = origin.substr(index+1);
    }
    else
    {
        left = origin;
        right = "";
    }
}

void getArray(string str,string &name, string &value)
{
    int begin = str.find_first_of('[',0);
    int end = str.find_last_of(']');
    if(begin!=-1)
    {
        name = str.substr(0,begin);
        value = str.substr(begin+1,end-begin-1);
    }
    else
    {
        name = "";
        value = str;
    }
}

bool isValue(string value)
{
    int index = value.find_first_of('[',0);
    if(index!=-1)
        return true;
    return false;
}

long long calculateArray(string str)
{
    string name,value;
    getArray(str,name,value);
    stack<string> s;
    long long ans;
    while(name!="")
    {
        string left,right;
        getArray(value,left,right);
        if (array_table.count(name)==0)
        {
            return -1;
        }
        value = right;
        s.push(name);
        name = left;

    }
    ans = atoi(value.c_str());
    if(ans<0)
        return -1;
    while (!s.empty())
    {
        string left = s.top();
        long long num = array_table[left];
        if(ans>=num)
            return -1;
        if(array_value_table[left].count(ans)==0)
            return -1;
        ans = array_value_table[left][ans];
        s.pop();
    }
    return ans;
}

int main(int argc, char* argv[])
{
    string str;
    bool mark = false,isfirst = true;
    int num = 0;
    while(cin>>str)
    {
        if(str!=".")
        {
            mark = false;
            num++;
            string left,right;
            partition(str,left,right);
            if(right=="")
            {
                string name,value;
                getArray(left,name,value);
                array_table[name] = atoi(value.c_str());
            }
            else
            {
                string name, value;
                long long ans,temp;
                getArray(left,name,value);
                temp = calculateArray(value);
                ans = calculateArray(right);
                if(temp>=0&&temp<array_table[name]&&ans!=-1)
                {
                    array_value_table[name][temp] = ans;
                }
                else
                {
                    if(isfirst)
                    {
                        cout<<num<<endl;
                        isfirst = false;
                    }
                }
            }
        }
        else
        {
            array_table.clear();
            array_value_table.clear();
            if(mark)
                break;
            else
            {
                if(isfirst)
                    cout<<0<<endl;
                mark = true;
                isfirst = true;
                num = 0;
            }
        }
    }
    return 0;
}
