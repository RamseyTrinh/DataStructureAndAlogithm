#include<bits/stdc++.h>
using namespace std;

class Node;

class Node {
public:
    double val;
    Node *left;
    Node *right;
    Node() {}
    Node(double x) {
        val = x;
        left = NULL;
        right = NULL;
    }
    void insert(Node *&root, double x) {
        if(root == NULL) {
            Node *p = new Node(x);
            root = p;
        } else if(root->val == x) {
            return;
        } else if(root->val > x) {
            insert(root->left,x);
        } else {
            insert(root->right,x);
        }
    }
    void PrintNLR(Node* root) {
        if(root != NULL) {
            cout << root->val << " ";
            PrintNLR(root->left);
            PrintNLR(root->right);
        }
    }
    void PrintNRL(Node* root) {
        if(root != NULL) {
            cout << root->val << " ";
            PrintNRL(root->right);
            PrintNRL(root->left);
        }
    }

    void PrintLNR(Node* root) {
        if(root != NULL) {
            PrintLNR(root->left);
            cout << root->val << " ";
            PrintLNR(root->right);
        }
    }

    void PrintRNL(Node* root) {
        if(root != NULL) {
            PrintRNL(root->right);
            cout << root->val << " ";
            PrintRNL(root->left);
        }
    }

    void PrintLRN(Node* root) {
        if(root != NULL) {
            PrintLRN(root->left);
            PrintLRN(root->right);
            cout << root->val << " ";
        }
    }

    void PrintRLN(Node* root) {
        if(root != NULL) {
            PrintRLN(root->right);
            PrintRLN(root->left);
            cout << root->val << " ";
        }
    }
    int countleaves(Node* root) {
        if(root == NULL) {
            return 0;
        } else if(root->left == NULL && root->right == NULL) {
            return 1;
        }
        return countleaves(root->left) + countleaves(root->right);
    }
    int countNode(Node* root) {
        if(root == NULL) {
            return 0;
        }
        return 1 + countNode(root->left) + countNode(root->right);
    }
    int height(Node* root) {
        if(root == NULL) {
            return 0;
        }
        return 1 + max(height(root->left),height(root->right));
    }
    void deleteNode(Node *&root, int x) {
        if(root == NULL) {
            return;
        }
        if(root->val < x) {
            deleteNode(root->right,x);
        } else if(root->val > x) {
            deleteNode(root->left,x);
        } else {
            Node *tmp = root;
            if(root->left == NULL) {
                root = root->right;
                delete tmp;
                tmp = NULL;
            } else if(root->right == NULL) {
                root = root->left;
                delete tmp;
                tmp = NULL;
            } else {
                Node* temp = root->right;
                while(temp->left != NULL) {
                    temp = temp->left;
                }
                root->val = temp->val;
                deleteNode(root->right,temp->val);
            }
        }
    }
};


int main() {
    
    return 0;
}