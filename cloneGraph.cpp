/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
public:
    map<Node*,Node*> dic;
    Node* cloneGraph(Node* node) {
        if(!node) return nullptr;
        if(dic.count(node)) return dic[node];
        Node* cur = new Node(node->val);
        dic[node] = cur;
        for(int i = 0;i<node->neighbors.size();i++){
            cur->neighbors.push_back(cloneGraph(node->neighbors[i]));
        }
        return cur;
    }
};
