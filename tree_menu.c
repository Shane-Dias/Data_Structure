/* Name: Shane Dias   Roll no:10179 */
#include <stdio.h>
#include <stdlib.h>

typedef struct BST
{
    int info;
    struct BST *left, *right;
} node;

node *getnode(int info)
{
    node *newnode = (node *)malloc(sizeof(node));
    if (newnode == NULL)
    {
        printf("Memory allocation failed");
        exit(0);
    }
    newnode->info = info;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

node *insert(node *root, int info)
{
    if (root == NULL)
    {
        return getnode(info);
    }
    if (info < root->info)
    {
        root->left = insert(root->left, info);
    }
    else
    {
        root->right = insert(root->right, info);
    }
    return root;
}

node *findMin(node *root)
{
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root;
}

node *deletenode(node *root, int info)
{
    if (root == NULL)
    {
        return root;
    }

    if (info < root->info)
    {
        root->left = deletenode(root->left, info);
    }
    else if (info > root->info)
    {
        root->right = deletenode(root->right, info);
    }
    else
    {
        if (root->left == NULL)
        {
            node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            node *temp = root->left;
            free(root);
            return temp;
        }

        node *temp = findMin(root->right);
        root->info = temp->info;
        root->right = deletenode(root->right, temp->info);
    }
    return root;
}

void inOrderTraversal(node *root)
{
    if (root == NULL)
        return;
    inOrderTraversal(root->left);
    printf("%d ", root->info);
    inOrderTraversal(root->right);
}

node *search(node *root, int info)
{
    if (root == NULL || root->info == info)
    {
        return root;
    }
    if (info < root->info)
    {
        return search(root->left, info);
    }
    else
    {
        return search(root->right, info);
    }
}

int countNodes(node *root)
{
    if (root == NULL)
        return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int countLeafNodes(node *root)
{
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return 1;
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

int countInteriorNodes(node *root)
{
    if (root == NULL || (root->left == NULL && root->right == NULL))
        return 0;
    return 1 + countInteriorNodes(root->left) + countInteriorNodes(root->right);
}

int main()
{
    node *root = NULL;
    int choice, value;

    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Insert a node\n");
        printf("2. Search for a node\n");
        printf("3. Display tree (In-order traversal)\n");
        printf("4. Delete a node\n");
        printf("5. Count total nodes\n");
        printf("6. Count leaf nodes\n");
        printf("7. Count interior nodes\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            root = insert(root, value);
            printf("Inserted %d into the BST.\n", value);
            break;
        case 2:
            printf("Enter value to search: ");
            scanf("%d", &value);
            node *searchResult = search(root, value);
            if (searchResult != NULL)
            {
                printf("Found %d in the BST.\n", value);
            }
            else
            {
                printf("%d not found in the BST.\n", value);
            }
            break;
        case 3:
            printf("In-order traversal:\n");
            inOrderTraversal(root);
            printf("\n");
            break;
        case 4:
            printf("Enter value to delete: ");
            scanf("%d", &value);
            root = deletenode(root, value);
            printf("Deleted %d from the BST.\n", value);
            break;
        case 5:
            printf("Total nodes: %d\n", countNodes(root));
            break;
        case 6:
            printf("Leaf nodes: %d\n", countLeafNodes(root));
            break;
        case 7:
            printf("Interior nodes: %d\n", countInteriorNodes(root));
            break;
        case 8:
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

/*
OUTPUT:
Menu:
1. Insert a node
2. Search for a node
3. Display tree (In-order traversal)
4. Delete a node
5. Count total nodes
6. Count leaf nodes
7. Count interior nodes
8. Exit
Enter your choice: 1
Enter value to insert: 10
Inserted 10 into the BST.

Menu:
1. Insert a node
2. Search for a node
3. Display tree (In-order traversal)
4. Delete a node
5. Count total nodes
6. Count leaf nodes
7. Count interior nodes
8. Exit
Enter your choice: 1
Enter value to insert: 7
Inserted 7 into the BST.

Menu:
1. Insert a node
2. Search for a node
3. Display tree (In-order traversal)
4. Delete a node
5. Count total nodes
6. Count leaf nodes
7. Count interior nodes
8. Exit
Enter your choice: 1
Enter value to insert: 4
Inserted 4 into the BST.

Menu:
1. Insert a node
2. Search for a node
3. Display tree (In-order traversal)
4. Delete a node
5. Count total nodes
6. Count leaf nodes
7. Count interior nodes
8. Exit
Enter your choice: 1
Enter value to insert: 9
Inserted 9 into the BST.

Menu:
1. Insert a node
2. Search for a node
3. Display tree (In-order traversal)
4. Delete a node
5. Count total nodes
6. Count leaf nodes
7. Count interior nodes
8. Exit
Enter your choice: 1
Enter value to insert: 14
Inserted 14 into the BST.

Menu:
1. Insert a node
2. Search for a node
3. Display tree (In-order traversal)
4. Delete a node
5. Count total nodes
6. Count leaf nodes
7. Count interior nodes
8. Exit
Enter your choice: 1
Enter value to insert: 11
Inserted 11 into the BST.

Menu:
1. Insert a node
2. Search for a node
3. Display tree (In-order traversal)
4. Delete a node
5. Count total nodes
6. Count leaf nodes
7. Count interior nodes
8. Exit
Enter your choice: 3
In-order traversal:
4 7 9 10 11 14

Menu:
1. Insert a node
2. Search for a node
3. Display tree (In-order traversal)
4. Delete a node
5. Count total nodes
6. Count leaf nodes
7. Count interior nodes
8. Exit
Enter your choice: 2
Enter value to search: 9
Found 9 in the BST.

Menu:
1. Insert a node
2. Search for a node
3. Display tree (In-order traversal)
4. Delete a node
5. Count total nodes
6. Count leaf nodes
7. Count interior nodes
8. Exit
Enter your choice: 4
Enter value to delete: 7
Deleted 7 from the BST.

Menu:
1. Insert a node
2. Search for a node
3. Display tree (In-order traversal)
4. Delete a node
5. Count total nodes
6. Count leaf nodes
7. Count interior nodes
8. Exit
Enter your choice: 4
Enter value to delete: 14
Deleted 14 from the BST.

Menu:
1. Insert a node
2. Search for a node
3. Display tree (In-order traversal)
4. Delete a node
5. Count total nodes
6. Count leaf nodes
7. Count interior nodes
8. Exit
Enter your choice: 3
In-order traversal:
4 9 10 11

Menu:
1. Insert a node
2. Search for a node
3. Display tree (In-order traversal)
4. Delete a node
5. Count total nodes
6. Count leaf nodes
7. Count interior nodes
8. Exit
Enter your choice: 5
Total nodes: 4

Menu:
1. Insert a node
2. Search for a node
3. Display tree (In-order traversal)
4. Delete a node
5. Count total nodes
6. Count leaf nodes
7. Count interior nodes
8. Exit
Enter your choice: 6
Leaf nodes: 2

Menu:
1. Insert a node
2. Search for a node
3. Display tree (In-order traversal)
4. Delete a node
5. Count total nodes
6. Count leaf nodes
7. Count interior nodes
8. Exit
Enter your choice: 7
Interior nodes: 2

Menu:
1. Insert a node
2. Search for a node
3. Display tree (In-order traversal)
4. Delete a node
5. Count total nodes
6. Count leaf nodes
7. Count interior nodes
8. Exit
Enter your choice: 8
Exiting...
*/