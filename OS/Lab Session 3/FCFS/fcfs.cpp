#include<bits/stdc++.h>
using namespace std;

class Process
{
    public:
    static int count;
    char id;
    int at , bt , ct , tat , wt; 


    Process()
    {   //taking input for the problem
        cin >> this -> at >> this -> bt ;
        this -> id = 'A' + count++ ;
    }
};
int Process :: count = 0;

void display(Process *p , int n)
{
    cout<<"\nGantte Chart : \n";
    for(int i = 0 ; i < n ; i++)
    {
        cout<<left<<setw(6)<<"|"<<p[i].id<<"     ";
    }
    cout<<"|";
    cout<<endl;
    cout<<p[0].at<<"           ";
    for(int i = 0 ; i < n ; i++)
    {
        cout << left << setw(12) << p[i].ct;
    }
    cout<<endl<<endl;

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

void FCFS(Process * p , int n)
{
    sort(p , p+n , [&](Process a , Process b){return a.at < b.at;}); // sort according to the arrival time 

    int sum = p[0].at;
    for(int i = 0 ; i < n ; i++)
    {
        sum = sum + p[i].bt;
        p[i].ct = sum;
        p[i].tat = p[i].ct - p[i].at;
        p[i].wt  = p[i].tat - p[i].bt;

        if(i == n-1 and sum < p[i+1].at) // To check if the next process is ready or not if not jump to that time
            sum = p[i+1].at;
    }
    display(p , n);
}

int main()
{
    int n;
    cout<<"Enter the Number of Processes\n";
    cin>>n;

    cout<<"Enter the Arrival Time and Burst Time Of Each Process\n";
    Process* p = new Process[n];
    
    FCFS(p , n);

    return 0;
}