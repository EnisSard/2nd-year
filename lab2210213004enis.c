#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct numbernode {
    int number;
    struct numbernode* next; // I defined a structure for a number and a pointer to the next node
};
struct StudentNode {
    int number;
    char name[100];
    int age;
    struct StudentNode* next; // I defined another structure for a student node containing a student number, name, age, and a pointer to the next node
};
struct numbernode* addNumberToList(struct numbernode* head, int num) {
    struct numbernode* newNode = (struct numbernode*)malloc(sizeof(struct numbernode)); // This struct allocates memory for a new node
    newNode->number = num; // Assigns the input number to the new node
    newNode->next = NULL; // Sets the next pointer of the new node to NULL so it doesn't get mixed up later
    if (!head) {
    return newNode; // If the list is empty, returns the new node as the head of the list
}
    struct numbernode* current = head;
    while (current->next) {
    current = current->next;
    }
    current->next = newNode; // Sets the new node to the end of the list
    return head; 
}
struct numbernode* generateRandomNumbers(int count) {
    struct numbernode* head = NULL; 
    for (; count > 0; --count) { // Loops as many times as count 
        int num = rand() % 100 + 1; // Generates a random number between 1 and 100
        head = addNumberToList(head, num); // Adds the generated number to the list
    }
    return head; 
}
void printNumbers(struct numbernode* head) {
    while (head) {
        printf("%d -> ", head->number); // Prints the number stored in the current node
        head = head->next; // Moves to the next node
    }
}
struct numbernode* sortNumbers(struct numbernode* head) {
    if (!head || !head->next) {
    return head; // Returns the list if it is empty or contains only one node
    }
    struct numbernode* sorted = NULL; 
    while (head) {
        struct numbernode* current = head;
        head = head->next; // Removes the current node from the original list
        if (!sorted || current->number > sorted->number) {
        current->next = sorted;
        sorted = current; // Inserts the current node at the beginning of the sorted list (if it's larger)
        } else {
        struct numbernode* temp = sorted;
        while (temp->next && !(current->number > temp->next->number)) {
        temp = temp->next; 
        }
        current->next = temp->next;
        temp->next = current; // Inserts the current node in the middle of the sorted list 
        }
    }
    return sorted; 
}
struct StudentNode* addStudent(struct StudentNode* head, int num, char* name, int age) {
    struct StudentNode* newNode = (struct StudentNode*)malloc(sizeof(struct StudentNode)); // Creates memory for a new student node
    newNode->number = num; // Gives student number to the new node
    strcpy(newNode->name, name); // Copies name string to the new node
    newNode->age = age; // Sets age to the new node
    newNode->next = head; // Sets the next pointer of node to the current head of the student list
    return newNode; // Returns node as head of student list
}
void displayStudentInfo(struct StudentNode* head) {
    int count = 1;
    while (head != NULL) {
        printf("%d- %s %d %d\n", count, head->name, head->age, head->number); // Prints student information
        head = head->next; // Moves to the next student node
        count++;
    }
}
struct StudentNode* searchByName(struct StudentNode* head, char* name) {
    while (head != NULL) {
        if (strcmp(head->name, name) == 0) {
        printf("Found: %s %d %d\n", head->name, head->age, head->number); // Prints found student information
        return head; // Returns found node
    }
    head = head->next; // Moves to next node
    }
    printf("Student with name '%s' not found.\n", name);
    return NULL; // Returns NULL if the student is not found
}
struct StudentNode* deleteNextWithName(struct StudentNode* head, char* name) {
    struct StudentNode* current = head;
    while (current != NULL && current->next != NULL) {
        if (strcmp(current->next->name, name) == 0) {
        struct StudentNode* temp = current->next;
        current->next = temp->next; // Removes the next student node
        free(temp); // Frees the memory of the removed node
        printf("Next student with name '%s' deleted.\n", name);
        return head; // Returns head of the student list
    }
    current = current->next; // Moves to the next student node
    }
    printf("No student with name '%s' found in the next node.\n", name);
    return head; // Returns head if student is not found
}
void findLongestName(struct StudentNode* head) {
    int maxLength = 0;
    char* longestName = NULL;
    while (head != NULL) {
        int currentLength = strlen(head->name);
        if (currentLength > maxLength) {
            maxLength = currentLength;
            longestName = head->name;
        }
        head = head->next; // Moves to the next student node
    }
    if (longestName != NULL) {
        printf("The longest name in the list: %s\n", longestName); // Prints the longest name
        printf("Length: %d\n", maxLength); // Prints the length of the longest name
    } else {
    printf("No names in the list.\n");
    }
}
void freeNumberList(struct numbernode* head) {
    while (head != NULL) {
        struct numbernode* temp = head;
        head = head->next; // Moves to the next node
        free(temp); // Frees the memory of the current node
    }
}
void freeStudentList(struct StudentNode* head) {
    while (head != NULL) {
        struct StudentNode* temp = head;
        head = head->next; 
        free(temp); 
    }
}
int main() {
    struct numbernode* numbersHead = NULL; //Sets pointer to Null
    struct StudentNode* studentsHead = NULL;
    int choice,count2,age,number,num;
    char name[100];
    do {
        printf("\nMenu:\n");
        printf("1. Add a number to the list\n");
        printf("2. Generate random numbers\n");
        printf("3. Display list of numbers\n");
        printf("4. Sort list of numbers\n");
        printf("5. Add a student\n");
        printf("6. Display student info\n");
        printf("7. Search by name\n");
        printf("8. Delete next node by name\n");
        printf("9. Find longest name\n");
        printf("10. Exit\n");
        printf("Enter your choice:");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
            printf("Enter a number, enter -1 to exit:");
            while (1) {
    		scanf("%d", &num);
    		numbersHead = addNumberToList(numbersHead, num);
   		 	if (num == -1) {
        	break; // Exit the loop when num equals -1 }
			}
			}	
            break;
            case 2:
            printf("Enter the number of random numbers to generate: ");
			scanf("%d", &count2);
            numbersHead = generateRandomNumbers(count2);
            break;
            case 3:
            printNumbers(numbersHead);
            break;
            case 4:
            numbersHead = sortNumbers(numbersHead);
            break;
            case 5:
            printf("Enter student name, age, and number(ex. Enis 19 211): ");
            scanf("%s %d %d", name, &age, &number);
            studentsHead = addStudent(studentsHead, number, name, age);
            break;
            case 6:
            displayStudentInfo(studentsHead);
            break;
            case 7:
        	printf("Enter the name to search: ");
            scanf("%s", name);
            struct StudentNode* foundStudent = searchByName(studentsHead, name);
            break;
            case 8:
            printf("Enter the name to delete next node: ");
            scanf("%s", name);
            studentsHead = deleteNextWithName(studentsHead, name);
            break;
            case 9:
            findLongestName(studentsHead);
            break;
            case 10:
            freeNumberList(numbersHead);
            freeStudentList(studentsHead);
            printf("Exiting....");
            break;
            default:
            printf("Wrong input, please try again");
        }
    } while (choice != 10);
    return 0;
}
