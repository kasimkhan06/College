#include<bits/stdc++.h>
using namespace std;

class Process
{
    public:
    static int count;
    char id;
    int at , bt , ct , tat , wt , orig_bt , prior; 


    Process()
    {   //taking input for the problem
        cin >> this -> at >> this -> bt >> this -> prior ;
        this -> id = 'A' + count++ ;
        this -> orig_bt = this -> bt ;
    }
};
int Process :: count = 0;

class compare
{
    public:
    bool operator() (Process &a , Process &b)
    {
        return a.prior > b.prior;
    }
};

void display(vector<Process> &p , vector<pair<char , int >> & gantte)
{    
    int n = p.size();
    int m  = gantte.size();
    cout<<"\nGantte Chart : \n";
    for(int i = 0 ; i < m ; i++)
    {
        cout<<left<<setw(6)<<"|"<<gantte[i].first<<"     ";
    }
    cout<<"|"<<endl;
    cout<<"            ";
    for(int i = 0 ; i < m ; i++)
    {
        cout << left << setw(12) << gantte[i].second;
    }
    cout<<endl<<endl;


    sort(p.begin() , p.end() , [&](Process a , Process b){return a.id < b.id;});// for printing purpose
    float avg_wt = 0 , avg_tat = 0;
    cout<<left<<setw(20)<<"Process Id"<<setw(20)<<"Arrival Time"<<setw(20)<<"Burst Time"<<setw(20)<<"Completion Time"<<setw(20)<<"Turn Around Time"<<setw(20)<<"Waiting Time"<<endl;
    for(int i = 0 ; i < n ; i++)
    {
        cout<<setw(20)<<p[i].id<<setw(20)<<p[i].at<<setw(20)<<p[i].bt<<setw(20)<<p[i].ct<<setw(20)<<p[i].tat<<setw(20)<<p[i].wt<<endl;
        avg_wt += p[i].wt;
        avg_tat += p[i].tat;
    }
    avg_tat /= n ;
    avg_wt /= n ;
    cout<<"Avg_WT : "<<avg_wt<<endl;
    cout<<"Avg_TAT : "<<avg_tat<<endl;
}

void Priority(vector<Process>& p)
{
    int n = p.size();
    vector<pair<char, int>> gantte;
    sort(p.begin() , p.end() , [&](Process a , Process b){return a.at < b.at;});    

    //Intuition : Run every Process until a new Process has arrived , rest remains same 
    vector<Process> ans;
    priority_queue<Process , vector<Process> , compare> pq;

    //initialize the start timer and index
    int index = 0  , start = p[index].at;

    while(index < n or !pq.empty())
    {
        // start adding the Processes which has arrived 
        while( index < n  and p[index].at <= start )
        {
            pq.push(p[index]);
            index++; // basically going to next process , since we have sorted it we know that the next smalles process is next
        }
        // index will at position where the process has not yet arrived or all processes are done !
        
        if(!pq.empty())
        {
            Process curr = pq.top(); pq.pop(); // process which has lowest burst time
            int time_for_nxt_arr = curr.bt ; // to calculate after what burst time next process will arrive
            if(index < n )
                time_for_nxt_arr = p[index].at - start; // we will run the curr process for this much time only
            
            if( curr.bt <= time_for_nxt_arr ) // this means we can finish this process , we will add this in our answer
            {
                //normal calculations
                curr.ct = start + curr.bt;
                curr.tat = curr.ct - curr.at;
                curr.wt = curr.tat - curr.orig_bt;

                start = start + curr.bt;
                
                curr.bt = curr.orig_bt; //restrore the original burst time , not required  

                gantte.push_back({curr.id , curr.ct});
                ans.push_back(curr);
            }
            else
            {
                //This means the Process is still remaining
                curr.ct = start + time_for_nxt_arr;
                gantte.push_back({curr.id , curr.ct});

                curr.bt = curr.bt - time_for_nxt_arr;
                start = start + time_for_nxt_arr;
                pq.push(curr);
            }
            if(pq.empty() and index < n and p[index].at > start )
                start = p[index].at;

        } 
    }  
    display(ans , gantte);
}

int main()
{
    int n;
    cout<<"Enter the Number of Processes\n";
    cin>>n;

    cout<<"Enter the Arrival Time and Burst Time and Priority Of Each Process\n";
    vector<Process> p(n);

    Priority(p);

    return 0;
}