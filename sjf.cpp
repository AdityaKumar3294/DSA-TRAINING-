#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;
struct Process {
    int id;
    int at;    
    int bt;      
    int rt;      
    int ct;    
    int tat;    
    int wt;     };
struct GanttEntry {
    int id;
    int endTime;};
int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;
    vector<Process> p(n);
    for (int i = 0; i < n; i++) {
        p[i].id = i + 1;
        cout << "Enter Arrival Time and Burst Time for P" << p[i].id << ": ";
        cin >> p[i].at >> p[i].bt;
        p[i].rt = p[i].bt;  }
    vector<GanttEntry> gantt;
    int completed = 0, current_time = 0, prev_pid = -1;
    while (completed != n) {
        int best_p = -1;
        int min_rt = 1e9;
        for (int i = 0; i < n; i++) {
            if (p[i].at <= current_time && p[i].rt > 0) {
                if (p[i].rt < min_rt) {
                    min_rt = p[i].rt;
                    best_p = i;  }
                if (p[i].rt == min_rt) {
                    if (p[i].at < p[best_p].at) best_p = i; } } }
        if (best_p != -1) {
            if (p[best_p].id != prev_pid) {
                gantt.push_back({p[best_p].id, current_time + 1});
            } else {
                gantt.back().endTime = current_time + 1;   }  
            p[best_p].rt--;
            prev_pid = p[best_p].id;
            current_time++;
            if (p[best_p].rt == 0) {
                p[best_p].ct = current_time;
                p[best_p].tat = p[best_p].ct - p[best_p].at;
                p[best_p].wt = p[best_p].tat - p[best_p].bt;
                completed++;
                prev_pid = -1;
            }
        } else {
            current_time++;
        }  }
    cout << "\nPID\tAT\tBT\tCT\tTAT\tWT\n";
    float total_wt = 0, total_tat = 0;
    for (const auto& proc : p) {
        cout << proc.id << "\t" << proc.at << "\t" << proc.bt << "\t"
             << proc.ct << "\t" << proc.tat << "\t" << proc.wt << endl;
        total_wt += proc.wt;
        total_tat += proc.tat; }
    cout << fixed << setprecision(2);
    cout << "\nAvg Waiting Time: " << total_wt / n;
    cout << "\nAvg Turnaround Time: " << total_tat / n << endl;
    cout << "\n--- Gantt Chart ---\n|";
    for (const auto& entry : gantt) cout << " P" << entry.id << " |";
    cout << "\n0";
    for (const auto& entry : gantt) cout << setw(5) << entry.endTime;
    cout << endl;
    return 0;}
