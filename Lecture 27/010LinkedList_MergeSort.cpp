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

ListNode* computeMidPoint(ListNode* head) {

	if (head == NULL) {
		// LinkedList is empty
		return NULL;
	}

	ListNode* slow = head;
	ListNode* fast = head->next;

	while (fast != NULL and fast->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;
	}

	return slow;

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


ListNode* mergeSort(ListNode* head) {

	// base case

	if (head == NULL || head->next == NULL) {

		// LinkedList is empty or it has one node

		return head;

	}

	// recursive case

	ListNode* midPoint = computeMidPoint(head);
	ListNode* head2 = midPoint->next;
	midPoint->next = NULL;

	head = mergeSort(head);
	head2 = mergeSort(head2);

	return mergeSortedLinkedListRecursive(head, head2);


}


int main() {

	ListNode* head = NULL;

	insertAtHead(head, 10);
	insertAtHead(head, 20);
	insertAtHead(head, 30);
	insertAtHead(head, 40);
	insertAtHead(head, 50);

	printLinkedList(head);

	head = mergeSort(head);

	printLinkedList(head);

	return 0;
}