struct GraphNode {
    int lable;
    vector<GraphNode *> neighbors;
    GraphNode(int x) : lable(x) {};
};
//DFS
// class Solution {
// public:
//     bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
//         vector<GraphNode *> graph;
//         vector<int> visit;
        
//         for (int i = 0; i < numCourses; i++) {
//             graph.push_back(new GraphNode(i));
//             visit.push_back(-1);
//         }
        
//         for (int i = 0; i < prerequisites.size(); i++) {
//             GraphNode *begin = graph[prerequisites[i].second];
//             GraphNode *end = graph[prerequisites[i].first];
//             begin->neighbors.push_back(end);
//         }
        
    //     for (int i = 0; i < graph.size(); i++) {
    //         if (visit[i] == -1 && !DFS_graph(graph[i], visit)) {
    //             return false;
    //         }
    //     }
        
    //     for (int i = 0; i < numCourses; i++) {
    //         delete graph[i];
    //     }
        
    //     return true;
    // }
    
    // bool DFS_graph(GraphNode *node, vector<int> &visit) {
    //     visit[node->lable] = 0;
    //     for (int i = 0; i < node->neighbors.size(); i++) {
    //         if (visit[node->neighbors[i]->lable] == -1) {
    //             if (DFS_graph(node->neighbors[i], visit) == 0) {
    //                 return false;
    //             }
    //         }
    //         else if (visit[node->neighbors[i]->lable] == 0) {
    //             return false;
//             }
//         }
//         visit[node->lable] = 1;
//         return true;
//     }
// };

//BFS

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<GraphNode *> graph;
        vector<int> degree;
        queue<GraphNode *> Q;
        
        for (int i = 0; i < numCourses; i++) {
            graph.push_back(new GraphNode(i));
            degree.push_back(0);
        }
        
        for (int i = 0; i < prerequisites.size(); i++) {
            GraphNode *begin = graph[prerequisites[i].second];
            GraphNode *end = graph[prerequisites[i].first];
            begin->neighbors.push_back(end);
            degree[prerequisites[i].first]++;
        }
        
        for (int i = 0; i < graph.size(); i++) {
            if (degree[i] == 0) {
                Q.push(graph[i]);
            }
        }
        
        while (!Q.empty()) {
            GraphNode *node = Q.front();
            Q.pop();
            
            for (int i = 0; i < node->neighbors.size(); i++) {
                degree[node->neighbors[i]->lable]--;
                if (degree[node->neighbor[i]->lable] == 0) {
                    Q.push(node->neighbors[i]);
                }
            }
            
        }
        
        for (int i = 0; i < degree.size(); i++) {
            if (degree[i]) {
                return false;
            }
        }
        
        return true;
    }
    
};

