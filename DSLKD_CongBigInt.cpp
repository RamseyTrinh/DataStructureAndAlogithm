#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<math.h>
using namespace std;

struct Node {
	int data;
	Node *pNext;
	Node *pPrevious;
};

struct Dlist {
	Node *pHead;
	Node *pTail;
};

void Initialize(Dlist &list) {
	list.pHead = list.pTail = NULL;
}

void Printlist (Dlist list) {
	Node *ptemp = list.pHead;
	if(list.pHead == NULL) {
		cout << "Rong\n";
	} else {
		while(ptemp != NULL) {
			cout << ptemp->data;
			ptemp = ptemp->pNext;
		}
	}
}

int Sizeoflist(Dlist list) {
	Node *ptemp = list.pHead;
	int size = 0;
	while(ptemp != NULL) {
		size++;
		ptemp = ptemp->pNext;
	}
	return size;
}

Node *CreateNode(int x) {
	Node *pNode = new Node;
	pNode->data = x;
	pNode->pNext = NULL;
	pNode->pPrevious = NULL;
	return pNode;
}

void InsertFirst(Dlist &list, int x) {
	Node *pNode = CreateNode(x);
	if(list.pHead == NULL) {
		list.pHead = list.pTail =pNode;
	} else {
		pNode->pNext = list.pHead;
		list.pHead->pPrevious = pNode;
		list.pHead = pNode;
	}
}

void InsertLast(Dlist &list, int x) {
	Node *pNode = CreateNode(x);
	if(list.pHead == NULL) {
		list.pHead = list.pTail = pNode;
	} else {
		list.pTail->pNext = pNode;
		pNode->pPrevious = list.pTail;
		list.pTail = pNode;
	}
}

Dlist taolist(string str) {
	Dlist list;
	Initialize(list);
	for(int i = 0; i < str.size(); i++) {
		char strtemp[2];
		strtemp[0] = str[i];
		int x = atoi(strtemp);
		InsertLast(list,x);
	}
	return list;
}

Dlist cong(Dlist list1, Dlist list2) {
	Dlist list3;
	Initialize(list3);
	Node *Tail1 = list1.pTail;
	Node *Tail2 = list2.pTail;
	int count = 0;
	while(Tail1 != NULL || Tail2 != NULL) {
		int x = Tail1->data + Tail2->data + count;
		if(Tail1->pPrevious == NULL && Tail2->pPrevious == NULL) {
			InsertFirst(list3,x);
			break;
		}
		if(Tail1 != NULL && Tail2 != NULL) {
			if(x >= 10) {
				InsertFirst(list3,x-10);
				count = 1;
			} else {
				InsertFirst(list3,x);
				count = 0;
			}
			Tail1 = Tail1->pPrevious;
			Tail2 = Tail2->pPrevious;
		}
		if(Tail1 == NULL) {
			InsertFirst(list3,Tail2->data+count);
			Tail2 = Tail2->pPrevious;
			while(Tail2 != NULL) {
				InsertFirst(list3,Tail2->data);
				Tail2 = Tail2->pPrevious;
			}
			break;
		} else if(Tail2 == NULL) {
			InsertFirst(list3,Tail1->data+count);
			Tail1 = Tail1->pPrevious;
			while(Tail1 != NULL) {
				InsertFirst(list3,Tail1->data);
				Tail1 = Tail1->pPrevious;
			}
			break;
		}
	}
	return list3;
}

int main() {
	string str;
	cout << "Nhap so: ";
	cin >> str;
	Dlist list1 = taolist(str);
	cout << "Ta co so: ";
	Printlist(list1);
	cout << endl;
	cout << "Nhap so: ";
	cin >> str;
	Dlist list2 = taolist(str);
	cout << "Ta co so: ";
	Printlist(list2);
	Dlist list3 = cong(list1,list2);
	cout << endl;
	cout << "Tong: ";
	Printlist(list3);
	return 0;     
}
