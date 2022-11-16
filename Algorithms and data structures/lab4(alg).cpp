#include <iostream>
#include <random>
#include <cmath>
#include <queue>

using namespace std;

int tab = 0;
int num_of_tab = 0;

struct Node
{
    int data;
    Node* left;
    Node* right;
    Node* parent;
};

struct Generator {
    int random;
};

Generator random() {
    random_device rd;
    mt19937 mt(rd());
    uniform_int_distribution<int> point(0, 100000);
    int random = point(mt);
    struct Generator Gen_elem;
    Gen_elem.random = random;
    return Gen_elem;
}

void add(int elem, Node*& branch)
{
    if (!branch)
    {
        branch = new Node;
        branch->data = elem;
        branch->left = 0;
        branch->right = 0;
        return;
    }
    else
    {
        if (branch->data > elem)
            add(elem, branch->left);
        else
            add(elem, branch->right);
    }
}

void print(Node* branch)
{
    if (!branch)
        return;
    tab += 5;
    print(branch->right);

    for (int i = 0; i < tab; i++)
        cout << " ";
    cout << "->";
    cout << branch->data << endl;
    print(branch->left);
    tab -= 5;
    return;
}

void preorder(Node*& branch)
{
    if (branch == NULL)
        return;
    cout << branch->data << " ";
    preorder(branch->left);
    preorder(branch->right);
}

void inorder(Node*& branch)
{
    if (branch == NULL)
        return;
    inorder(branch->left);
    cout << branch->data << " ";
    inorder(branch->right);
}

void postorder(Node*& branch)
{
    if (branch == NULL)
        return;
    postorder(branch->left);
    postorder(branch->right);
    cout << branch->data << " ";
}

void breadth_first(Node*& branch)
{
    if (branch == NULL) 
        return;
    queue<Node*>q;
    q.push(branch);
    while (q.empty() == false)
    {
        Node* node = q.front();
        cout << node->data << " ";
        q.pop();
        if (node->left != NULL)
            q.push(node->left);
        if (node->right != NULL)
            q.push(node->right);
    }
}

void delete_Tree(Node*& branch)
{
    if (!branch)
        return;
    delete_Tree(branch->left);
    delete_Tree(branch->right);
    delete branch;
    return;
}

Node* find_elem(Node*& branch, int elem)
{
    if (branch == NULL)
        return NULL;
    if (branch->data == elem)
        return branch;
    if (elem <= branch->data)
    {
        if (branch->left != NULL)
            return find_elem(branch->left, elem);
        else
            return NULL;
    }
    else
    {
        if (branch->right != NULL)
            return find_elem(branch->right, elem);
        else
            return NULL;
    }
}

int min_elem(Node*& branch)
{
    struct Node* cur = branch;
    while (cur->left != NULL)
        cur = cur->left;
    return (cur->data);
}

int max_elem(Node*& branch)
{
    struct Node* cur = branch;
    while (cur->right != NULL)
        cur = cur->right;
    return (cur->data);
}

Node* min_Node(Node*& branch)
{
    struct Node *cur = branch;
    while (cur && cur->left != NULL)
        cur = cur->left;
    return cur;
}

Node* delete_elem(Node*& branch, int elem) 
{
    if (branch == NULL)
        return branch;
    if (elem < branch->data)
        branch->left = delete_elem(branch->left, elem);
    else if(elem > branch->data)
        branch->right = delete_elem(branch->right, elem);
    else 
    {
        Node* tmp;
        if (branch->left == NULL)
        {
            tmp = branch->right;
            free(branch);
            return tmp;
        }
        else if (branch->right == NULL)
        {
            tmp = branch->left;
            free(branch);
            return tmp;
        }
        else if (branch->left == NULL && branch->right == NULL)
        {
            if (branch->data == elem)
                return NULL;
            else
                return branch;
        }
        tmp = min_Node(branch->right);
        branch->data = tmp->data;
        branch->right = delete_elem(branch->right, tmp->data);
    }
    return branch;
}

Node* next(Node*& branch, int elem)
{
    Node* cur = branch, *successor = NULL;
    while (cur != NULL)
    {
        if (cur->data > elem)
        {
            successor = cur;
            cur = cur->left;
        }
        else
            cur = cur->right;
    }
    return successor;
}

Node* previous(Node*& branch, int elem)
{
    Node* cur = branch, *prev = NULL;
    while (cur != NULL)
    {
        if (cur->data < elem)
        {
            prev = cur;
            cur = cur->right;
        }
        else
            cur = cur->left;
    }
    return prev;
}

void menu()
{
    Node* root = 0, *succ, *temp, *temp1, *prev, *tmp;
        int amount, element, choice;
        cout << "Enter the number of elements in the tree (up to 100):" << endl;
        cin >> amount;

        if (amount == 0)
        {
            cout << "No elements.";
            return;
        }

        for (int i = 0; i < amount; i++)
        {
            Generator rand_elem = random();
            int random = rand_elem.random;
            if (random > 100)
                amount++;
            if (random < 100)
                add(random, root);
        }

        cout << "Tree: " << endl;
        print(root);
        cout << endl;
    
    do {
        cout << "\nChoose:\n"
            "1 - Finding min\n"
            "2 - Finding max\n"
            "3 - Pre-order\n"
            "4 - In-order\n"
            "5 - Post-order\n"
            "6 - Breadth first\n"
            "7 - Element search\n"
            "8 - Finding the next element\n"
            "9 - Finding the previous element\n"
            "10 - Deleting an element\n"
            "11 - End.\n";

        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Min: " << min_elem(root);
            break;
        case 2:
            cout << "Max: " << max_elem(root);
            break;
        case 3:
            preorder(root);
            break;
        case 4:
            inorder(root);
            break;
        case 5:
            postorder(root);
            break;
        case 6:
            breadth_first(root);
            break;
        case 7:
            int element1;
            cout << "Enter element: ";
            cin >> element1;
            tmp = find_elem(root, element1);
            if (tmp == NULL)
                cout << "No element";
            else
                cout << "Element found";
            break;
        case 8:
            int element2;
            cout << "Enter element: ";
            cin >> element2;
            temp1 = find_elem(root, element2);
            if (temp1 == NULL)
                cout << "No element";
            else
            {
                succ = next(root, element2);
                if (succ != NULL)
                    cout << "Next element of " << element2 << " is " << succ->data;
                else
                    cout << "No next element";
            }
            break;
        case 9:
            int element3;
            cout << "Enter element: ";
            cin >> element3;
            temp = find_elem(root, element3);
            if (temp == NULL)
                cout << "No element";
            else
            {
                prev = previous(root, element3);
                if (prev != NULL)
                    cout << "Previous element of " << element3 << " is " << prev->data;
                else
                    cout << "No previous element";
            }
            break;
        case 10:
            cout << "Element to remove: ";
            cin >> element;
            delete_elem(root, element);
            print(root);
            break;
        case 11:
            break;
        }
    } while (choice != 11);
    delete_Tree(root);
}

int main()
{
    menu();
    cout << "Program is over.";
    return 0;
}
