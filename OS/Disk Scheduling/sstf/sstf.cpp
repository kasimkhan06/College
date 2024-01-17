#include<bits/stdc++.h>
using namespace std;

vector<int> sstf(vector<int>& req, int n , int head , int maxh)
{
    vector<int> ans;
    ans.push_back(head);
    sort(req.begin() , req.end());
    int i = lower_bound(req.begin() , req.end() , head) - req.begin()  - 1;
    int j = upper_bound(req.begin() , req.end() , head) - req.begin() ;

    while(i != 0 or j!=req.size() - 1)
    {

        int dist1 = INT_MAX;
        int dist2 = INT_MAX;

        if(req[i] != 0)    dist1 = abs(head - req[i]);
        if(req[j] != maxh) dist2 = abs(head - req[j]);

        if(dist1 < dist2)
        {
            ans.push_back(req[i]);
            head = req[i];
            i--;
        }
        else
        {
            ans.push_back(req[j]);
            head = req[j];
            j++;
        }
    }
    return ans;
}

int main()
{
    int n , head , maxh;
    cin>> n >> head >> maxh;
    vector<int> req(n+1 , 0);
    for(int i = 1 ; i<=n ; i++) cin>>req[i];
    req.push_back(maxh);
    vector<int> ans = sstf(req ,  n , head , maxh);

    for(auto &it : ans)
        cout<<it<< " ";
    cout<<endl;

    return 0;
}