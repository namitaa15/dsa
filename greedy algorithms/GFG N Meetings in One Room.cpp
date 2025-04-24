struct Meeting {
    int start, end, pos;
};

bool static compare(Meeting m1, Meeting m2) {
    if (m1.end == m2.end)
        return m1.pos < m2.pos;
    return m1.end < m2.end;
}

int maxMeetings(int start[], int end[], int n) {
    vector<Meeting> meetings;

    for (int i = 0; i < n; i++) {
        meetings.push_back({start[i], end[i], i + 1});
    }

    sort(meetings.begin(), meetings.end(), compare);

    int count = 1;
    int endLimit = meetings[0].end;

    for (int i = 1; i < n; i++) {
        if (meetings[i].start > endLimit) {
            count++;
            endLimit = meetings[i].end;
        }
    }

    return count;
}
