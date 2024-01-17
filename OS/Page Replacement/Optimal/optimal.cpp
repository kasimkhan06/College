#include<bits/stdc++.h>
using namespace std;

int OptimalPr(vector<int>& pages , int cap)
{
    unordered_set<int> st;
    unordered_map<int , deque<int>> indices;

    int page_faluts = 0;
    
    //store the occurences
    for(int i = 0 ; i<pages.size() ; i++) indices[pages[i]].push_back(i);
    

    for(int i = 0 ; i<pages.size(); i++)
    {
        //free frames are available
        if(st.size() < cap)
        {
            if(st.find(pages[i]) == st.end())
            {
                page_faluts++;
                st.insert(pages[i]);
            }
        }
        else
        {
            //no free frames are present 
            if(st.find(pages[i]) == st.end())
            {
                page_faluts++;
                int mx = INT_MIN , page;
                for(auto &it : st)
                {
                    //for every element find the next occ 
                    int next_occ = INT_MAX;
                    if(!indices[it].empty())
                        next_occ = indices[it].front();
                    if(next_occ > mx)
                    {
                        mx = next_occ;
                        page = it;
                    }
                }
                st.erase(page);
                st.insert(pages[i]);
            }
        }
        if(!indices[pages[i]].empty()) indices[pages[i]].pop_front();

    }
    return page_faluts;
}

int main()
{
    vector<int> pages{4,2,3,0,3,2,1,7,5,5,1,2,0,3,0,2,0,1,7,0,7};
    int cap = 4;
    cout<<OptimalPr(pages ,cap);
    return 0;
}