#include<iostream>

using namespace std;

class ListNode {
public:

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

	while (head) { // head != NULL
		cout << head->val << " ";
		head = head->next;
	}

	cout << endl;
}

ListNode* mergeSortedLinkedList(ListNode* head1, ListNode* head2) {

	ListNode* dummy = new ListNode(0);
	ListNode* temp = dummy;

	while (head1 != NULL and head2 != NULL) {

		if (head1->val < head2->val) {

			temp->next = head1;
			temp = temp->next;
			head1 = head1->next;

		} else {

			temp->next = head2;
			temp = temp->next;
			head2 = head2->next;

		}

	}

	if (head1 != NULL) { // head2 was exhausted
		temp->next = head1;
	}

	if (head2 != NULL) { // head1 was exhausted
		temp->next = head2;
	}

	return dummy->next;

}

ListNode* mergeSortedLinkedListRecursive(ListNode* head1, ListNode* head2) {

	// base case

	if (head1 == NULL) {

		// first LinkedList is empty

		return head2;

	}

	if (head2 == NULL) {

		// second LinkedList is empty

		return head1;

	}

	// recursive case

	ListNode* head = NULL;

	if (head1->val < head2->val) {

		head = head1;
		ListNode* headFromMyFriend = mergeSortedLinkedListRecursive(head1->next, head2);
		head->next = headFromMyFriend;

	} else {

		head = head2;
		ListNode* headFromMyFriend = mergeSortedLinkedListRecursive(head1, head2->next);
		head->next = headFromMyFriend;

	}


	return head;

}

int main() {

	ListNode* head1 = NULL;

	insertAtHead(head1, 50);
	insertAtHead(head1, 30);
	insertAtHead(head1, 10);

	printLinkedList(head1);

	ListNode* head2 = NULL;

	insertAtHead(head2, 80);
	insertAtHead(head2, 70);
	insertAtHead(head2, 60);
	insertAtHead(head2, 40);
	insertAtHead(head2, 20);

	printLinkedList(head2);

	// ListNode* head = mergeSortedLinkedList(head1, head2);

	ListNode* head = mergeSortedLinkedListRecursive(head1, head2);

	printLinkedList(head);

	return 0;
}