#include <stdio.h>
#include <string.h>

struct StudentsRecord {
    int id;
    char name[50];
    char branch[10];
};

int binarySearch(struct StudentsRecord s[], int x, int low, int high) {

    if (high >= low) {

        int mid = low + (high - low) / 2;

        if (s[mid].id == x)
            return mid;

        if (x > s[mid].id)
            return binarySearch(s, x, mid + 1, high);
        else
            return binarySearch(s, x, low, mid - 1);
    }

    return -1;
}

int main() {

    int n, i, x;

    printf("Enter number of students: ");
    scanf("%d", &n);

    struct StudentsRecord s[n];

    printf("\nEnter student records (ID Name Branch):\n");

    for (i = 0; i < n; i++) {
        printf("Student %d:\n", i + 1);
        scanf("%d %s %s", &s[i].id, s[i].name, s[i].branch);
    }

    printf("\nEnter Student ID to search: ");
    scanf("%d", &x);

    int result = binarySearch(s, x, 0, n - 1);

    if (result == -1) {
        printf("\nStudent ID %d - Student Detail Not Found.\n", x);
    } 
    else {
        printf("\nStudent Found:\n");
        printf("Student ID : %d\n", s[result].id);
        printf("Name       : %s\n", s[result].name);
        printf("Branch     : %s\n", s[result].branch);
    }

    return 0;
}