#include <iostream>
#include <vector>
using namespace std;

// returns whether a state is safe state (or) not
bool safety_algo(const int n, const int m, const vector <vector <int>>& need, const vector <int>& available, const vector <vector <int> >& allocation){
    vector <int> work = available;
    vector <int> finish(n, false);

    bool changed;
    int i;
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
    return true;
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