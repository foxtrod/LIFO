#include <iostream>

using namespace std;

struct list
{
	int data;
	list *next;
};

list *head = NULL;

void add(int x)
{
	list *tmp = new list;
	tmp->data = x;
	tmp->next = head;
	head = tmp;
}

void print()
{
	list *tmp = head;
	while (tmp != NULL)
	{
		cout << tmp->data << " ";
		tmp = tmp->next;
	}
	cout << endl;
}

void clear()
{
	while (head != NULL)
	{
		list *tmp = head->next;
		delete head;
		head = tmp;
	}
}

void shunkevich()
{
	list *tmp = head;
	list *qwe = head; 
	list *_tmp = head;
	int max = tmp->data;
	while(tmp != NULL)
	{
		if (tmp->data > max)
		{
			max = tmp->data;
		}
		tmp = tmp->next;
	}
	while (head->data != max)
	{
		_tmp = head;
		head = head->next;
	}
	head = qwe;
	int s = _tmp->next->data;
	_tmp->next = _tmp->next->next;

	list *temp = new list;
	temp->next = head;
	temp->data = s;
	head = temp;
	print();
}

int main()
{
	add(10);
	add(49);
	add(31);
	add(13);
	add(7);
	print();
	shunkevich();
	clear();
}