#include<bits/stdc++.h>

using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->right, data);
                    root->right = cur;
               }

               return root;
           }
        }

/*
class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

*/

    void fillMap(Node* root, int d, int l,
                map<int, pair<int, int> >& m) {
        if (root == NULL)
            return;
    
        if (m.count(d) == 0) {
            m[d] = make_pair(root->data, l);
        }
        else if (m[d].second > l) {
            m[d] = make_pair(root->data, l);
        }
    
        fillMap(root->left, d - 1, l + 1, m);
        fillMap(root->right, d + 1, l + 1, m);
    }
 
// function should print the topView of
// the binary tree

    void topView(Node * root) {
        // map to store the pair of node value and its level
        // with respect to the vertical distance from root.
        map<int, pair<int, int> > m;
    
        // fillmap(root,vectical_distance_from_root,level_of_node,map)
        fillMap(root, 0, 0, m);
    
        for (auto it = m.begin(); it != m.end(); it++) {
            cout << it->second.first << " ";
        }
    }

}; //End of Solution

int main() {
  
    Solution myTree;
    Node* root = NULL;
    
    int t;
    int data;

    std::cin >> t;

    while(t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }
    
    myTree.topView(root);
    return 0;
}
