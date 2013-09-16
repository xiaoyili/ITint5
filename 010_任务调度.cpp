/*
 作者: Annie Kim, anniekim.pku[at]gmail.com
 时间: Sep 16, 2013
 题目: 任务调度
 难度: Easy
 链接: http://www.itint5.com/oj/#10
 问题: 
 有n个任务需要完成（编号1到n），任务之间有一些依赖关系，如果任务a依赖于任务b和c，
 那么只有当任务b和任务c完成之后才能完成任务a。给定所有的依赖关系，判断这些任务是否能够完成。
 如果能够完成，请给出一个合法的任务完成序列。
 样例：
 n=5
 1->2,3
 3->4
 上述样例中任务1依赖于任务2和任务3，任务3依赖于任务4，那么存在合法的任务完成序列4,3,2,1,5

 Solution: 拓扑排序。
*/

typedef int JobID;
typedef map<JobID, vector<JobID> > MAP;
typedef MAP::const_iterator Iterator;

/*
 * deps[id]表示任务id所依赖的任务
 * 如果存在合法的任务完成序列，返回true，否则返回false
 * 合法的任务序列请存放在参数result中（已经分配空间，不需要push_back）
 */
bool jobSchedule(const map<JobID, vector<JobID> > &deps, int n, vector<JobID> &result) 
{
    MAP notify;
    queue<JobID> q;
    int deps_count[n+1];
    for (int i = 1; i <= n; ++i) 
        deps_count[i] = 0;
    for (Iterator it = deps.begin(); it != deps.end(); ++it)
    {
        JobID id = it->first;
        const vector<JobID> &jobs = it->second;
        int N = jobs.size();
        deps_count[id] = N;
        for (int i = 0; i < N; ++i)
            notify[jobs[i]].push_back(id);
    }
    for (int i = 1; i <= n; ++i) 
        if (deps_count[i] == 0) 
            q.push(i);

    int index = 0;
    while (!q.empty())
    {
        JobID id = q.front(); q.pop();
        result[index++] = id;
        if (notify.find(id) == notify.end())
            continue;
        vector<JobID> &jobs = notify[id];
        for (int i = 0; i < jobs.size(); ++i)
        {
            deps_count[jobs[i]]--;
            if (deps_count[jobs[i]] == 0)
                q.push(jobs[i]);
        }
    }

    return index == n;
}