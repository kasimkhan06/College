#include<bits/stdc++.h>
using namespace std;

int fifo(vector<int>& pages, int cap)
{
    unordered_set<int> s; //actual frames
    queue<int> indexes; 

    int page_faults = 0;

    for(int i = 0 ; i < pages.size() ; i++)
    {
        //if there are free frames
        if(s.size() < cap)
        {
            //if the curr page req is not in page frames
            if(s.find(pages[i]) == s.end())
            {
                page_faults++;
                s.insert(pages[i]);
                indexes.push(pages[i]);
            }
        }
        else
        {
            if(s.find(pages[i]) == s.end())
            {
                int toremoved = indexes.front() ; indexes.pop();
                s.erase(toremoved);
                s.insert(pages[i]);
                indexes.push(pages[i]);
                page_faults++;
            }
        }
    }
    return page_faults;
}

int main()
{
    vector<int> pages{1,3,0,3,5,6,3} ; 
    int cap = 3;
    cout<<fifo(pages , cap);
    return 0;
}