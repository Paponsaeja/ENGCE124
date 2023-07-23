#include <stdio.h>
#include <stdlib.h>

#define HeadData -999 // Special Data of Head Node

struct Node {
    int info;
    struct Node* link;
};

struct Node* H, * H1, * p, * q;

struct Node* allocate(void) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    return temp;
}

void createNNode(int n) {
    int i, temp;
    H = allocate(); // Create HEAD Node
    H->info = HeadData;
    H->link = H; // Link back to Node
    H1 = H;
    for (i = 1; i <= n; i++) {
        p = allocate(); // Allocate Node
        temp = 1 + rand() % 99; // Random difference number 1..99
        p->info = temp; // Put random data into node
        H1->link = p; // Let last node point to new node
        H1 = p; // Let H1 point to new node
        H1->link = H; // Set link of H1 to HEAD for Circular Linked List
    }
}

void showAllNode(void) {
    printf("H = %p\n", H); // Display address of pointer H
    p = H->link; // Set start point of p pointer at first node
    int i = 1; // Set start value of counter
    while (p->info != HeadData) {
        printf("%d) : %p\t", i, p); // Show COUNTER and POINTER
        printf("INFO : %d\t", p->info); // Show INFO
        printf("LINK : %p\n", p->link); // Show LINK
        p = p->link; // Skip to the next node
        i++; // Increment counter
    }
}

void insertAfter(int data1) {
    int temp;
    if (H->link == H) {
        printf("Circular Linked List has no node!!..\n");
    } else {
        H1 = H->link;
        while (H1->info != HeadData) {
            if (H1->info == data1) {
                p = allocate(); // Allocate one node from storage pool
                printf("\nInsert data: "); // Input data for insert
                scanf("%d", &temp); // Read from keyboard
                p->info = temp; // Entry temporary data into INFO of node
                p->link = H1->link; // Change pointer 1st for insert node far
                H1->link = p; // Change pointer 2nd for insert node (NEAR)
            }
            H1 = H1->link; // Skip H1 to the next node
        }
    }
}

void deleteAfter(int data1) {
    if (H->link == H) {
        printf("Circular Linked List has no node!!..\n");
    } else {
        H1 = H->link;
        while (H1->info != HeadData) {
            if (H1->info == data1) {
                if (H1->link == H) {
                    printf("This is the HEAD Node, Can't delete it!!!\n");
                } else {
                    p = H1->link; // Mark at node for Delete
                    if (p->link == H) { // If p is the last node
                        H1->link = H; // Set link of H1 to the Head node
                    } else {
                        H1->link = p->link; // If not set link of H1 point
                    }
                    free(p); // Free node to storage pool
                }
            }
            H1 = H1->link; // Skip H1 to the next node
        }
    }
}

int main(void) {
    int n = 10; // Set the number of nodes
    createNNode(n);
    printf("PROGRAM SINGLY CIRCULAR LINKED LIST\n");
    printf("========================================\n");
    printf("All Data in Linked List\n");
    showAllNode();
    char ch = ' ';
    while (ch != 'E') {
        printf("MENU: [I: Insert D: Delete E: Exit]\n");
        ch = getchar();
        switch (ch) {
            case 'I':
                printf("\nInsert After data: ");
                int data;
                scanf("%d", &data);
                insertAfter(data);
                printf("\nAll Data in Linked List AFTER INSERTED\n");
                showAllNode();
                break;
            case 'D':
                printf("\nDelete After data: ");
                scanf("%d", &data);
                deleteAfter(data);
                printf("\nAll Data in Linked List AFTER DELETED\n");
                showAllNode();
                break;
        }
        while (getchar() != '\n') {} // Clear the input buffer
    }
    return 0;
}
