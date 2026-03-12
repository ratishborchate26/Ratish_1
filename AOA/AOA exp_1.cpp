#include <stdio.h>
#include <string.h>

struct Book {
    int id;
    char BookName[30];
    char author[30];
    float price;
};

int main() {

    struct Book b[10];
    int n, i, j;

    printf("Enter number of books: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("\nEnter details of Book %d\n", i + 1);

        printf("Enter Book ID: ");
        scanf("%d", &b[i].id);

        printf("Enter Book Name: ");
        scanf("%s", b[i].BookName);

        printf("Enter Author Name: ");
        scanf("%s", b[i].author);

        printf("Enter Price: ");
        scanf("%f", &b[i].price);
    }

    for(j = 1; j < n; j++) {
        struct Book key = b[j];
        int k = j - 1;

        while(k >= 0 && b[k].id > key.id) {
            b[k + 1] = b[k];
            k = k - 1;
        }

        b[k + 1] = key;
    }

    printf("\nSorted Book Details:\n");
    printf("BookID\tBookName\tAuthor\t\tPrice\n");

    for(i = 0; i < n; i++) {
        printf("%d\t%s\t\t%s\t\t%.2f\n",
               b[i].id,
               b[i].BookName,
               b[i].author,
               b[i].price);
    }

    return 0;
}