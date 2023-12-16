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

// time : O(n)

void deleteAtTail(ListNode*& head) {

	if (head == NULL) {
		// LinkedList is empty
		return;
	}

	if (head->next == NULL) {
		// LinkedList has one node therefore deletion at tail is equi to deletion at head
		deleteAtHead(head);
		return;
	}

	// LinkedList has >= 2 nodes

	ListNode* prev = NULL;
	ListNode* curr = head;

	while (curr->next != NULL) { // till curr has not reached the tail node
		prev = curr;
		curr = curr->next;
	}

	// curr has reached the tail node and prev is one-step behind

	prev->next = NULL;
	delete curr;

}

int main() {

	ListNode* head = NULL; // linked list is initially empty

	insertAtHead(head, 50);
	// insertAtHead(head, 40);
	// insertAtHead(head, 30);
	// insertAtHead(head, 20);
	// insertAtHead(head, 10);

	printLinkedList(head);

	deleteAtTail(head);

	// printLinkedList(head);

	return 0;
}