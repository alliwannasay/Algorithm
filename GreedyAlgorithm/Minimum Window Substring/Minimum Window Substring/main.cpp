//
//  main.cpp
//  Minimum Window Substring
//
//  Created by zzqmyos on 17/5/17.
//  Copyright © 2017年 zzqmyos. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

string minWindow_wrong(string s, string t)
{
    int sl = int(s.size());
    int tl = int(t.size());
    if(sl == 0 || tl == 0) return "";
    int p1 = 0;
    int p2 = 0;
    int next = 0;
    int count = 0;
    int result = sl;
    string restr = "";
    string tmp;
    string tmpt = t;
    string tmpr;
    vector<int>tmpv;
    sort(tmpt.begin(),tmpt.end());
    while (1)
    {
        int res = t.find(s[p2]);
        if(res >= 0)
        {
            if(count == 0)
            {
                p1 = p2;
            }
            else if(count == 1)
            {
                next = p2;
            }
            count++;
            tmp.push_back(s[p2]);
            tmpv.push_back(p2);
        }
        if(count == tl)
        {
            tmpr = tmp;
            sort(tmpr.begin(),tmpr.end());
            if(tmpr == tmpt)
            {
                if(p2-p1+1 <= result)
                {
                    restr = s.substr(p1,p2-p1+1);
                    result = p2-p1+1;
                }
            }
            p1 = next;
            reverse(tmp.begin(), tmp.end());
            tmp.pop_back();
            reverse(tmp.begin(), tmp.end());
            reverse(tmpv.begin(), tmpv.end());
            tmpv.pop_back();
            reverse(tmpv.begin(), tmpv.end());
            count--;
            next = tmpv[1];
        }
        p2++;
        if(p2 == sl) break;
    }
    return restr;
}

//这个方法不对。忽略了一种情况：窗口中有在T中的字母，但是是干扰字母。
//能过193/268个test case也是奇迹。

string minWindow(string s, string t)
{
    int sl = int(s.size());
    int tl = int(t.size());
    if(sl == 0 || tl == 0) return "";
    vector<int>thash;
    vector<int>shash;
    thash.assign(129, 0);
    shash.assign(129, 0);
    for(int i = 0; i < tl; i++)
    {
        thash[t[i]]++;
    }
    int start = 0;
    int found = 0;
    int result = sl;
    string res = "";
    for(int i = 0; i < sl; i++)
    {
        shash[s[i]]++;
        if(shash[s[i]] <= thash[s[i]])
        {
            found++;
        }
        if(found == tl)
        {
            while(shash[s[start]] > thash[s[start]])
            {
                shash[s[start]]--;
                start++;
            }
            if(i-start+1 <= result)
            {
                res = s.substr(start,i-start+1);
                result = i-start+1;
            }
            shash[s[start]]--;
            start++;
            found--;
        }
    }
    return res;
}

//从这个题学到的方法：
//1.窗口移动大法，一个前指针一个后指针指区间
//2.出现次数法：适用于字串间隔匹配这样的问题




int main(int argc, const char * argv[]) {
    string s = "cabwefgewcwaefgcf";
    string t = "cae";
    cout<<minWindow(s,t)<<endl;
    return 0;
}
