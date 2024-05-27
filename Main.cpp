#include <iostream>
#include "ToDoList.h"
#include <limits>

using namespace std;
void printMenu()
{
    cout << endl
         << "------------MENU------------" << endl;
    cout << "1. Add a task." << endl;
    cout << "2. Remove a task. " << endl;
    cout << "3. Display all tasks." << endl;
    cout << "4. Update task status." << endl;
    cout << "5. Get tasks by priority." << endl;
    cout << "6. Get tasks by status." << endl;
    cout << "7. Get tasks by category." << endl;
    cout << "8. Tasks Stats." << endl;
    cout << "0. Exit." << endl;
    cout << "Enter your choice:" << endl;
}

int main()
{
    ToDoList tasks;

    while (true)
    {
        int choice;
        printMenu();
        cin >> choice;
        if (cin.fail() || cin.peek() != '\n')
        {
            cerr << "Error: Input is not an integer." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else
        {
            cout << "Your Choice : " << choice << endl;
            if (choice == 1)
            {
                int id;
                string description;
                string priority;
                string category;
                int x;
                cout << "Enter Task Id: ";
                cin >> id;
                cout << "Enter Task Description: ";
                getline(cin >> ws, description);
                cout << "Select Task Priority: \n";
                cout << "1.High\n2.Medium\n3.Low\n";
                cin >> x;
                if (x == 1)
                {
                    priority = "High";
                }
                else if (x == 2)
                {
                    priority = "Medium";
                }
                else if (x == 3)
                {
                    priority = "Low";
                }
                else
                {
                    priority = "Undefined";
                }
                cout << "Select Task Category: \n";
                cout << "1.Personal\n2.Professional\n";
                cin >> x;
                if (x == 1)
                {
                    category = "Personal";
                }
                else if (x == 2)
                {
                    category = "Professional";
                }
                else
                {
                    category = "Undefined";
                }
                tasks.insert(id, description, priority, category);
            }
            else if (choice == 2)
            {
                int id;
                cout << "Enter Task Id to remove: ";
                cin >> id;
                if (cin.fail() || cin.peek() != '\n')
                {
                    cerr << "Error: Input is not an integer." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                else
                {
                    tasks.remove(id);
                }
            }
            else if (choice == 3)
            {
                tasks.display();
            }
            else if (choice == 4)
            {
                int id;
                string status;
                int x;
                cout << "Enter Task Id to update status: ";
                cin >> id;
                cout << "Select new status: \n";
                cout << "1.Complete\n2.Incomplete\n";
                cin >> x;
                if (x == 1)
                {
                    status = "Complete";
                }
                else if (x == 2)
                {
                    status = "Incomplete";
                }
                else
                {
                    cout << "Invalid Choice!" << endl;
                    continue;
                }
                tasks.updateStatus(id, status);
            }
            else if (choice == 5)
            {
                string priority;
                int x;
                cout << "Select priority to get tasks: \n";
                cout << "1.High\n2.Medium\n3.Low\n";
                cin >> x;
                if (x == 1)
                {
                    priority = "High";
                }
                else if (x == 2)
                {
                    priority = "Medium";
                }
                else if (x == 3)
                {
                    priority = "Low";
                }
                else
                {
                    cout << "Invalid Choice!" << endl;
                }
                tasks.getByPriority(priority);
            }
            else if (choice == 6)
            {
                string status;
                int x;
                cout << "Select status to get tasks: \n";
                cout << "1.Complete\n2.Incomplete\n";
                cin >> x;
                if (x == 1)
                {
                    status = "Complete";
                }
                else if (x == 2)
                {
                    status = "Incomplete";
                }
                else
                {
                    cout << "Invalid Choice!" << endl;
                }
                tasks.getByStatus(status);
            }
            else if (choice == 7)
            {
                string category;
                int x;
                cout << "Select category to get tasks: \n";
                cout << "1.Personal\n2.Professional\n";
                cin >> x;
                if (x == 1)
                {
                    category = "Personal";
                }
                else if (x == 2)
                {
                    category = "Professional";
                }
                else
                {
                    cout << "Invalid Choice!" << endl;
                }
                tasks.getByCategory(category);
            }
            else if (choice == 8)
            {
                cout << " -----------------------------------\n";
                cout << "|             Statistics           |"
                     << "\n -----------------------------------\n";
                cout << "Tottal tasks: " << tasks.length() << endl;
                cout << "Completed tasks: " << tasks.completed() << endl;
                cout << "Pending tasks: " << tasks.pending() << endl;
                cout << "Personal tasks: " << tasks.personal() << endl;
                cout << "Professional tasks: " << tasks.professional() << endl;
                cout << "High Priority tasks: " << tasks.high() << endl;
                cout << "Medium Priority tasks: " << tasks.medium() << endl;
                cout << "Low Priority tasks: " << tasks.low() << endl;
            }
            else if (choice == 0)
            {
                cout << "Exiting the Program. Thanks for Using :)";
                break;
            }
            else
            {
                cout << "\nInvalid Option\n";
            }
        }
    }

    return 0;
}