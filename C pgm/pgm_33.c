#include <stdio.h>

// Structure definition first, typedef after
struct Date {
    int day;
    int month;
    int year;
};
typedef struct Date Date;

// Function to read a date
void readDate(Date *d) {
    printf("Enter date (dd mm yyyy): ");
    scanf("%d %d %d", &d->day, &d->month, &d->year);
}

// Function to display a date
void displayDate(Date d) {
    printf("Date: %02d/%02d/%04d\n", d.day, d.month, d.year);
}

// Function to compare two dates
int compareDate(Date d1, Date d2) {
    if (d1.day == d2.day && d1.month == d2.month && d1.year == d2.year)
        return 1;  // Equal
    else
        return 0;  // Not equal
}

// Main function
int main() {
    Date date1, date2;
    int choice;

    do {
        printf("1. Read first date\n");
        printf("2. Read second date\n");
        printf("3. Display both dates\n");
        printf("4. Compare dates\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter first date:\n");
                readDate(&date1);
                break;

            case 2:
                printf("Enter second date:\n");
                readDate(&date2);
                break;

            case 3:
                printf("\nFirst ");
                displayDate(date1);
                printf("Second ");
                displayDate(date2);
                break;

            case 4:
                if (compareDate(date1, date2))
                    printf("\nBoth dates are equal.\n");
                else
                    printf("\nDates are not equal.\n");
                break;

            case 5:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }

    } while (choice != 5);
    return 0;
}
