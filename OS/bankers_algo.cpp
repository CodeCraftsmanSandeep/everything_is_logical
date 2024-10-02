#include <iostream>
#include <vector>
using namespace std;

// returns whether a state is safe state (or) not
// time complexity: O(n*n*m) per request !!!!
// space complexity: O(m + n) per request !!!!
bool safety_algo(const int n, const int m, const vector <vector <int>>& need, const vector <int>& available, const vector <vector <int> >& allocation){
    vector <int> work = available;
    vector <int> finish(n, false);

    bool changed;
    int i;
    vector <int> safety_seq;
    do{
        changed  = false;
        for(int i = 0; i < n; i++){ // n times 
            if(finish[i] == false){
                bool less_than_or_equal_to = true;
                for(int j = 0; j < m; j++){ // looping m times
                    if(need[i][j] > work[j]){
                        less_than_or_equal_to = false;
                        break;
                    }
                }
                if(less_than_or_equal_to == false) break;
                changed = true;
                safety_seq.push_back(i);
                for(int j = 0; j < m; j++) work[j] += allocation[i][j]; // looping n time
                finish[i] = true;
            }
        }
    }while(!changed); // O(n) time looping 
    // total time complexity: O(n * n * m) 
    // for checking whether a state is safe state (or) not

    for(int i = 0; i < n; i++){
        if(finish[i] == false) return false;
    }

    cout << "Safety sequence:\n";
    for(int i = 0; i < n; i++) cout << safety_seq[i] << " ";
    cout << "\n";
    
    return true;
}

// returns true if the request is granted
// returns false if the request is not graneted
// time complexity: O(n*n*m) per request !!!!
// space complexity: O(m + n) per request !!!! 
bool resource_request_algo(int i, int n, int m, vector <int>& available, vector <vector <int> >& request, vector <vector <int>>& need, vector <vector <int>>& allocated){
    // O(m) time
    for(int j = 0; j < m; j++){
        if(request[i][j] > need[i][j]){
            cout << "Error: Requesting more than maximum limit\n";
            return false;
        }
    }

    // O(m) time
    for(int j = 0; j < m; j++){
        if(request[i][j] > available[j]){
            cout << "Error: Requesting more than available\n";
            return false;
        }
    }

    // O(m) time
    // grant the request
    for(int j = 0; j < m; j++) need[i][j] -= request[i][j];
    for(int j = 0; j < m; j++) available[j] -= request[i][j];
    for(int j = 0; j < m; j++) allocated[i][j] += request[i][j];

    // O(n*n*m) time
    // check for stead state
    if(safety_algo(n, m, need, available, allocated)) return true;

    // O(m) time
    // the state is not safe
    // revoke the operations
    for(int j = 0; j < m; j++) need[i][j] += request[i][j];
    for(int j = 0; j < m; j++) available[j] += request[i][j];
    for(int j = 0; j < m; j++) allocated[i][j] -= request[i][j];
}



int main(){
    int n, m;
    // n - number of processes (or) threads
    // m - number of types of resources

    vector <vector <int> > max(n, vector <int> (m, 0));
    vector <int> available(m, 0);
    vector <vector <int> > allocated(n, vector <int> (m, 0));
    vector <vector <int> > need(n, vector <int> (m, 0));
}