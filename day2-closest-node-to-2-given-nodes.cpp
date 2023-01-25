class Solution
{
public:
    void path(int node, vector<int> &hash, vector<int> &edges, vector<int> &checked, int dist)
    {
        if (node == -1 || checked[node] == 1)
        {
            return;
        }
        hash[node] = dist;
        dist++;
        checked[node] = 1;
        path(edges[node], hash, edges, checked, dist);
    }
    int closestMeetingNode(vector<int> &edges, int node1, int node2)
    {
        vector<int> hash1(edges.size(), -1), hash2(edges.size(), -1);
        vector<int> checked1(edges.size(), 0), checked2(edges.size(), 0);
        path(node1, hash1, edges, checked1, 0);
        path(node2, hash2, edges, checked2, 0);
        int ans = -1;
        int distance = INT_MAX;
        for (int i = 0; i < edges.size(); i++)
        {
            if (hash1[i] != -1 && hash2[i] != -1)
            {
                int d = max(hash1[i], hash2[i]);
                if (d < distance)
                {
                    distance = d;
                    ans = i;
                }
            }
        }
        return ans;
    }
};