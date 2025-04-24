#include <bits/stdc++.h>
using namespace std;

struct Process {
    int pid;     // Process ID
    int at;      // Arrival Time
    int bt;      // Burst Time
};

bool compareAT(Process a, Process b) {
    return a.at < b.at;
}

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    vector<Process> proc(n);
    for (int i = 0; i < n; i++) {
        cout << "Enter arrival and burst time for P" << i + 1 << ": ";
        cin >> proc[i].at >> proc[i].bt;
        proc[i].pid = i + 1;
    }

    sort(proc.begin(), proc.end(), compareAT);

    vector<bool> done(n, false);
    vector<int> wt(n, 0), tat(n, 0);
    int time = 0, completed = 0;

    while (completed < n) {
        int idx = -1, minBT = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (!done[i] && proc[i].at <= time && proc[i].bt < minBT) {
                minBT = proc[i].bt;
                idx = i;
            }
        }

        if (idx != -1) {
            // Execute process
            wt[idx] = time - proc[idx].at;
            time += proc[idx].bt;
            tat[idx] = wt[idx] + proc[idx].bt;
            done[idx] = true;
            completed++;
        } else {
            // If no process has arrived yet, move time forward
            time++;
        }
    }

    // Output
    double totalWT = 0, totalTAT = 0;
    cout << "\nPID\tAT\tBT\tWT\tTAT\n";
    for (int i = 0; i < n; i++) {
        cout << proc[i].pid << "\t" << proc[i].at << "\t" << proc[i].bt << "\t"
             << wt[i] << "\t" << tat[i] << "\n";
        totalWT += wt[i];
        totalTAT += tat[i];
    }

    cout << "\nAverage Waiting Time: " << totalWT / n;
    cout << "\nAverage Turnaround Time: " << totalTAT / n << endl;

    return 0;
}
