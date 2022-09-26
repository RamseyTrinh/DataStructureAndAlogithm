#include<iostream>
using namespace std;

class Head;
class Node;

class Node {
public:
    double val;
    Node *next;
    Node() {
        val = 0;
        next = NULL;
    }
    Node(double x) {
        val = x;
        next = NULL;
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
    }
    void pop_front() {
        Node *temp = head->next;
        head->next = NULL;
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
        delete head;
        head = temp;
    }
    void remove(double x) {
        Node *ptemp = head;
        if(head->val == x) {
            pop_front();
        }
        Node *pPre = NULL;
        Node *pDel = head;
        while(pDel != NULL) {
            if(pDel->val == x) {
                pPre->next = pDel->next;
                pDel->next = NULL;
                delete pDel;
                pDel = pPre;
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
            p->next = temp->next;
            temp->next = p;
        }
    }
    void reverse() {
        if(head == NULL || head->next == NULL) {
            return;
        } else if(head->next->next == NULL) {
            Node *pPar = head->next;
            pPar->next = head;
            head->next = NULL;
            head = pPar;
        } else {
            Node *pPar = head->next;
            Node *pChild = pPar->next;
            head->next = NULL;
            pPar->next = head;
            while(pChild->next != NULL) {
                Node *temp = pChild->next;
                pChild->next = pPar;
                pPar = pChild;
                pChild = temp;
            }
            pChild->next = pPar;
            head = pChild;
        }
    }
    void erase(int pos) {
        if(pos <= 0 || pos > size()) {
            return;
        } else if(pos == 1) {
            Node *x = head;
            head = head->next;
            x->next = NULL;
            delete x;
            x = NULL;
        } else if(pos == size()) {
            Node *temp = head;
            Node *pre = head;
            while(temp->next != NULL) {
                pre = temp;
                temp = temp->next;
            }   
            pre->next = NULL;
            delete temp;
            temp = NULL;
        } else {
            int c = 1;
            Node *pre = head;
            Node *del = head;
            while(c < pos) {
                c++;
                pre = del;
                del = del->next;
            }
            pre->next = del->next;
            del->next = NULL;
            delete del;
            del = NULL;
        }
    }
};

int main() {
    int n;
    cin >> n;
    Head *x = new Head();
    for(int i = 0; i < n; i++) {
        int t;
        cin >> t;
        x->push_back(t);
    }
    int pos;
    cin >> pos;
    x->erase(pos);
    Node *r = x->head;
    while(r != NULL) {
        cout << r->val << " ";
        r = r->next;
    }
    return 0;
}