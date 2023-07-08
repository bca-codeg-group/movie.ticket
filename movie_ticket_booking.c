#include <stdio.h>
#include <stdbool.h>

#define MAX_SEATS 50

typedef struct {
    int seatNumber;
    bool isBooked;
    char movieName[100];
    char customerName[100];
} Seat;

void initializeSeats(Seat seats[], int numSeats) {
    for (int i = 0; i < numSeats; i++) {
        seats[i].seatNumber = i + 1;
        seats[i].isBooked = false;
    }
}

void displaySeats(Seat seats[], int numSeats) {
    printf("Seats:\n");
    for (int i = 0; i < numSeats; i++) {
        printf("Seat %d: ", seats[i].seatNumber);
        if (seats[i].isBooked) {
            printf("Booked by %s for the movie '%s'\n", seats[i].customerName, seats[i].movieName);
        } else {
            printf("Available\n");
        }
    }
}

int findAvailableSeat(Seat seats[], int numSeats) {
    for (int i = 0; i < numSeats; i++) {
        if (!seats[i].isBooked) {
            return i;
        }
    }

    return -1; // No available seats
}

void bookSeat(Seat seats[], int numSeats) {
    int seatIndex = findAvailableSeat(seats, numSeats);
    if (seatIndex == -1) {
        printf("Sorry, no available seats.\n");
        return;
    }

    printf("Enter your name: ");
    scanf(" %[^\n]s", seats[seatIndex].customerName);

    printf("Enter the movie name: ");
    scanf(" %[^\n]s", seats[seatIndex].movieName);

    seats[seatIndex].isBooked = true;

    printf("Seat %d booked successfully.\n", seats[seatIndex].seatNumber);
}

void cancelSeat(Seat seats[], int numSeats) {
    int seatNumber;
    printf("Enter the seat number to cancel: ");
    scanf("%d", &seatNumber);

    if (seatNumber < 1 || seatNumber > numSeats) {
        printf("Invalid seat number.\n");
        return;
    }

    int seatIndex = seatNumber - 1;

    if (!seats[seatIndex].isBooked) {
        printf("Seat %d is not booked.\n", seatNumber);
        return;
    }

    seats[seatIndex].isBooked = false;
    printf("Seat %d booking canceled successfully.\n", seatNumber);
}

int main() {
    int numSeats;
    printf("Enter the number of seats: ");
    scanf("%d", &numSeats);

    if (numSeats > MAX_SEATS) {
        printf("Maximum number of seats exceeded.\n");
        return 0;
    }

    Seat seats[MAX_SEATS];
    initializeSeats(seats, numSeats);

    int choice;

    while (1) {
        printf("\nMovie Ticket Booking System\n");
        printf("---------------------------\n");
        printf("1. Display Available Seats\n");
        printf("2. Book a Seat\n");
        printf("3. Cancel Seat Booking\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displaySeats(seats, numSeats);
                break;
            case 2:
                bookSeat(seats, numSeats);
                break;
            case 3:
                cancelSeat(seats, numSeats);
                break;
            case 4:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
