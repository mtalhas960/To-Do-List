
# To Do List

A robust task management tool designed to streamline the process of organizing, tracking, and prioritizing tasks.




## Objectives
 - Facilitating seamless task addition, removal, and status updates.
 -	Offering versatile task retrieval options based on priority, status, and category
 - Providing insightful statistics to help users gain better insights into their task management habits.
## Design Overview
-  ### Task Class:
    The Task class encapsulates taskspecific attributes such as ID, description, priority, category, and status. Additionally, it provides methods for printing task details and updating task status.
- ### Node Class:
    The Node class represents a node within the linked list, housing a Task object and pointers to the next and previous nodes. This enables seamless navigation through the task list.
- ### ToDoList Class:
    The ToDoList class serves as the core component of the application, offering functionalities for task manipulation, retrieval, and statistical analysis. It provides a cohesive interface for users to interact with their tasks efficiently.
- ### Main Program:
    The main program encapsulates the user interface logic, presenting users with a menudriven interface for performing various tasks such as adding, removing, updating, and viewing tasks.
##  Usage Instructions
-  ### Adding a Task:
    Choose option 1 from the menu. Enter task details such as ID, description, priority, and category.

- ### Removing a Task:
    Choose option 2 from the menu. Enter the ID of the task to be removed.
- ### Updating Task Status:
    Choose option 4 from the menu. Enter the ID of the task whose status you want to update. Choose the new status from the menu.
- ### Viewing Tasks:
    Choose options 3, 5, 6, or 7 from the menu to view tasks based on priority, status, or category.
- ### Statistics:
    Choose options 8 from the menu to view tasks stats such as number of tasks of a specific priority, status, or category.
## Conclusion
In conclusion, the ToDo List Application offers a comprehensive solution for efficient task management. By providing users with intuitive functionalities and insightful analytics, it empowers individuals to stay organized, focused, and productive in their daily endeavors.
