#include <iostream>

using namespace std;

struct List
{
	double element;
	List* next;
};

void insert_at_the_beggining(List*& element2, int position, int add_element)
{
	int number = 1;
	int number1;
	List* currentnew, * current = element2;
	currentnew = new List;
	currentnew->element = add_element;
	if (position <= 1 || element2 == NULL)
	{
		currentnew->next = element2;
		element2 = currentnew;
	}
	else
	{
		for (number1 = 1; number1 < position - 1; number1++)
			if (current->next != NULL)
			{
				current = current->next;
				number++;
			}
		if (position <= number + 1)
		{
			currentnew->next = current->next;
			current->next = currentnew;
		}
	}
}

void insert_end(List*& element4, int position, int add_element)
{
	int number = 1;
	int number1;
	List* currentnew, * current = element4;
	currentnew = new List;
	currentnew->element = add_element;
	if (position <= 1 || element4 == NULL)
	{
		currentnew->next = element4;
		element4 = currentnew;
	}
	else
	{
		for (number1 = 1; number1 < position - 1; number1++)
			if (current->next != NULL)
			{
				current = current->next;
				number++;
			}
		if (position <= number + 1)
		{
			currentnew->next = current->next;
			current->next = currentnew;
		}
	}
}

void add(List*& element3, int position, int add_element)
{
	int number = 0;
	int number1;
	List* currentnew, * current = element3;
	currentnew = new List;
	currentnew->element = add_element;
	if (position <= 0 || element3 == NULL)
	{
		currentnew->next = element3;
		element3 = currentnew;
	}
	else
	{
		for (number1 = 0; number1 < position - 1; number1++)
			if (current->next != NULL)
			{
				current = current->next;
				number++;
			}
		if (position <= number + 1)
		{
			currentnew->next = current->next;
			current->next = currentnew;
		}
	}
}

void PrintList(List* head)
{
	cout << "List: ";
	while (head != NULL)
	{
		cout << head->element << " ";
		head = head->next;
	}
	cout << endl;
}

bool empty(List* head)
{
	return head == NULL;
}


void Delete_Element(int position, List*& head)
{
	int amount = 0;
	List* cur = head;
	while (cur != NULL)
	{
		amount++;
		cur = cur->next;
	}
	if (position < 0 || position >= amount) {
		cout << "There is no element.\n";
		return;
	}

	if (position == 0)
	{
		cur = head;
		head = head->next;
		delete cur;
	}
	else
	{
		cur = head;
		for (int i = 0; i < position - 1; i++) {
			cur = cur->next;
		}
		List* tmp = cur->next;
		cur->next = tmp->next;
		delete tmp;
	}
}

void Delete_First(List*& head)
{
	if (!empty(head))
	{
		List* cur = head;
		head = head->next;
		delete cur;
	}
	else
		cout << "No elements in list.\n";
}

void Delete_End(List*& head)
{
	int amount = 0;
	List* cur = head;
	while (cur != NULL)
	{
		amount++;
		cur = cur->next;
	}
	Delete_Element(amount - 1, head);
}

void Delete_All(int position, List*& head)
{
	List*& cur = head;
	List* curnew = cur->next;
	if (position == 1) {
		cur = cur->next;
	}
	else {

		while (position > 2)
		{
			position--;
			cur = cur->next;
			curnew = curnew->next;
			if (curnew == NULL) break;
		}
		if (curnew != NULL) {
			cur->next = curnew->next;
		}
	}
}

int size(List* head)
{
	int amount;
	amount = 0;

	while (head != NULL)
	{
		amount++;
		head = head->next;
	}
	return amount;
}

void sizeList(List* head)
{
	int amount;
	amount = 0;

	while (head != NULL)
	{
		amount++;
		head = head->next;
	}
	cout << "List size: " << amount << "\n";
}

void found(List* head)
{
	int index;
	cout << "Enter index: \n";
	cin >> index;
	int number = 0;
	int number1;
	List* cur = head;
	if (index == 0)
	{
		cout << "Found element: " << head->element << "\n";
	}
	if (index < 0)
		cout << "No element\n";
	else if (index > 0)
	{
		if (index >= size(head))
		{
			cout << "No element\n";
			return;
		}
		while (index)
		{
			cur = cur->next;
			index--;
		}
		cout << "Found element: " << cur->element << "\n";
	}
}

