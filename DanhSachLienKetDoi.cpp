#include<bits/stdc++.h>
using namespace std;

class Head;
class Node;

class Node {
public:
    double val;
    Node *next;
    Node *pre;
    Node() {
        val = 0;
        next = NULL;
        pre = NULL;
    }
    Node(double x) {
        val = x;
        next = NULL;
        pre = NULL;
    }
};

class Head {
public:
    Node *head;
    Head() {
        head = NULL;
    }
    Head(Node *x) {
        head = x;
    }
    void push_front(double x) {
        Node *a = new Node(x);
        if(head == NULL) {
            head = a;
            return;
        }
        a->next = head;
        head->pre = a;
        head = a;
    }
    void push_back(double x) {
        Node *a = new Node(x);
        if(head == NULL) {
            head = a;
            return;
        }
        Node *temp = head;
        while(temp->next != NULL) {
            temp = temp->next;
        }   
        temp->next = a;
        a->pre = temp;
    }
    void pop_front() {
        Node *temp = head->next;
        head->next = NULL;
        temp->pre = NULL;
        delete head;
        head = temp;
    }
    void pop_back() {
        if(head != NULL && head->next == NULL) {
            delete head;
            head = NULL;
            return;
        } 
        Node *temp = head;
        Node *pPre = head;
        while(head->next != NULL) {
            pPre = head;
            head = head->next;
        }   
        pPre->next = NULL;
        head->pre = NULL;
        delete head;
        head = temp;
    }
    void remove(double x) {
        Node *ptemp = head;
        while (head->val == x) {
            pop_front();
        }
        Node *pPre = NULL;
        Node *pDel = head;
        while(pDel != NULL) {
            if(pDel->val == x) {
                pPre->next = pDel->next;
                pDel->pre = NULL;
                pDel->next = NULL;
                delete pDel;
                pDel = pPre->next;
                pDel->pre = pPre;
            }
            pPre = pDel;
            pDel = pDel->next;
        }
    }
    int size() {
        int c = 0;
        Node* temp = head;
        while(temp != NULL) {   
            temp = temp->next;
            c++;
        }
        return c;
    }
    void insert(int pos, double x) {
        if(size() + 1 < pos || pos <= 0) {
            cout << "Insert Invalid\n";
        } else if(size() + 1 == pos) {
            push_back(x);
        } else if(pos == 1) {
            push_front(x);
        } else {
            int c = 2;
            Node *p = new Node(x);
            Node *temp = head;
            while(c < pos) {
                c++;
                temp = temp->next;
            }
            temp->next->pre = p;
            p->next = temp->next;
            p->pre = temp;
            temp->next = p;
        }
    }
    void reverse() {
        if(head == NULL || head->next == NULL) {
            return;
        } else if(head->next->next == NULL) {
            Node *pPar = head->next;
            pPar->next = head;
            pPar->pre = NULL;
            head->pre = pPar;
            head->next = NULL;
            head = pPar;
        } else {
            Node *pPar = head->next;
            Node *pChild = pPar->next;
            head->next = NULL;
            head->pre = pPar;
            pPar->next = head;
            while(pChild->next != NULL) {
                Node *temp = pChild->next;
                pChild->next = pPar;
                pPar->pre = pChild;
                pPar = pChild;
                pChild = temp;
            }
            pChild->next = pPar;
            pPar->pre = pChild;
            head = pChild;
        }
    }
};

int main() {
    Node *x = new Node(4);
    Head *a = new Head(x);
    Node *t = a->head;
    return 0;
}