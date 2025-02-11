/*
Given intervals (di, ti)
where di is the deadline and and ti is the time needed to complete the task i
Give a schedule which has minimum latness i.e max((si + ti) - di, 0) is minimum, where si is starting time of ith task in the schedule

https://www.youtube.com/watch?v=5d5tVcUAzJU
*/

#include <bits/stdc++.h>
using namespace std;

struct task{
    int deadline;
    int time;

    task() {};
    task(int deadline, int time): deadline(deadline), time(time) {}
};

int main(){
    int n;
    cin >> n;

    task intervals[n];
    for(int i = 0; i < n; i++){
        cin >> intervals[i].deadline >> intervals[i].time;
    }

    sort(intervals, intervals + n, [](const task& t1, const task& t2){
        return t1.deadline < t2.deadline;
    });

    int optimal_lateness = 0;
    int start_time = 0;
    for(int i = 0; i < n; i++){
        int finish_time = start_time + intervals[i].time;
        optimal_lateness = max(optimal_lateness, max(finish_time - intervals[i].deadline, 0));
        start_time = finish_time;
    }
    cout << "Minimum maximum lateness: " << optimal_lateness << "\n";
    cout << "Optimal schedule:\n";
    for(int i = 0; i < n; i++){
        cout << intervals[i].deadline << " " << intervals[i].time << "\n";
    }
}