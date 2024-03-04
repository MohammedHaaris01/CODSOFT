#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

// Structure to represent a task
struct Task {
    string description;
    bool completed;

    Task(const string& desc, bool comp) : description(desc), completed(comp) {}
};

// Function to add a task to the list
void addTask(vector<Task>& tasks, const string& description) {
    tasks.push_back(Task(description, false));
    cout << "Task added successfully!" << endl;
}

// Function to view all tasks
void viewTasks(const vector<Task>& tasks) {
    cout << "Tasks:" << endl;
    for (size_t i = 0; i < tasks.size(); ++i) {
        cout << i+1 << ". " << (tasks[i].completed ? "[X] " : "[ ] ") << tasks[i].description << endl;
    }
}

// Function to mark a task as completed
void markCompleted(vector<Task>& tasks, int index) {
    if (index >= 1 && index <= static_cast<int>(tasks.size())) {
        tasks[index-1].completed = true;
        cout << "Task marked as completed!" << endl;
    } else {
        cout << "Invalid task index!" << endl;
    }
}

// Function to remove a task
void removeTask(vector<Task>& tasks, int index) {
    if (index >= 1 && index <= static_cast<int>(tasks.size())) {
        tasks.erase(tasks.begin() + index - 1);
        cout << "Task removed successfully!" << endl;
    } else {
        cout << "Invalid task index!" << endl;
    }
}

// Function to save tasks to a file
void saveTasksToFile(const vector<Task>& tasks, const string& filename) {
    ofstream file(filename);
    if (file.is_open()) {
        for (const Task& task : tasks) {
            file << task.description << "," << (task.completed ? "1" : "0") << endl;
        }
        file.close();
        cout << "Tasks saved to " << filename << " successfully!" << endl;
    } else {
        cout << "Error: Unable to open file for writing!" << endl;
    }
}

// Function to load tasks from a file
void loadTasksFromFile(vector<Task>& tasks, const string& filename) {
    ifstream file(filename);
    if (file.is_open()) {
        tasks.clear();
        string line;
        while (getline(file, line)) {
            size_t pos = line.find(",");
            if (pos != string::npos) {
                string desc = line.substr(0, pos);
                bool completed = (line.substr(pos + 1) == "1");
                tasks.push_back(Task(desc, completed));
            }
        }
        file.close();
        cout << "Tasks loaded from " << filename << " successfully!" << endl;
    } else {
        cout << "No existing task file found. Starting with an empty list." << endl;
    }
}

int main() {
    vector<Task> tasks;
    const string filename = "tasks.txt"; // File to store tasks
    loadTasksFromFile(tasks, filename);

    char choice;

    do {
        cout << "TODO LIST MANAGER" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. View Tasks" << endl;
        cout << "3. Mark Task as Completed" << endl;
        cout << "4. Remove Task" << endl;
        cout << "5. Save Tasks" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case '1': {
                cin.ignore(); // Clear input buffer
                string taskDescription;
                cout << "Enter task description: ";
                getline(cin, taskDescription);
                addTask(tasks, taskDescription);
                break;
            }
            case '2':
                viewTasks(tasks);
                break;
            case '3': {
                int index;
                cout << "Enter task index to mark as completed: ";
                cin >> index;
                markCompleted(tasks, index);
                break;
            }
            case '4': {
                int index;
                cout << "Enter task index to remove: ";
                cin >> index;
                removeTask(tasks, index);
                break;
            }
            case '5':
                saveTasksToFile(tasks, filename);
                break;
            case '6':
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice! Please enter a valid option." << endl;
        }
    } while (choice != '6');

    return 0;
}
