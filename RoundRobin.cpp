#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>
#include <iomanip>
using namespace std;

struct Process {
    int pid;
    int arrival;
    int burst;
    int remaining;
    int completion;
    int turnaround;
    int waiting;
};

int main() {
    int n;
    cout << "Enter number of processes: ";
    if (!(cin >> n) || n <= 0) {
        cerr << "Invalid process count\n";
        return 1;
    }

    vector<Process> procs(n);

    for (int i = 0; i < n; i++) {
        procs[i].pid = i + 1;

        cout << "Enter arrival time for P" << procs[i].pid << ": ";
        cin >> procs[i].arrival;

        cout << "Enter burst time for P" << procs[i].pid << ": ";
        cin >> procs[i].burst;

        if (procs[i].arrival < 0 || procs[i].burst <= 0) {
            cerr << "Arrival must be >=0 and burst >0." << endl;
            return 1;
        }

        procs[i].remaining = procs[i].burst;
        procs[i].completion = 0;
        procs[i].turnaround = 0;
        procs[i].waiting = 0;
    }

    int quantum;
    cout << "Enter time quantum: ";
    cin >> quantum;

    if (quantum <= 0) {
        cerr << "Quantum should be >0" << endl;
        return 1;
    }

    auto cmpArrival = [](const Process &a, const Process &b) {
        if (a.arrival != b.arrival)
            return a.arrival < b.arrival;
        return a.pid < b.pid;
    };

    vector<Process*> order;
    for (auto &p : procs)
        order.push_back(&p);

    sort(order.begin(), order.end(), cmpArrival);

    queue<Process*> ready;

    int currentTime = 0;
    int idx = 0;
    int finished = 0;

    vector<tuple<int,int,int>> gantt;

    while (finished < n) {

        while (idx < n && order[idx]->arrival <= currentTime) {
            ready.push(order[idx]);
            idx++;
        }

        if (ready.empty()) {
            if (idx < n) {
                currentTime = order[idx]->arrival;
                continue;
            }
            break;
        }

        Process *cp = ready.front();
        ready.pop();

        int start = currentTime;

        int run = min(quantum, cp->remaining);

        currentTime += run;
        cp->remaining -= run;

        int end = currentTime;

        gantt.emplace_back(cp->pid, start, end);

        while (idx < n && order[idx]->arrival <= currentTime) {
            ready.push(order[idx]);
            idx++;
        }

        if (cp->remaining == 0) {
            cp->completion = currentTime;
            cp->turnaround = cp->completion - cp->arrival;
            cp->waiting = cp->turnaround - cp->burst;
            finished++;
        }
        else {
            ready.push(cp);
        }
    }

    double totalTAT = 0.0, totalWT = 0.0;

    cout << "\nRound Robin Scheduling (Quantum=" << quantum << ")\n";
    cout << "Process\tArrival\tBurst\tCompletion\tTurnaround\tWaiting\n";

    for (auto &p : procs) {
        cout << "P" << p.pid << "\t"
             << p.arrival << "\t"
             << p.burst << "\t"
             << p.completion << "\t\t"
             << p.turnaround << "\t\t"
             << p.waiting << "\n";

        totalTAT += p.turnaround;
        totalWT += p.waiting;
    }

    cout << fixed << setprecision(2);

    cout << "\nAverage Turnaround Time = " << totalTAT / n << "\n";
    cout << "Average Waiting Time = " << totalWT / n << "\n";

    cout << "\nGantt Chart:\n";

    cout << " ";
    for (auto &seg : gantt) {
        int pid, s, e;
        tie(pid, s, e) = seg;
        int width = e - s;

        for (int i = 0; i < width; i++)
            cout << "--";

        cout << " ";
    }
    cout << endl;

    cout << "|";
    for (auto &seg : gantt) {
        int pid, s, e;
        tie(pid, s, e) = seg;

        int width = e - s;

        for (int i = 0; i < width; i++)
            cout << "  ";

        cout << "P" << pid << "|";
    }
    cout << endl;

    cout << " ";
    for (auto &seg : gantt) {
        int pid, s, e;
        tie(pid, s, e) = seg;

        int width = e - s;

        for (int i = 0; i < width; i++)
            cout << "--";

        cout << " ";
    }
    cout << endl;

    int last = 0;
    cout << last;

    for (auto &seg : gantt) {
        int pid, s, e;
        tie(pid, s, e) = seg;

        int width = e - s;

        for (int i = 0; i < width; i++)
            cout << "  ";

        cout << e;
    }

    cout << endl;

    return 0;
}