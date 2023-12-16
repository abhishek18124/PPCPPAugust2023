#include<iostream>

using namespace std;

class ListNode {

public :

	int val;
	ListNode* next;

	ListNode(int val) {
		this->val = val;
		this->next = NULL;
	}

};


void insertAtHead(ListNode*& head, int val) {

	ListNode* n = new ListNode(val);
	n->next = head;
	head = n;

}

void printLinkedList(ListNode* head) {

	while (head != NULL) {
		cout << head->val << " ";
		head = head->next;
	}

	cout << endl;
}

void deleteAtHead(ListNode*& head) {

	if (!head) { // head == NULL
		// linkedList is empty
		return;
	}

	ListNode* temp = head;
	head = head->next;
	delete temp;
}

ListNode* getListNode(int j, ListNode* temp) {

	int k = 0;
	while (temp != NULL && k < j) { // while(temp && k < j)
		temp = temp->next;
		k++;
	}

	return temp;

}

ListNode* getNode(ListNode* head, int j) {

	// returns the address of the node at the jth index

	int k = 1;

	while (head != NULL and k <= j) {

		head = head->next;
		k++;

	}

	return head;

}

// O(n)

void deleteAtIndex(ListNode*& head, int i) {

	if (i == 0) {

		// deletion at index 0 is equi to deletion at head

		deleteAtHead(head);
		return;

	}

	ListNode* curr = getNode(head, i);

	if (curr == NULL) {

		// i >= n i.e. curr does not exist

		return;

	}

	// i <= n-1

	ListNode* prev = getNode(head, i - 1);

	// this is not required, if you reach here, prev is not NULL;

	// if(prev == NULL) {
	// 	return;
	// }

	prev->next = curr->next;
	delete curr;

}

int main() {

	ListNode* head = NULL; // initially, linkedList is empty

	insertAtHead(head, 50);
	insertAtHead(head, 40);
	insertAtHead(head, 30);
	insertAtHead(head, 20);
	insertAtHead(head, 10);

	printLinkedList(head);

	deleteAtIndex(head, 2);

	printLinkedList(head);

	return 0;
}