void replace(List*& head)
{
	List* add_element = new List;
	List* cur = head;
	List* cur_prev = head;
	int index;
	cout << "Enter index:\n";
	cin >> index;
	cout << "Enter add element:\n";
	cin >> add_element->element;
	if (index == 0)
	{
		add_element->next = head->next;
		delete head;
		head = add_element;
	}
	if (index < 0)
		cout << "No element\n";
	else if (index > 0)
	{
		if (index >= size(head))
		{
			cout << "No element\n";
			return;
		}
		while (index)
		{
			cur = cur->next;
			index--;
			if (index == 1)
			{
				cur_prev = cur;
			}
		}
		cur_prev->next = add_element;
		add_element->next = cur->next;
		delete cur;
	}
}

void insert_list(List* head, List* head2)
{
	List* cur = head;
	List* cur1 = head2;
	int index;
	cout << "Enter index:\n";
	cin >> index;
	if (index == 0)
	{
		cur1 = head2;
		while (cur1->next != NULL)
		{
			cur1 = cur1->next;
		}
		cur1->next = head->next;
		head->next = head2;
	}
	if (index < 0)
		cout << "No place to insert.\n";
	else if (index > 0)
	{
		if (index >= size(head))
		{
			cout << "No place to insert.\n";
			return;
		}
		cur = head;
		while (index)
		{
			cur = cur->next;
			index--;

		}
		cur1 = head2;
		while (cur1->next != NULL)
		{
			cur1 = cur1->next;
		}
		cur1->next = cur->next;
		cur->next = head2;
	}
}

void menu(List*& head)
{
	int choice;
	do {
		cout << "Выберите какое действие необходимо выполнить:\n"
			"1 - Добавление в конец списка.\n"
			"2 - Добавление в начало списка.\n"
			"3 - Удаление последнего элемента.\n"
			"4 - Удаление первого элемента.\n"
			"5 - Добавление элемента по индексу (вставка перед элементом, который был ранее доступен по этому индексу).\n"
			"6 - Получение элемента по индексу.\n"
			"7 - Удаление элемента по индексу.\n"
			"8 - Получение размера списка.\n"
			"9 - Удаление всех элементов списка.\n"
			"10 - Замена элемента по индексу на передаваемый элемент.\n"
			"11 - Проверка на пустоту списка.\n"
			"12 - Вставка другого списка в список, начиная с индекса.\n"
			"13 - Вывод всего списка.\n"
			"14 - Завершение программы.\n";

		cin >> choice;
		List* head2 = NULL;
		int size_list2 = 0;
		int position_end_list = 0;
		int element_list2 = 0;
		switch (choice)
		{
		case 1:
			int position_end_add, add_element2;
			position_end_add = size(head) + 1;
			cout << "Enter the element please: \n";
			cin >> add_element2;
			insert_end(head, position_end_add, add_element2);
			break;
		case 2:
			int position_add_first, add_element;
			position_add_first = 0;
			cout << "Enter the element please: \n";
			cin >> add_element;
			insert_at_the_beggining(head, position_add_first, add_element);
			break;
		case 3:
			Delete_End(head);
			break;
		case 4:
			Delete_First(head);
			break;
		case 5:
			int position, add_element1;
			cout << "Enter the position please: \n";
			cin >> position;
			cout << "Enter the added element please: \n";
			cin >> add_element1;
			add(head, position, add_element1);
			break;
		case 6:
			found(head);
			break;
		case 7:
			int position2;
			cout << "Enter the position: \n";
			cin >> position2;
			Delete_Element(position2, head);
			break;
		case 8:
			sizeList(head);
			break;
		case 9:
			int position_delete;
			position_delete = size(head);
			Delete_All(position_delete, head);
			int position_delete1;
			position_delete1 = 1;
			if (position_delete > 1)
				Delete_All(position_delete1, head);
			cout << "List deleted.\n";
			break;
		case 10:
			replace(head);
			break;
		case 11:
			if (!empty(head))
				cout << "List isn't empty.\n";
			if (empty(head))
				cout << "List empty.\n";
			break;
		case 12:
			cout << "Enter size of list 2: \n";
			cin >> size_list2;
			position_end_list = size_list2;
			for (int i = 0; i < size_list2; i++)
			{
				cout << "Enter element of list2: \n";
				cin >> element_list2;
				insert_end(head2, position_end_list, element_list2);
			}
			insert_list(head, head2);
			break;
		case 13:
			PrintList(head);
			break;
		case 14:
			break;
		}
	} while (choice != 14);
}

int main()
{
	setlocale(LC_ALL, "Rus");
	List* list = NULL;
	menu(list);
	cout << "Program is over.";
	return 0;
}
