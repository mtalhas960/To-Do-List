#include <iostream>
using namespace std;

class Task
{
public:
    int id;
    string description;
    string priority;
    string category;
    string status;
    void printTask()
    {
        cout << "Task Id: " << id << endl;
        cout << "Task Description: " << description << endl;
        cout << "Task Priority: " << priority << endl;
        cout << "Task Category: " << category << endl;
        cout << "Completion Status: " << status << endl;
    }
};

class Node
{
private:
    Node *next;
    Node *previous;
    Task *task;

public:
    Node()
    {
        next = NULL;
        previous = NULL;
        task = new Task();
    }
    void setTask(int id, string description, string priority, string category)
    {
        this->task->id = id;
        this->task->description = description;
        this->task->priority = priority;
        this->task->category = category;
        this->task->status = "Incomplete";
    }
    Task *getTask()
    {
        return this->task;
    }
    void setNext(Node *nextNode)
    {
        this->next = nextNode;
    }
    Node *getNext()
    {
        return next;
    }
    void setPrevious(Node *prevNode)
    {
        this->previous = prevNode;
    }
    Node *getPrevious()
    {
        return previous;
    }
};

class ToDoList
{
private:
    Node *head;
    Node *current;
    int size;

public:
    ToDoList()
    {
        head = new Node();
        head->setNext(NULL);
        head->setPrevious(NULL);
        current = head;
        size = 0;
    }

    int length()
    {
        return size;
    }

    int completed()
    {
        int count = 0;
        Node *temp = head;
        while (temp->getNext() != NULL)
        {
            temp = temp->getNext();
            if (temp->getTask()->status == "Complete")
            {
                count++;
            }
        }
        return count;
    }

    int pending()
    {
        int count = 0;
        Node *temp = head;
        while (temp->getNext() != NULL)
        {
            temp = temp->getNext();
            if (temp->getTask()->status == "Incomplete")
            {
                count++;
            }
        }
        return count;
    }

    int personal()
    {
        int count = 0;
        Node *temp = head;
        while (temp->getNext() != NULL)
        {
            temp = temp->getNext();
            if (temp->getTask()->category == "Personal")
            {
                count++;
            }
        }
        return count;
    }

    int professional()
    {
        int count = 0;
        Node *temp = head;
        while (temp->getNext() != NULL)
        {
            temp = temp->getNext();
            if (temp->getTask()->category == "Professional")
            {
                count++;
            }
        }
        return count;
    }

    int high()
    {
        int count = 0;
        Node *temp = head;
        while (temp->getNext() != NULL)
        {
            temp = temp->getNext();
            if (temp->getTask()->priority == "High")
            {
                count++;
            }
        }
        return count;
    }

    int medium()
    {
        int count = 0;
        Node *temp = head;
        while (temp->getNext() != NULL)
        {
            temp = temp->getNext();
            if (temp->getTask()->priority == "Medium")
            {
                count++;
            }
        }
        return count;
    }

    int low()
    {
        int count = 0;
        Node *temp = head;
        while (temp->getNext() != NULL)
        {
            temp = temp->getNext();
            if (temp->getTask()->priority == "Low")
            {
                count++;
            }
        }
        return count;
    }

    void insert(int id, string description, string priority, string category)
    {
        while (current->getNext() != NULL)
        {
            current = current->getNext();
        }
        Node *newNode = new Node();
        newNode->setTask(id, description, priority, category);
        newNode->setNext(NULL);
        current->setNext(newNode);
        newNode->setPrevious(current);
        current = newNode;
        size++;
        cout << "Task added successfully";
    }

    void remove(int id)
    {
        cout << "Removing task with Id: " << id << endl;
        Node *temp = head->getNext();
        int found = 0;
        while (temp != NULL)
        {
            if (temp->getTask()->id == id)
            {
                found = 1;
                break;
            }
            else
            {
                temp = temp->getNext();
            }
        }
        if (found == 1)
        {
            current = temp;
            if (current->getNext() != NULL)
            {
                current->getPrevious()->setNext(current->getNext());
                current->getNext()->setPrevious(current->getPrevious());
                size--;
            }
            else if (current->getNext() == NULL)
            {
                current->getPrevious()->setNext(NULL);
                size--;
            }
            cout << "Task with id " << id << " removed\n";
        }
        else
        {
            cout << "Task with id " << id << " not found\n";
        }
        current = head->getNext() == NULL ? head : head->getNext();
    }

    void updateStatus(int id, string status)
    {
        cout << "Updating status of task with Id " << id << " to " << status << endl;
        Node *temp = head;
        while (temp->getNext() != NULL)
        {
            temp = temp->getNext();
            if (temp->getTask()->id == id)
            {
                temp->getTask()->status = status;
                return;
            }
        }
        cout << "Task with id " << id << " not found\n";
        current = head->getNext() == NULL ? head : head->getNext();
    }

    void getByPriority(string priority)
    {
        if (size == 0)
        {
            cout << "List is empty" << endl;
        }
        else
        {
            cout << " -----------------------------------\n";
            cout << "|        " << priority << " Priority Tasks        |"
                 << "\n -----------------------------------\n";
            Node *temp = head;
            while (temp->getNext() != NULL)
            {
                temp = temp->getNext();
                if (temp->getTask()->priority == priority)
                {
                    temp->getTask()->printTask();
                    cout << "\n-----------------\n";
                }
            }
        }
    }

    void getByStatus(string status)
    {
        if (size == 0)
        {
            cout << "List is empty" << endl;
        }
        else
        {
            cout << " -----------------------------------\n";
            cout << "|          " << status << " Task          |"
                 << "\n -----------------------------------\n";
            Node *temp = head;
            while (temp->getNext() != NULL)
            {
                temp = temp->getNext();
                if (temp->getTask()->status == status)
                {
                    temp->getTask()->printTask();
                    cout << "\n-----------------\n";
                }
            }
        }
    }

    void getByCategory(string category)
    {
        if (size == 0)
        {
            cout << "List is empty" << endl;
        }
        else
        {
            cout << " -----------------------------------\n";
            cout << "|          " << category << " Task          |"
                 << "\n -----------------------------------\n";
            Node *temp = head;
            while (temp->getNext() != NULL)
            {
                temp = temp->getNext();
                if (temp->getTask()->category == category)
                {
                    temp->getTask()->printTask();
                    cout << "\n-----------------\n";
                }
            }
        }
    }

    void display()
    {
        if (size == 0)
        {
            cout << "List is empty" << endl;
        }
        else
        {
            cout << " -----------------------------------\n";
            cout << "|             To Do List           |"
                 << "\n -----------------------------------\n";
            Node *temp = head;
            while (temp->getNext() != NULL)
            {
                temp = temp->getNext();
                temp->getTask()->printTask();
                cout << "\n-----------------\n";
            }
        }
    }
};