#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

node *buildTree()
{
    int d;
    cin >> d;
    if (d == -1)
    {
        return NULL;
    }
    node *root = new node(d);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}

void BFS(node *root)
{
    queue<node *> Q;
    Q.push(root);
    Q.push(NULL);
    while (!Q.empty())
    {
        node *curr = Q.front();
        if (curr == NULL)
        {
            cout << endl;
            Q.pop();
            if (!Q.empty())
            {
                Q.push(NULL);
            }
        }
        else
        {
            cout << curr->data << " ";
            if (curr->left)
            {
                Q.push(curr->left);
            }
            if (curr->right)
            {
                Q.push(curr->right);
            }
            Q.pop();
        }
    }
}

vector<int> rightView(node *root)
{
    vector<int> ans;
    if (!root)
        return ans;
    int level=0;
    queue<node *> q;
    q.push(root);

    map<int, int> m;

    while (!q.empty())
    {
        
        int size = q.size();
        while (size--)
        {
            node* x = q.front();
            q.pop();
            m[level] = x->data;

            if(x->left) q.push(x->left);
            if(x->right) q.push(x->right);
        }
        level++;
    }
    for(auto x:m) ans.push_back(x.second);
}

vector <int> leftView(node* root){
    vector<int> ans;
    if (!root)
        return ans;
    int level=0;
    queue<node *> q;
    q.push(root);

    map<int, int> m;

    while (!q.empty())
    {
        
        int size = q.size();
        while (size--)
        {
            node* x = q.front();
            q.pop();
            if(m.find(level)== m.end()) m[level] = x->data;
            

            if(x->left) q.push(x->left);
            if(x->right) q.push(x->right);
        }
        level++;
    }
    for(auto x:m) ans.push_back(x.second);
}

int main()
{
    node *root = buildTree();
    BFS(root);
    cout<<endl;
    vector<int> rView = rightView(root);
    for(auto x: rView) cout<<x<<endl;
    cout<<endl;
    vector<int> lView = leftView(root);
    for(auto x: lView) cout<<x<<endl;
}