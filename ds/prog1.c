#include <stdio.h>
#include <stdlib.h>

struct Day {
    char *dayName;
    int date;
    char *activity;
};

void create(struct Day *day) {
    day->dayName = (char *)malloc(20 * sizeof(char));
    day->activity = (char *)malloc(100 * sizeof(char));

    printf("Enter the day name: ");
    scanf("%s", day->dayName);

    printf("Enter the date: ");
    scanf("%d", &day->date);

    printf("Enter the activity for the day: ");
    scanf(" %[^\n]", day->activity);
}

void read(struct Day *calendar, int size) {
    for (int i = 0; i < size; i++) {
        printf("\nEnter details for Day %d:\n", i + 1);
        create(&calendar[i]);
    }
}

void display(struct Day *calendar, int size) {
    printf("\nWEEK's Activity Details:\n");

    for (int i = 0; i < size; i++) {
        printf("\nDay %d:\n", i + 1);
        printf("Day Name: %s\n", calendar[i].dayName);
        printf("Date: %d\n", calendar[i].date);
        printf("Activity: %s\n", calendar[i].activity);
    }
}

int main() {
    int size = 7;   // one week
    struct Day calendar[7];

    read(calendar, size);
    display(calendar, size);

    return 0;
}
