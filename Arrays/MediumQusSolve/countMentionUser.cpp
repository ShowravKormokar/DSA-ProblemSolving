// Leetcode problem 3433 -> Count Mentions Per User
#include <bits/stdc++.h>
using namespace std;

// ------------------ Hard to understand, submit solved code help of internet, need more practice and study 🚨☠️

struct OfflineUser
{
    int returnTimestamp;
    int userId;

    // min-heap comparator
    bool operator>(const OfflineUser &other) const
    {
        return returnTimestamp > other.returnTimestamp;
    }
};

class Solution
{
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>> &events)
    {
        vector<int> ans(numberOfUsers);
        vector<int> online(numberOfUsers, true);

        priority_queue<OfflineUser, vector<OfflineUser>, greater<>> offlineQueue;

        int allMentionsCount = 0;

        // Sort by (timestamp, eventType priority)
        sort(events.begin(), events.end(),
             [](const vector<string> &a, const vector<string> &b)
             {
                 int tA = stoi(a[1]);
                 int tB = stoi(b[1]);
                 char eA = a[0][0];
                 char eB = b[0][0];
                 return pair<int, char>{tA, -eA} < pair<int, char>{tB, -eB};
             });

        for (const auto &event : events)
        {
            string eventType = event[0];
            int timestamp = stoi(event[1]);

            // Bring users online if their offline period is over
            while (!offlineQueue.empty() &&
                   offlineQueue.top().returnTimestamp <= timestamp)
            {
                online[offlineQueue.top().userId] = true;
                offlineQueue.pop();
            }

            if (eventType == "MESSAGE")
            {
                const string mentions = event[2];
                if (mentions == "ALL")
                {
                    allMentionsCount++;
                }
                else if (mentions == "HERE")
                {
                    for (int u = 0; u < numberOfUsers; u++)
                        if (online[u])
                            ans[u]++;
                }
                else
                {
                    for (int u : getUserIds(mentions))
                        ans[u]++;
                }
            }
            else if (eventType == "OFFLINE")
            {
                int userId = stoi(event[2]);
                online[userId] = false;
                offlineQueue.push({timestamp + 60, userId});
            }
        }

        // Add ALL mentions to all users
        for (int u = 0; u < numberOfUsers; u++)
            ans[u] += allMentionsCount;

        return ans;
    }

private:
    vector<int> getUserIds(const string &s)
    {
        vector<int> ids;
        istringstream iss(s);
        for (string id; iss >> id;)
            ids.push_back(stoi(id.substr(2)));
        return ids;
    }
};

int main()
{
    Solution sol;
    int numberOfUsers = 3;
    vector<vector<string>> events = {
        {"MESSAGE", "1", "USER_0 USER_1"},
        {"OFFLINE", "2", "0"},
        {"MESSAGE", "3", "HERE"},
        {"MESSAGE", "61", "ALL"},
        {"MESSAGE", "62", "USER_0"}};

    vector<int> result = sol.countMentions(numberOfUsers, events);
    for (int count : result)
    {
        cout << count << " "; // Output the mention counts for each user
    }
    return 0;
}

/*
TC: O(E log E + E + U) where E is the number of events and U is the number of users.
SC: O(U + E) for the answer array, online status array, and the offline
*/