// Sep. 17th, 2025

using tiii = tuple<int,int,int>; // (priority, taskId, userId)

class TaskManager {
public:
    // per-user heaps (priority_queue defaults to max-heap on pair<int,int>)
    unordered_map<int, priority_queue<pair<int,int>>> userTasks;

    // global heap: default max-heap by (priority, taskId, userId)
    priority_queue<tiii> globalPQ;

    // taskId -> (userId, priority)
    unordered_map<int, pair<int,int>> taskInfo;

    TaskManager(vector<vector<int>>& tasks) {
        for (auto &t : tasks) {
            add(t[0], t[1], t[2]);
        }
    }

    void add(int userId, int taskId, int priority) {
        userTasks[userId].push({priority, taskId});
        globalPQ.push({priority, taskId, userId});
        taskInfo[taskId] = {userId, priority};
    }
    
    void edit(int taskId, int newPriority) {
        auto [u, _] = taskInfo[taskId];
        taskInfo[taskId] = {u, newPriority};
        userTasks[u].push({newPriority, taskId});
        globalPQ.push({newPriority, taskId, u}); // push updated copy
    }
    
    void rmv(int taskId) {
        taskInfo.erase(taskId); // lazy delete
    }
    
    int execTop() {
        while (!globalPQ.empty()) {
            auto [p, id, u] = globalPQ.top();
            if (!taskInfo.count(id) || taskInfo[id].second != p) {
                globalPQ.pop(); // stale
                continue;
            }
            globalPQ.pop();
            taskInfo.erase(id);
            return u;
        }
        return -1;
    }
};
