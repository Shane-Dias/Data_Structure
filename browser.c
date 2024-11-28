#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char page[100];
    struct Node* prev;
    struct Node* next;
};

struct BrowserHistory {
    struct Node* head;
    struct Node* current;
};

// Initialize the browser history
void initBrowserHistory(struct BrowserHistory* browser) {
    browser->head = NULL;
    browser->current = NULL;
}

// Visit a new page
void visit(struct BrowserHistory* browser, const char* page) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    strcpy(new_node->page, page);
    new_node->prev = browser->current;
    new_node->next = NULL;

    if (browser->current) {
        browser->current->next = new_node;
    }
    browser->current = new_node;
    browser->head = new_node;
}

// Go back to the previous page
void back(struct BrowserHistory* browser) {
    if (browser->current && browser->current->prev) {
        browser->current = browser->current->prev;
    } else {
        printf("No previous page to go back to.\n");
    }
}

// Go forward to the next page
void forward(struct BrowserHistory* browser) {
    if (browser->current && browser->current->next) {
        browser->current = browser->current->next;
    } else {
        printf("No forward page to go to.\n");
    }
}

// Get the current page
void getCurrentPage(struct BrowserHistory* browser) {
    if (browser->current) {
        printf("Current page: %s\n", browser->current->page);
    } else {
        printf("No current page.\n");
    }
}

// Free memory
void freeBrowserHistory(struct BrowserHistory* browser) {
    struct Node* temp = browser->head;
    while (temp) {
        struct Node* next = temp->next;
        free(temp);
        temp = next;
    }
}

int main() {
    struct BrowserHistory browser;
    initBrowserHistory(&browser);

    int choice;
    char page[100];

    do {
        printf("\n1. Visit page\n2. Back\n3. Forward\n4. Get current page\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter page to visit: ");
                scanf("%s", page);
                visit(&browser, page);
                break;
            case 2:
                back(&browser);
                break;
            case 3:
                forward(&browser);
                break;
            case 4:
                getCurrentPage(&browser);
                break;
            case 5:
                printf("Exiting browser...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 5);

    freeBrowserHistory(&browser);
    return 0;
}