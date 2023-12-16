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

ListNode* getTail(ListNode* temp) {

	while (temp->next != NULL) { // till you've not reached the tail node of the LinkedList
		temp = temp->next;
	}

	// temp pointer is pointing to the tail node

	return temp;

}

// time : O(n)

void insertAtTail(ListNode*& head, int val) {

	if (head == NULL) {

		// if the LinkedList is empty then insertion at tail is equivalent to insertion at head

		insertAtHead(head, val);
		return;

	}

	ListNode* n = new ListNode(val);

	ListNode* tail = getTail(head);

	tail->next = n;

}

int main() {

	ListNode* head = NULL; // initially, linkedList is empty

	// insertAtHead(head, 50);
	// insertAtHead(head, 40);
	// insertAtHead(head, 30);
	// insertAtHead(head, 20);
	// insertAtHead(head, 10);

	// printLinkedList(head);

	insertAtTail(head, 60);

	printLinkedList(head);

	return 0;
}
