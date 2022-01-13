// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int maxDepth(Node* n)
    // finding the most distant leaf node from given node
    {
        if (!n) return 0;
        return 1 + max( maxDepth(n->left) , maxDepth(n->right) );
    }

    int traverse(Node* n, int target, int &ret)
    {
        if (!n) return 0;
        // base case

        if (n->data == target) {
            ret = max( ret, maxDepth(n->right) );
            ret = max( ret, maxDepth(n->left) );
            return 1;
        }
        // target found, hence returning distance from it

        int val = traverse(n->left, target, ret);
        if (val)
            // (val != 0) means target was found at distance = val
        {
            ret = max( ret, val + maxDepth(n->right) );
            // finding max Depth on right as target was on left
            return val + 1;
        }

        val = traverse(n->right, target, ret);
        if (val)
            // (val != 0) means target was found at distance = val
        {
            ret = max( ret, val + maxDepth(n->left) );
            // finding max Depth on left as target was on right
            return val + 1;
        }

        return 0;
    }

    int minTime(Node* root, int target)
    {
        int ret = 0;
        traverse(root, target, ret);
        return ret;
    }
};


// { Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}
  // } Driver Code Ends
