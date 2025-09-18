// Leetcode problem 3408 -> Design Task Manager
#include <bits/stdc++.h>
using namespace std;

struct Task
{
    int userId;
    int taskId;
    int priority;
    Task(int u, int t, int p) : userId(u), taskId(t), priority(p) {}
};

// Comparison for sorted ordering
struct Cmp
{
    bool operator()(const Task &a, const Task &b) const
    {
        if (a.priority != b.priority)
            return a.priority > b.priority;
        return a.taskId > b.taskId;
    }
};

class TaskManager
{
private:
    // Map from taskId -> (userId, priority)
    unordered_map<int, pair<int, int>> taskMap;
    // Set of tasks sorted by priority desc, then taskId desc
    set<Task, Cmp> taskSet;

public:
    TaskManager(vector<vector<int>> &tasks)
    {
        for (auto &t : tasks)
        {
            int u = t[0], id = t[1], p = t[2];
            taskMap[id] = {u, p};
            taskSet.insert(Task(u, id, p));
        }
    }

    void add(int userId, int taskId, int priority)
    {
        taskMap[taskId] = {userId, priority};
        taskSet.insert(Task(userId, taskId, priority));
    }

    void edit(int taskId, int newPriority)
    {
        auto it = taskMap.find(taskId);
        if (it == taskMap.end())
            return;
        auto [u, oldP] = it->second;
        Task oldTask(u, taskId, oldP);
        taskSet.erase(oldTask);
        Task newTask(u, taskId, newPriority);
        taskSet.insert(newTask);
        taskMap[taskId] = {u, newPriority};
    }

    void rmv(int taskId)
    {
        auto it = taskMap.find(taskId);
        if (it == taskMap.end())
            return;
        auto [u, p] = it->second;
        Task t(u, taskId, p);
        taskSet.erase(t);
        taskMap.erase(it);
    }

    int execTop()
    {
        if (taskSet.empty())
            return -1;
        auto it = taskSet.begin();
        Task t = *it;
        taskSet.erase(it);
        taskMap.erase(t.taskId);
        return t.userId;
    }
};

int main()
{
    // Initial tasks: [userId, taskId, priority]
    vector<vector<int>> tasks = {
        {1, 101, 5}, // User 1, Task 101, Priority 5
        {2, 102, 8}, // User 2, Task 102, Priority 8
        {1, 103, 3}  // User 1, Task 103, Priority 3
    };

    TaskManager tm(tasks);

    cout << "ExecTop -> User " << tm.execTop() << endl; // Task 102 (highest priority 8)

    tm.add(3, 104, 10);                                 // Add new task for User 3, Priority 10
    cout << "ExecTop -> User " << tm.execTop() << endl; // Task 104 (priority 10)

    tm.edit(101, 12);                                   // Update Task 101 (priority 5 -> 12)
    cout << "ExecTop -> User " << tm.execTop() << endl; // Task 101 (priority 12)

    tm.rmv(103);                                        // Remove Task 103 (priority 3)
    cout << "ExecTop -> User " << tm.execTop() << endl; // No tasks left? -1

    return 0;
}