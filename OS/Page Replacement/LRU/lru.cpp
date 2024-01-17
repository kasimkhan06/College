#include<bits/stdc++.h>
using namespace std;

int LRU(vector<int>& pages , int cap)
{
    unordered_set<int> s;
    unordered_map<int , int> indexes;
    int page_faluts = 0;

    for(int i=0 ; i<pages.size() ; i++)
    {
        //if frames are empty
        if(s.size() < cap)
        {
            //if the pages doesnt exist in the frames 
            if(s.find(pages[i]) == s.end())
            {
                page_faluts++;
                s.insert(pages[i]);
                indexes[pages[i]] = i;
            }
            else
                indexes[pages[i]] = i;
        }
        else
        {
            //if the page doent exist use lru
            if(s.find(pages[i]) == s.end())
            {
                page_faluts++;
                int minInd = INT_MAX , page;
                for(auto &it : s)
                {
                    if(indexes[it] < minInd)
                    {
                        minInd = indexes[it];
                        page = it;// getting the minum index page
                    }
                }
                //replace the page 
                s.erase(page);
                s.insert(pages[i]);
                indexes[pages[i]] = i;
            }
            else
                indexes[pages[i]] = i;
        }
    }

    return page_faluts;
}

int main()
{
    vector<int> pages{4 , 2 , 3 , 0 , 3 , 2 , 1 , 7 , 5 , 5 , 1 , 2, 0 , 3  , 0  , 2, 0  , 1 , 7 , 0 , 7} ;
    int cap = 6;
    cout<<LRU(pages,cap);
    return 0;
}