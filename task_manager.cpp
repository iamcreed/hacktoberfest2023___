#include <iostream>
#include <vector>
#include <string>

struct Task {
    std::string description;
    bool completed;

    Task(const std::string& desc) : description(desc), completed(false) {}
};

class TaskManager {
public:
    void addTask(const std::string& description) {
        tasks.push_back(Task(description));
        std::cout << "Task added: " << description << std::endl;
    }

    void viewTasks() {
        if (tasks.empty()) {
            std::cout << "No tasks to display." << std::endl;
        } else {
            std::cout << "Tasks:" << std::endl;
            for (int i = 0; i < tasks.size(); i++) {
                std::cout << i + 1 << ". ";
                if (tasks[i].completed) {
                    std::cout << "[X] ";
                } else {
                    std::cout << "[ ] ";
                }
                std::cout << tasks[i].description << std::endl;
            }
        }
    }

    void completeTask(int index) {
        if (index >= 0 && index < tasks.size()) {
            tasks[index].completed = true;
            std::cout << "Task completed: " << tasks[index].description << std::endl;
        } else {
            std::cout << "Invalid task index." << std::endl;
        }
    }

    void removeTask(int index) {
        if (index >= 0 && index < tasks.size()) {
            std::cout << "Task removed: " << tasks[index].description << std::endl;
            tasks.erase(tasks.begin() + index);
        } else {
            std::cout << "Invalid task index." << std::endl;
        }
    }

private:
    std::vector<Task> tasks;
};

int main() {
    TaskManager taskManager;
    int choice;

    std::cout << "Welcome to the Task Manager!" << std::endl;

    while (true) {
        std::cout << "\nOptions:" << std::endl;
        std::cout << "1. Add Task" << std::endl;
        std::cout << "2. View Tasks" << std::endl;
        std::cout << "3. Complete Task" << std::endl;
        std::cout << "4. Remove Task" << std::endl;
        std::cout << "5. Quit" << std::endl;
        std::cout << "Choose an option: ";

        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter task description: ";
                std::cin.ignore();
                std::string description;
                std::getline(std::cin, description);
                taskManager.addTask(description);
                break;
            case 2:
                taskManager.viewTasks();
                break;
            case 3:
                int completeIndex;
                std::cout << "Enter the index of the task to mark as completed: ";
                std::cin >> completeIndex;
                taskManager.completeTask(completeIndex - 1);
                break;
            case 4:
                int removeIndex;
                std::cout << "Enter the index of the task to remove: ";
                std::cin >> removeIndex;
                taskManager.removeTask(removeIndex - 1);
                break;
            case 5:
                std::cout << "Goodbye!" << std::endl;
                return 0;
            default:
                std::cout << "Invalid choice. Try again." << std::endl;
        }
    }

    return 0;
}
