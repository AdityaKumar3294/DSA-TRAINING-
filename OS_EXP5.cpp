#include <iostream>
#include <vector>
using namespace std;

struct Process {
    int pid;
    int arrival;
    int burst;
    int priority;
    int remaining;
    int completion;
    int turnaround;
    int waiting;
};

// Print Table
void printTable(const vector<Process> &procs) {
    cout << "\nPID\tAT\tBT\tPR\tCT\tTAT\tWT\n";
    for (auto &p : procs) {
        cout << p.pid << "\t" << p.arrival << "\t" << p.burst << "\t"
             << p.priority << "\t" << p.completion << "\t"
             << p.turnaround << "\t" << p.waiting << "\n";
    }
}

// Print Gantt Chart with PID
void printGantt(const vector<tuple<int,int,int>> &gantt) {
    cout << "\nGantt Chart:\n";
    for (auto &g : gantt) {
        cout << "| P" << get<0>(g) << " ";
    }
    cout << "|\n";

    cout << "0";
    for (auto &g : gantt) {
        cout << "\t" << get<2>(g);
    }
    cout << "\n";
}

// ---------------- NON-PREEMPTIVE ----------------
void PriorityNonPreemptive(vector<Process> procs) {
    int n = procs.size();
    vector<bool> done(n, false);
    vector<tuple<int,int,int>> gantt;

    int time = 0, completed = 0;

    while (completed < n) {
        int idx = -1;
        int bestPri = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (!done[i] && procs[i].arrival <= time) {
                if (procs[i].priority < bestPri) {
                    bestPri = procs[i].priority;
                    idx = i;
                }
            }
        }

        if (idx == -1) {
            time++;
            continue;
        }

        int start = time;
        time += procs[idx].burst;
        int end = time;

        procs[idx].completion = end;
        procs[idx].turnaround = end - procs[idx].arrival;
        procs[idx].waiting = procs[idx].turnaround - procs[idx].burst;

        gantt.push_back({procs[idx].pid, start, end});

        done[idx] = true;
        completed++;
    }

    cout << "\n--- Non-Preemptive Priority Scheduling ---\n";
    printTable(procs);

    double avgTAT = 0, avgWT = 0;
    for (auto &p : procs) {
        avgTAT += p.turnaround;
        avgWT += p.waiting;
    }

    cout << "\nAverage TAT: " << avgTAT / n;
    cout << "\nAverage WT: " << avgWT / n << "\n";

    printGantt(gantt);
}

// ---------------- PREEMPTIVE ----------------
void PriorityPreemptive(vector<Process> procs) {
    int n = procs.size();

    for (auto &p : procs) p.remaining = p.burst;

    vector<bool> done(n, false);
    vector<tuple<int,int,int>> gantt;

    int time = 0, completed = 0;
    int last = -1, start = 0;

    while (completed < n) {
        int idx = -1;
        int bestPri = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (!done[i] && procs[i].arrival <= time) {
                if (procs[i].priority < bestPri) {
                    bestPri = procs[i].priority;
                    idx = i;
                }
            }
        }

        if (idx == -1) {
            time++;
            continue;
        }

        if (last != idx) {
            if (last != -1) {
                gantt.push_back({procs[last].pid, start, time});
            }
            start = time;
            last = idx;
        }

        procs[idx].remaining--;
        time++;

        if (procs[idx].remaining == 0) {
            procs[idx].completion = time;
            procs[idx].turnaround = time - procs[idx].arrival;
            procs[idx].waiting = procs[idx].turnaround - procs[idx].burst;

            done[idx] = true;
            completed++;

            gantt.push_back({procs[idx].pid, start, time});
            last = -1;
        }
    }

    cout << "\n--- Preemptive Priority Scheduling ---\n";
    printTable(procs);

    double avgTAT = 0, avgWT = 0;
    for (auto &p : procs) {
        avgTAT += p.turnaround;
        avgWT += p.waiting;
    }

    cout << "\nAverage TAT: " << avgTAT / n;
    cout << "\nAverage WT: " << avgWT / n << "\n";

    printGantt(gantt);
}

// ---------------- MAIN ----------------
int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    vector<Process> procs(n);

    for (int i = 0; i < n; i++) {
        cout << "\nProcess " << i + 1 << ":\n";
        procs[i].pid = i + 1;

        cout << "Arrival Time: ";
        cin >> procs[i].arrival;

        cout << "Burst Time: ";
        cin >> procs[i].burst;

        cout << "Priority (lower = higher): ";
        cin >> procs[i].priority;
    }

    int choice;
    cout << "\n1. Non-Preemptive\n2. Preemptive\n3. Both\nChoice: ";
    cin >> choice;

    if (choice == 1) {
        PriorityNonPreemptive(procs);
    } else if (choice == 2) {
        PriorityPreemptive(procs);
    } else if (choice == 3) {
        PriorityNonPreemptive(procs);
        PriorityPreemptive(procs);
    } else {
        cout << "Invalid choice\n";
    }

    return 0;
}