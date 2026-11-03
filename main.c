
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "parcels.dat"

struct Parcel {
    int id;
    char destination[50];
    float distance;
    int priority;
    int deadline;
};
int parcelIDExists(int id) {
    struct Parcel p;
    FILE *fp;

    fp = fopen(FILE_NAME, "rb");

    if (fp == NULL) {
        return 0;
    }

    while (fread(&p, sizeof(struct Parcel), 1, fp) == 1) {
        if (p.id == id) {
            fclose(fp);
            return 1;
        }
    }

    fclose(fp);
    return 0;
}
void addParcel() {
    struct Parcel p;
    FILE *fp;
    int ch;

    printf("\n========== ADD NEW PARCEL ==========\n");

    // Parcel ID validation
    printf("Enter Parcel ID: ");

    if (scanf("%d", &p.id) != 1) {
        printf("\nInvalid input! Enter a numeric Parcel ID.\n");

        while ((ch = getchar()) != '\n' && ch != EOF);
        return;
    }

    if (p.id <= 0) {
        printf("\nParcel ID must be positive!\n");
        return;
    }

    if (parcelIDExists(p.id)) {
        printf("\nParcel ID already exists!\n");
        return;
    }

    // Destination
    printf("Enter Destination: ");

    if (scanf(" %49[^\n]", p.destination) != 1) {
        printf("\nInvalid destination!\n");
        return;
    }

    // Distance validation
    printf("Enter Distance (in km): ");

    if (scanf("%f", &p.distance) != 1) {
        printf("\nInvalid input! Enter a number.\n");

        while ((ch = getchar()) != '\n' && ch != EOF);
        return;
    }

    if (p.distance <= 0) {
        printf("\nDistance must be positive!\n");
        return;
    }

    // Priority validation
    printf("\nSelect Priority:\n");
    printf("1. Normal\n");
    printf("2. Express\n");
    printf("3. Urgent\n");

    printf("Enter Priority: ");

    if (scanf("%d", &p.priority) != 1) {
        printf("\nInvalid input! Enter a number.\n");

        while ((ch = getchar()) != '\n' && ch != EOF);
        return;
    }

    if (p.priority < 1 || p.priority > 3) {
        printf("\nInvalid priority! Choose 1, 2 or 3.\n");
        return;
    }

    // Deadline validation
    printf("Enter Delivery Deadline (days): ");

    if (scanf("%d", &p.deadline) != 1) {
        printf("\nInvalid input! Enter a number.\n");

        while ((ch = getchar()) != '\n' && ch != EOF);
        return;
    }

    if (p.deadline <= 0) {
        printf("\nDeadline must be positive!\n");
        return;
    }

    // Save parcel
    fp = fopen(FILE_NAME, "ab");

    if (fp == NULL) {
        printf("\nError opening file!\n");
        return;
    }

    if (fwrite(&p, sizeof(struct Parcel), 1, fp) == 1) {
        printf("\nParcel added successfully!\n");
    }
    else {
        printf("\nError saving parcel!\n");
    }

    fclose(fp);
}
void viewParcels() {
    struct Parcel p;
    FILE *fp;

    fp = fopen(FILE_NAME, "rb");

    if (fp == NULL) {
        printf("\nNo parcel records found yet.\n");
        return;
    }

    printf("\n==================== ALL PARCELS ====================\n");

    printf("%-10s %-20s %-12s %-12s %-10s\n",
           "ID", "Destination", "Distance", "Priority", "Deadline");

    printf("-----------------------------------------------------\n");

    while (fread(&p, sizeof(struct Parcel), 1, fp) == 1) {

        char *priorityName;

        if (p.priority == 1)
            priorityName = "Normal";
        else if (p.priority == 2)
            priorityName = "Express";
        else if (p.priority == 3)
            priorityName = "Urgent";
        else
            priorityName = "Unknown";

        printf("%-10d %-20s %-12.2f %-12s %-10d\n",
               p.id, p.destination, p.distance,
               priorityName, p.deadline);
    }

    fclose(fp);
}
void sortParcels() {
    struct Parcel p[100];
    struct Parcel temp;
    FILE *fp;
    int count = 0;

    fp = fopen(FILE_NAME, "rb");

    if (fp == NULL) {
        printf("\nNo parcel records found!\n");
        return;
    }

    while (count < 100 &&
           fread(&p[count], sizeof(struct Parcel), 1, fp) == 1) {
        count++;
    }

    fclose(fp);

    if (count == 0) {
        printf("\nNo parcels available for sorting!\n");
        return;
    }

    // Bubble Sort: Highest priority first
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {

            if (p[j].priority < p[j + 1].priority) {
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }

    printf("\n========== PARCELS SORTED BY PRIORITY ==========\n");

    printf("%-10s %-20s %-12s %-12s %-10s\n",
           "ID", "Destination", "Distance", "Priority", "Deadline");

    printf("-----------------------------------------------------\n");

    for (int i = 0; i < count; i++) {

        char *priorityName;

        if (p[i].priority == 1)
            priorityName = "Normal";
        else if (p[i].priority == 2)
            priorityName = "Express";
        else if (p[i].priority == 3)
            priorityName = "Urgent";
        else
            priorityName = "Unknown";

        printf("%-10d %-20s %-12.2f %-12s %-10d\n",
               p[i].id, p[i].destination, p[i].distance,
               priorityName, p[i].deadline);
    }
}
void searchParcel() {
    struct Parcel p;
    FILE *fp;
    int searchID;
    int found = 0;

    fp = fopen(FILE_NAME, "rb");

    if (fp == NULL) {
        printf("\nNo parcel records found!\n");
        return;
    }

    printf("\n========== SEARCH PARCEL ==========\n");
    printf("Enter Parcel ID to search: ");
    scanf("%d", &searchID);

    while (fread(&p, sizeof(struct Parcel), 1, fp) == 1) {

        if (p.id == searchID) {
            char *priorityName;

            if (p.priority == 1)
                priorityName = "Normal";
            else if (p.priority == 2)
                priorityName = "Express";
            else if (p.priority == 3)
                priorityName = "Urgent";
            else
                priorityName = "Unknown";

            printf("\nParcel Found!\n");
            printf("-----------------------------------\n");
            printf("Parcel ID       : %d\n", p.id);
            printf("Destination     : %s\n", p.destination);
            printf("Distance        : %.2f km\n", p.distance);
            printf("Priority        : %s\n", priorityName);
            printf("Delivery Deadline: %d days\n", p.deadline);
            printf("-----------------------------------\n");

            found = 1;
            break;
        }
    }

    if (found == 0) {
        printf("\nParcel with ID %d not found!\n", searchID);
    }

    fclose(fp);
}
void dispatchSummary() {
    struct Parcel p;
    FILE *fp;

    int total = 0;
    int normal = 0;
    int express = 0;
    int urgent = 0;
    int deadlineCount = 0;

    float totalDistance = 0;

    // First pass: Calculate overall statistics
    fp = fopen(FILE_NAME, "rb");

    if (fp == NULL) {
        printf("\nNo parcel records found!\n");
        return;
    }

    while (fread(&p, sizeof(struct Parcel), 1, fp) == 1) {
        total++;
        totalDistance += p.distance;

        if (p.priority == 1)
            normal++;
        else if (p.priority == 2)
            express++;
        else if (p.priority == 3)
            urgent++;

        if (p.deadline <= 2)
            deadlineCount++;
    }

    fclose(fp);

    printf("\n========== DISPATCH SUMMARY ==========\n");

    printf("\nTotal Parcels           : %d\n", total);
    printf("Normal Parcels          : %d\n", normal);
    printf("Express Parcels         : %d\n", express);
    printf("Urgent Parcels          : %d\n", urgent);

    printf("\nTotal Delivery Distance : %.2f km\n", totalDistance);
    printf("Deadlines Within 2 Days : %d\n", deadlineCount);

    // Second pass: Display priority dispatch table
    fp = fopen(FILE_NAME, "rb");

    if (fp == NULL) {
        printf("\nUnable to read parcel records!\n");
        return;
    }

    printf("\n========== PRIORITY DISPATCH PLAN ==========\n");

    printf("%-10s %-15s %-12s %-12s %-12s %-22s\n",
           "ID", "Destination", "Distance", "Travel Hrs",
           "Deadline", "Dispatch Plan");

    printf("-------------------------------------------------------------------------------\n");

    while (fread(&p, sizeof(struct Parcel), 1, fp) == 1) {

        // Include Urgent parcels OR parcels with deadline <= 2 days
        if (p.priority == 3 || p.deadline <= 2) {

            float travelHours = p.distance / 60.0;

            // Assume maximum 8 driving hours per day
            int drivingDays = (int)(travelHours / 8.0);

            if (travelHours > drivingDays * 8.0)
                drivingDays++;

            if (travelHours > 0 && drivingDays == 0)
                drivingDays = 1;

            int dispatchDay = p.deadline - drivingDays + 1;

            char dispatchPlan[40];

            if (drivingDays > p.deadline) {
                strcpy(dispatchPlan, "Immediate - At Risk");
            }
            else if (dispatchDay <= 1) {
                strcpy(dispatchPlan, "Day 1 - Immediately");
            }
            else {
                snprintf(dispatchPlan, sizeof(dispatchPlan),
                         "By Day %d", dispatchDay);
            }

            printf("%-10d %-15s %-12.2f %-12.2f %-12d %-22s\n",
                   p.id, p.destination, p.distance,
                   travelHours, p.deadline, dispatchPlan);
        }
    }

    fclose(fp);

    printf("===============================================================================\n");
}
int main() {

    int choice;

    do {
        printf("\n====================================\n");
        printf("     SMART PARCEL PRIORITY SORTER\n");
        printf("====================================\n");

        printf("\n1. Add New Parcel");
        printf("\n2. View All Parcels");
        printf("\n3. Sort Parcels by Priority");
        printf("\n4. Search Parcel");
        printf("\n5. Dispatch Summary");
        printf("\n6. Exit");

        printf("\n\nEnter your choice: ");
        if (scanf("%d", &choice) != 1) {
    printf("\nInvalid input! Please enter a number.\n");

    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);

    if (ch == EOF) {
        break;
    }

    continue;
}

        switch (choice) {

            case 1:
    addParcel();
    break;

            case 2:
    viewParcels();
    break;

            case 3:
    sortParcels();
    break;

            case 4:
    searchParcel();
    break;

            case 5:
    dispatchSummary();
    break;

            case 6:
                printf("\nThank you for using Smart Parcel Priority Sorter!\n");
                break;

            default:
                printf("\nInvalid choice! Please enter 1 to 6.\n");
        }

    } while (choice != 6);

    return 0;
}
