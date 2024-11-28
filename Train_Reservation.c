#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Reservation
{
    char name[50];
    int seatNumber;
    struct Reservation *next;
} Reservation;

Reservation *createReservation(char name[], int seatNumber)
{
    Reservation *newReservation = (Reservation *)malloc(sizeof(Reservation));
    strcpy(newReservation->name, name);
    newReservation->seatNumber = seatNumber;
    newReservation->next = NULL;
    return newReservation;
}

void addReservation(Reservation **head, char name[], int seatNumber)
{
    Reservation *newReservation = createReservation(name, seatNumber);
    if (*head == NULL)
    {
        *head = newReservation;
    }
    else
    {
        Reservation *temp = *head;
        while (temp->next != NULL)
        {
            if (seatNumber == temp->seatNumber)
            {
                printf("Seat is already booked\n");
                free(newReservation);
                return;
            }
            temp = temp->next;
        }
        temp->next = newReservation;
    }
    printf("Reservation added for %s at seat %d.\n", name, seatNumber);
}

void cancelReservation(Reservation **head, int seatNumber)
{
    Reservation *temp = *head;
    Reservation *prev = NULL;

    if (temp != NULL && temp->seatNumber == seatNumber)
    {
        *head = temp->next;
        free(temp);
        printf("Reservation at seat %d has been cancelled.\n", seatNumber);
        return;
    }

    while (temp != NULL && temp->seatNumber != seatNumber)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("No reservation found for seat %d.\n", seatNumber);
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("Reservation at seat %d has been cancelled.\n", seatNumber);
}

void displayReservations(Reservation *head)
{
    if (head == NULL)
    {
        printf("No reservations made.\n");
        return;
    }
    Reservation *temp = head;
    printf("Reservations:\n");
    while (temp != NULL)
    {
        printf("Seat %d: %s\n", temp->seatNumber, temp->name);
        temp = temp->next;
    }
}

int main()
{
    Reservation *head = NULL;
    int choice, seatNumber;
    char name[50];

    while (1)
    {
        printf("\nTrain Reservation System\n");
        printf("1. Add Reservation\n");
        printf("2. Cancel Reservation\n");
        printf("3. Display All Reservations\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter passenger name: ");
            scanf("%s", name);
            printf("Enter seat number: ");
            scanf("%d", &seatNumber);
            addReservation(&head, name, seatNumber);
            break;

        case 2:
            printf("Enter seat number to cancel: ");
            scanf("%d", &seatNumber);
            cancelReservation(&head, seatNumber);
            break;

        case 3:
            displayReservations(head);
            break;

        case 4:
            printf("Exiting system...\n");
            exit(0);

        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}