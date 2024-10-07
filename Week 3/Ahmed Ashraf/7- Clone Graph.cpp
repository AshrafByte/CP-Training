/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution
{
public:
    Node *cloneGraph(Node *node)
    {
        if (!node)
            return nullptr;

        unordered_map<Node *, Node *> clones;
        queue<Node *> q;
        q.push(node);
        clones[node] = new Node(node->val);

        while (!q.empty())
        {
            Node *curr = q.front();
            q.pop();

            for (Node *neighbor : curr->neighbors)
            {
                if (!clones.count(neighbor))
                {
                    clones[neighbor] = new Node(neighbor->val);
                    q.push(neighbor);
                }
                clones[curr]->neighbors.push_back(clones[neighbor]);
            }
        }
        return clones[node];
    }
};

class Solution
{
public:
    unordered_map<Node *, Node *> clones;

    Node *cloneGraph(Node *node)
    {
        if (!node)
            return nullptr;

        if (clones.count(node))
            return clones[node];

        Node *cloneNode = new Node(node->val);
        clones[node] = cloneNode;

        for (Node *neighbor : node->neighbors)
            cloneNode->neighbors.push_back(cloneGraph(neighbor));

        return cloneNode;
    }
};
