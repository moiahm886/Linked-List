#include<iostream>
using namespace std;
struct Node
{
	int data;
	Node* next;
};
class list
{
	Node* head;
	int count;
public:
	list()
	{
		head = NULL;
		count = 0;
	}
	void insertatbeginning(Node* N, int val)
	{
		if (head == NULL)
		{
			N = new Node;
			N->data = val;
			N->next = NULL;
			head = N;
			count++;
		}
		else
		{
			N = new Node();
			N->data = val;
			N->next = head;
			head = N;
			count++;
		}
	}
	void insertatend(Node* N, int val)
	{
		Node *M = new Node();
		N = head;
		while (N->next != NULL)
		{
			N = N->next;
		}
		M->data = val;
		N->next = M;
		M->next = NULL;
		count++;
	}
	void insertinbetween(Node* N, int val, int search)
	{
		Node* M = new Node();
		N = head;
		while (N->data!= search)
		{
			N = N->next;
		}
		M->data = val;
		M->next = N->next;
		N->next = M;
		count++;
	}
	void deletebeginning(Node* N)
	{
		N = head;
		head = N->next;
		delete N;
		count--;
	}
	void deleteatend(Node* N)
	{
		N = head;
		while (N->next->next != NULL)
		{
			N = N->next;
		}
		delete N->next;
		N->next = NULL;
		count--;
	}
	void deleteinbetween(Node* N, int num)
	{
		N = head;
		Node* pre = NULL;
		while (N->data != num)
		{
			pre = N;
			N = N->next;
		}
		pre->next = N->next;
		delete N;
		count--;

	}
	void nodecount()
	{
		cout << "Number of Nodes in the list are " << count << endl;
	}
	bool search(Node* N, int val)
	{
		N = head;
		while (N->next != NULL)
		{
			if (N->data = val)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}
	void display(Node *N)
	{
		N = head;
		while (N!= NULL)
		{
			cout << N->data << "\t";
			N = N->next;
		}
		cout << endl;
	}
};
int main()
{
	Node* N = NULL;
	list l;
	l.insertatbeginning(N, 68);
	l.insertatbeginning(N, 56);
	l.insertatend(N, 98);
	l.insertatend(N, 27);
	l.insertatbeginning(N, 15);
	l.display(N);
	l.insertinbetween(N, 9, 68);
	l.display(N);
	l.deletebeginning(N);
	l.display(N);
	l.deleteatend(N);
	l.display(N);
	l.deleteatend(N);
	l.display(N);
	l.insertatbeginning(N, 43);
	l.insertatend(N, 98);
	l.display(N);
	l.deleteinbetween(N, 68);
	l.display(N);
	l.nodecount();
}