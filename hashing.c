#include<stdio.h>
#include<stdlib.h>

#define size 10

struct node {
    int info;
    struct node* next;
};

struct node* getnode() {
    struct node* newnode = malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("No Memory Available!\n");
        exit(0);
    }
    return newnode;
}

int hash1(int x) {
    return (x % size);
}

int hash2(int x, int i) {
    return ((hash1(x) + i) % size);
}

int hash3(int x, int i) {
    return ((hash1(x) + i * i) % size);
}

void insert_open_Addressing(int hashtable[], int x, int choice) {
    if (!hashtable[hash1(x)]) {
        hashtable[hash1(x)] = x;
    } else {
        int inserted = 0;
        for (int i = 1; i < size; i++) {
            int index = (choice == 2) ? hash2(x, i) : hash3(x, i);
            if (!hashtable[index]) {
                hashtable[index] = x;
                printf("Element has been inserted into hash table at location %d\n", index);
                inserted = 1;
                break;
            }
        }
        if (!inserted) {
            printf("No memory location available in hash table!\n");
        }
    }
}

void insert_seperate_chaining(struct node* arr[], int x) {
    struct node* newnode = getnode();
    newnode->info = x;
    newnode->next = NULL;

    int index = hash1(x);
    if (arr[index] == NULL) {
        arr[index] = newnode;
    } else {
        struct node* ptr = arr[index];
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = newnode;
    }
}

void search_seperate(struct node* arr[], int x) {
    int index = hash1(x);
    if (arr[index] == NULL) {
        printf("No such key found!\n");
    } else {
        struct node* ptr = arr[index];
        while (ptr != NULL && ptr->info != x) {
            ptr = ptr->next;
        }
        if (ptr == NULL) {
            printf("No such key found!\n");
        } else {
            printf("Key found at location %d in the hash table!\n", index);
        }
    }
}

void search_open(int hashtable[], int x, int choice) {
    for (int i = 0; i < size; i++) {
        int index = (choice == 2) ? hash2(x, i) : hash3(x, i);
        if (hashtable[index] == x) {
            printf("Element has been found in the hash table at location %d\n", index);
            return;
        }
    }
    printf("No such element in hash table!\n");
}

void display_seperate(struct node* arr[]) {
    printf("---Hash Table---\n");
    for (int i = 0; i < size; i++) {
        printf("At index %d: ", i);
        struct node* ptr = arr[i];
        while (ptr != NULL) {
            printf("%d -> ", ptr->info);
            ptr = ptr->next;
        }
        printf("NULL\n");
    }
    printf("----------------\n");
}

void display_open(int hashtable[]) {
    printf("---Hash Table---\n");
    for (int i = 0; i < size; i++) {
        if (hashtable[i]) {
            printf("At index %d: %d\n", i, hashtable[i]);
        } else {
            printf("At index %d: NULL\n", i);
        }
    }
    printf("----------------\n");
}

int main() {
    int choice, choice2;

    printf("Enter the type of hash mode to use: \n");
    printf("1. Separate Chaining \n");
    printf("2. Linear Probing \n");
    printf("3. Quadratic Probing \n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        struct node* hashtable[size] = { NULL };
        while (1) {
            printf("\n-----Menu-----\n");
            printf("1. Insert\n");
            printf("2. Search\n");
            printf("3. Display\n");
            printf("4. Exit\n");
            printf("Enter your choice: ");
            scanf("%d", &choice2);

            if (choice2 == 4) break;

            int n, x;
            switch (choice2) {
                case 1:
                    printf("Enter the number of elements to insert: ");
                    scanf("%d", &n);
                    printf("Enter the elements to insert: ");
                    for (int i = 0; i < n; i++) {
                        scanf("%d", &x);
                        insert_seperate_chaining(hashtable, x);
                    }
                    printf("All elements entered successfully!\n");
                    break;

                case 2:
                    printf("Enter the number to search: ");
                    scanf("%d", &x);
                    search_seperate(hashtable, x);
                    break;

                case 3:
                    display_seperate(hashtable);
                    break;

                default:
                    printf("Please enter a valid input!\n");
            }
        }
    } else if (choice == 2 || choice == 3) {
        int hashtable[size] = { 0 };
        while (1) {
            printf("\n-----Menu-----\n");
            printf("1. Insert\n");
            printf("2. Search\n");
            printf("3. Display\n");
            printf("4. Exit\n");
            printf("Enter your choice: ");
            scanf("%d", &choice2);

            if (choice2 == 4) break;

            int n, x;
            switch (choice2) {
                case 1:
                    printf("Enter the number of elements to insert: ");
                    scanf("%d", &n);
                    printf("Enter the elements to insert: ");
                    for (int i = 0; i < n; i++) {
                        scanf("%d", &x);
                        insert_open_Addressing(hashtable, x, choice);
                    }
                    printf("All elements entered successfully!\n");
                    break;

                case 2:
                    printf("Enter the number to search: ");
                    scanf("%d", &x);
                    search_open(hashtable, x, choice);
                    break;

                case 3:
                    display_open(hashtable);
                    break;

                default:
                    printf("Please enter a valid input!\n");
            }
        }
    } else {
        printf("Please enter a valid choice!\n");
    }

    return 0;
}
