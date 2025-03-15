#include <iostream>
using namespace std;

typedef struct Node {
	string songName;
	Node *link;
} Node;

Node* createNode(string data) {
	Node* newNode = new Node;
	newNode->songName = data;
	newNode->link = NULL;
	return newNode;
}

void traverse (Node *head) {
	Node *temp = new Node;
	temp = head;

	cout << "My Playlist" <<endl;
	while(temp !=NULL) {
		cout << temp->songName<< "->" <<endl;
		if(temp->link == NULL) {
			cout << "NULL" << endl;
		}
		temp = temp->link;
	}
}

Node *insertAtEnd(string data, Node *head) {
	if(head == NULL) {
		Node *newNode = createNode(data);
		head = newNode;
		cout << "A new node has been insterted at the end \n" << endl;
		return head;
	}
	Node *temp = new Node;
	temp = head;

	while (temp->link != NULL) {
		temp = temp->link;
	}
	Node *newNode = createNode(data);
	temp->link = newNode;

	cout << "A new node has been insterted at the end \n" << endl;
	return head;
}

Node *instertAtBeginning(string data, Node *head) {
	Node *newNode = createNode(data);
	newNode->link = head;

	head = newNode;

	cout << "A new node has been inserted at the beginning \n" <<endl;
	return head;
}
string insertAfter(string after, string data, Node *head) {
	Node *temp = new Node;
	temp = head;

	while(temp->songName.compare(after) !=0) {
		if(temp == NULL) {
			return "No such song exist, please try again.";
		}

		temp = temp->link;
	}
	Node *newNode = createNode(data);
	newNode->link = temp->link;
	temp->link = newNode;

	return "An new node has been added after" + after + "\n";
}

string deleteAtEnd(Node *head) {
	if(head == NULL) {
		return "The linked list is empty \n";
	}

	if(head->link == NULL) {
		delete head;
		return "The head has been deleted \n";
	}

	Node *temp = new Node;
	temp = head;

	while(temp->link->link != NULL) {
		temp = temp->link;
	}

	temp->link = NULL;

	return "A node has been deleted at the end \n";
}

Node *deleteFromBeginning(Node *head) {
	if(head == NULL) {
		cout << "The linked list is empty \n" << endl;
		return NULL;
	}

	if(head->link == NULL) {
		delete head;
	}
	head = head->link;

	cout << "A node has been delete from the beginning \n" << endl;

	return head;
}

Node *deleteFromGivenNode(string givenNode, Node *head) {
	if(head == NULL) {
		cout << "The Node" + givenNode + " has been deleted. \n" << endl;
		return head;
	}
	Node *temp = new Node;
	Node *next = new Node;
	temp = head;
	next = temp->link;

	while(next->songName.compare(givenNode) !=0) {
		if(temp == NULL) {
			cout << "No Such node exist. \n" << endl;
			return head;
		}
		next = next->link;
		temp = temp->link;
	}
	temp->link = next->link;
	cout << "The Node " + givenNode + " has been deleted. \n" << endl;
	return head;
}

int main(){

	Node *head = createNode ("Marilag by Dionela");
	traverse(head);
	head = insertAtEnd("Loose by Daniel Caesar", head);
	traverse(head);
	head = insertAtEnd("Die With A Smile by BrunoMars", head);
	traverse(head);
	head = insertAtEnd("Higa by Arthur Nery", head);
	traverse(head);

	head = instertAtBeginning ("Binhi by Arthur Nery", head);
	traverse(head);
	head = instertAtBeginning ("Best Part by Daniel Ceasar", head);
	traverse(head);
	head = instertAtBeginning ("Take All The Love by Arthur Nery", head);
	traverse(head);
	head = instertAtBeginning ("Palagi by TJ Monterde", head);
	traverse(head);

	insertAfter ("Ikaw at Ako by TJ Monterde", "Best Part by Daniel Ceasar", head);
	traverse(head);
	insertAfter ("Happy w u by Arthur Nery","Take All The Love by Arthur Nery", head);
	traverse(head);
	insertAfter ("Marilag by Dionela", "Palagi by TJ Monterde", head);
	traverse(head);

	cout << deleteAtEnd(head);
	traverse(head);
	head = deleteFromBeginning(head);
	traverse(head);
	head = deleteFromGivenNode("Binhi by Arthur Nery",head);
	traverse(head);

	return 0;

}
