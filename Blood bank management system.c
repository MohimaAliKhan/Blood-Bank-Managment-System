#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct BloodGroup {
    char bloodType[10];
    int quantity;
};

void addBloodGroup(struct BloodGroup *bloodGroups, int *count)
{
    if (*count >= 10) {
        printf("Blood group list is full.\n");
        return;
    }
    char bloodType[10];
    int quantity;

    printf("\n\n\t\tEnter blood type: ");
    scanf("%s", bloodType);

    printf("\n\n\t\tEnter quantity: ");
    scanf("%d", &quantity);

    strcpy(bloodGroups[*count].bloodType, bloodType);
    bloodGroups[*count].quantity = quantity;
    *count+=quantity;
}
int searchBloodGroup(struct BloodGroup *bloodGroups, int count, const char *bloodType) {
    for (int i=0;i<count;i++) {
        if (strcmp(bloodGroups[i].bloodType, bloodType) == 0) {
            return i;
        }
    }
    return -1;
}

void deleteBloodGroup(struct BloodGroup *bloodGroups, int *count, const char *bloodType) {
    int index = searchBloodGroup(bloodGroups, *count, bloodType);

    if (index == -1) {
        printf("Blood group not found.\n");
        return;
    }

    for (int i = index; i < *count - 1; i++) {
        bloodGroups[i] = bloodGroups[i + 1];
    }
    (*count)--;
}

void displayBloodGroups(struct BloodGroup *bloodGroups, int count) {
    printf("Available blood groups:\n");
    for (int i = 0; i < count; i++) {
        printf("Blood Type: %s  quantity: %d\n", bloodGroups[i].bloodType,bloodGroups[i].quantity);
    }
}

void updateBloodQuantity(struct BloodGroup *bloodGroups, int count, const char *bloodType, int quantity) {
    int index = searchBloodGroup(bloodGroups, count, bloodType);

    if (index == -1) {
        printf("Blood group not found.\n");
        return;
    }

    bloodGroups[index].quantity = quantity;
}

void createBloodGroupPackage(struct BloodGroup *bloodGroups, int count, const char *packageDetails) {
    printf("Creating blood group package...\n");
    for (int i = 0; i < count; i++) {
        printf("Blood Type: %s, Quantity: %d\n", bloodGroups[i].bloodType, bloodGroups[i].quantity);
    }
    printf("Package details: %s\n", packageDetails);
}


int main() {
    struct BloodGroup bloodGroups[10];

    int count=8;
    int choice;
    char bloodType[10];
    int quantity;

    strcpy(bloodGroups[0].bloodType, "A+");bloodGroups[0].quantity = 5;
    strcpy(bloodGroups[1].bloodType, "B+");bloodGroups[1].quantity = 67;
    strcpy(bloodGroups[2].bloodType, "O+");bloodGroups[2].quantity = 56;
    strcpy(bloodGroups[3].bloodType, "AB+");bloodGroups[3].quantity = 38;
    strcpy(bloodGroups[4].bloodType, "A-");bloodGroups[4].quantity = 49;
    strcpy(bloodGroups[5].bloodType, "B-");bloodGroups[5].quantity = 67;
    strcpy(bloodGroups[6].bloodType, "O-");bloodGroups[6].quantity = 11;
    strcpy(bloodGroups[7].bloodType, "AB-");bloodGroups[7].quantity = 15;

    printf("\nBlood Bank Management System\n");
    printf("1. Add Blood Group\n");
    printf("2. Delete Blood Group\n");
    printf("3. Search Blood Group\n");
    printf("4. Display Blood Groups\n");
    printf("5. Update Blood Quantity\n");
    printf("6. Create Blood Group Package\n");
    printf("7. Exit\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            addBloodGroup(bloodGroups, &count);
            break;
        case 2:
            printf("Enter blood type to delete: ");
            scanf("%s", bloodType);
            deleteBloodGroup(bloodGroups, &count, bloodType);
            break;
        case 3:
            printf("\n\tEnter blood type to search: ");
            scanf("%s", bloodType);
            if (searchBloodGroup(bloodGroups, count, bloodType) != -1) {
                printf("Blood group found.\n");
            } else {
                printf("Blood group not found.\n");
            }
            break;
        case 4:
            displayBloodGroups(bloodGroups, count);
            break;
        case 5:
            printf("Enter blood type to update: ");
            scanf("%s", bloodType);
            printf("Enter new quantity: ");
            scanf("%d", &quantity);
            updateBloodQuantity(bloodGroups, count, bloodType, quantity);
            break;
        case 6:
            createBloodGroupPackage(bloodGroups, count, "PackageDetails");
            break;
        case 7:
            exit(0);
        default:
            printf("Invalid choice!\n");
    }


    return 0;
}
