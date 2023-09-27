#include<bits/stdc++.h>
using namespace std;

class Process
{
    public:
    static int count;
    char id;
    int at , bt , ct , tat , wt , prior;

    Process()
    {   //taking input for the problem
        cin >> this -> at >> this -> bt >> this -> prior ;
        this -> id = 'A' + count++ ;
    }
};
int Process :: count = 0;

class compare
{
    public:
    bool operator() (Process a , Process b)
    {
        return a.prior > b.prior;
    }
};

void display(vector<Process> &p)
{    
    int n = p.size();
    cout<<"\nGantte Chart : \n";
    for(int i = 0 ; i < n ; i++)
    {
        cout<<left<<setw(6)<<"|"<<p[i].id<<"     ";
    }
    cout<<"|"<<endl;
    cout<<p[0].at<<"           ";
    for(int i = 0 ; i < n ; i++)
    {
        cout << left << setw(12) << p[i].ct;
    }
    cout<<endl<<endl;

    float avg_wt = 0 , avg_tat = 0;
    cout<<left<<setw(20)<<"Process Id"<<setw(20)<<"Arrival Time"<<setw(20)<<"Burst Time"<<setw(20)<<"Priority"<<setw(20)<<"Completion Time"<<setw(20)<<"Turn Around Time"<<setw(20)<<"Waiting Time"<<endl;
    for(int i = 0 ; i < n ; i++)
    {
        cout<<setw(20)<<p[i].id<<setw(20)<<p[i].at<<setw(20)<<p[i].bt<<setw(20)<<p[i].prior<<setw(20)<<p[i].ct<<setw(20)<<p[i].tat<<setw(20)<<p[i].wt<<endl;
        avg_wt += p[i].wt;
        avg_tat += p[i].tat;
    }
    avg_tat /= n ;
    avg_wt /= n ;
    cout<<"Avg_WT : "<<avg_wt<<endl;
    cout<<"Avg_TAT : "<<avg_tat<<endl;
}

void SJF(vector<Process>& p)
{
    int n = p.size();
    sort(p.begin() , p.end() , [&](Process a , Process b){return a.at < b.at;}); // We should konw where is the next smallest arrival time
    priority_queue<Process , vector<Process> , compare> pq;

    vector<Process> ans; // to Store the final ans
    int index = 0  , start = p[index] . at; // starting config 

    while(index < n or !pq.empty())
    {
        while(index < n and p[index].at <= start)
        {
            pq.push(p[index]);
            index++;
        }

        if(!pq.empty())
        {
            Process curr = pq.top();
            pq.pop();

            //normal calculations
            curr.ct = start + curr.bt;
            curr.tat = curr.ct - curr.at;
            curr.wt = curr.tat - curr.bt;

            start += curr.bt;
            ans.push_back(curr);
        }
        if(index < n  and p[index].at > start) // if there is a gap i.e we have not reached the arrival time of the next process in time
            start = p[index].at;
    }
    display(ans);
}
  

  
int main()
{
    int n;
    cout<<"Enter the Number of Processes\n";
    cin>>n;

    cout<<"Enter the Arrival Time and Burst Time and Priority Of Each Process\n";
    vector<Process> p(n);

    SJF(p);

    return 0;
}