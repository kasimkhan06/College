#include<bits/stdc++.h>
using namespace std;

vector<int> isSafe(vector<vector<int>>& alloc , vector<vector<int>>& need , vector<int>& avail)
{
    int numProcess = alloc.size() , numResources = alloc[0].size();
    vector<bool> flags(numProcess , false);
    vector<int> ans;
    for(int iter = 0 ; iter < numProcess ; iter++)
    {
        for(int i = 0  ; i < numProcess ; i++)
        {
            if(flags[i]) continue;
            bool flag = true;
            for(int j = 0 ; j < numResources ; j++)
            {
                if(need[i][j] > avail[j]){
                    flag = false;
                    break;
                }
            }

            if(flag)
            {
                ans.push_back(i);
                flags[i] = true;
                for(int j = 0 ; j < numResources ; j++)
                    avail[j] += alloc[i][j];
            }
        }
    }

    //check if all processes were executed and there is no deadlock
    for(int i = 0 ; i < numProcess ; i++)
        if(!flags[i]) return {-1};
    return ans;
}

void __helper(vector<vector<int>>& allocation , vector<vector<int>>& maxNeed , vector<int>& resourceInstance , vector<vector<int>>& need , vector<int>& available)
{
    int numProcess = allocation.size() , numResources = allocation[0].size();
    for(int i = 0 ; i < numResources ; i++) available[i] = 0;
    for(int i = 0 ; i < numProcess ; i++ )
    {
        for(int j = 0 ; j < numResources ; j++)
            available[j] += allocation[i][j]; 
    }

    for(int i = 0 ; i < numResources ; i++) available[i] = resourceInstance[i] - available[i]; // calculatoin the allocation
    for(int i = 0 ; i < numResources ; i++) cout<<available[i] << " ";
    cout<<endl;
    //calculate need matrix
    for(int i = 0 ; i<numProcess ; i++)
    {
        for(int j = 0 ; j < numResources ; j++)
            need[i][j] = maxNeed[i][j] - allocation[i][j];
    }
}

void BankersAlgorithm(vector<vector<int>>& allocation , vector<vector<int>>& maxNeed , vector<int>& resourceInstance)
{
    //Bankers Algorithm
    int numProcess = allocation.size()  , numResources = resourceInstance.size();
    //step 1 : calculate the available 
    vector<vector<int>> need(numProcess , vector<int>(numResources , 0));
    vector<int> available(numResources , 0);

    __helper(allocation , maxNeed , resourceInstance , need , available);
    
    vector<int> seq = isSafe(allocation , need , available);
    if(seq[0] == -1)
        cout<<"No Safe State\n";
    else
    {
        cout<<"The Safe Sequence is : \n";
        for(int i = 0 ; i<numProcess ; i++)
        {
           cout<<"P"<<seq[i];
           if(i != numProcess-1)
                cout<<"=>";
        }
        cout<<endl;
    }

    while (true)
    {
        bool choice;
        cout<<"Enter 1 To req and 0 to Leave\n";
        cin>>choice;

        if(!choice) break;

        int pid;
        cout<<"Enter the pid to request\n";
        cin>>pid;

        vector<int> resource(numResources , 0);
        cout<<"Enter the Request\n";
        for(int i = 0 ; i< numResources ; i++) cin>>resource[i];
        for(int i = 0 ; i<numResources ; i++) allocation[pid][i] += resource[i];

        
        __helper(allocation , maxNeed , resourceInstance , need , available);
        vector<int> seq = isSafe(allocation , need , available);

        if(seq[0] == -1)
        {
            cout<<"No Safe State\n";
            for(int i = 0 ; i<numResources ; i++) allocation[pid][i] -= resource[i];
        }
        else
        {
            for(int i = 0 ; i<numProcess ; i++)
            {
                cout<<"P"<<seq[i];
                if(i != numProcess-1)
                        cout<<"=>";
            }
            cout<<endl;
        }
    }
}

void takeInupt(vector<vector<int>>& allocation , vector<vector<int>>& maxNeed , vector<int>& resourceInstance)
{
    int numProcess = allocation.size() , numResources = resourceInstance.size();
    cout<<"Taking input For the Allocation Matrix\n";
    for(int i = 0 ; i < numProcess ; i++)
    {
        cout<<"For Process "<<i+1<<" : ";
        for(int j = 0 ; j < numResources ; j++)
        {
            cin>>allocation[i][j];
        }
    }
    cout<<"Taking input For the Max Need Matrix\n";
    for(int i = 0 ; i < numProcess ; i++)
    {
        cout<<"For Process "<<i+1<<" : ";
        for(int j = 0 ; j < numResources ; j++)
        {
            cin>>maxNeed[i][j];
        }
    }
    cout<<"Enter the max Resource Instance for Each resource\n";
    for(int i = 0 ; i < numResources ; i++)
    {
        cout<<"For Resource "<<char('A' + i)<< " : ";
        cin>>resourceInstance[i]; 
    }
}

int main()
{
    //taking input 
    int numProcess , numResources;
    cout<<"Enter the Number Of Processes And Number Of Resources\n";
    cin>>numProcess>>numResources;

    //the requried matrices
    vector<vector<int>> allocation(numProcess , vector<int>(numResources , 0));
    vector<vector<int>> maxNeed(numProcess , vector<int>(numResources , 0));
    vector<int> resourceInstance(numResources , 0); //to store the max resources instance

    takeInupt(allocation , maxNeed , resourceInstance);
    BankersAlgorithm(allocation , maxNeed , resourceInstance);

    return 0;
}