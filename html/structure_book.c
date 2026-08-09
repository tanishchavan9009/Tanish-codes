#include <stdio.h>
#include <string.h>

struct book {
    char title[30];
    char author[30];
    char genre[20];
    int year;
};

int main() {
    struct book b[20], temp;
    int n, i, j, choice;

    printf("Enter number of books: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("\nEnter details of book %d\n", i + 1);
        printf("Title: ");
        scanf("%s", b[i].title);
        printf("Author: ");
        scanf("%s", b[i].author);
        printf("Genre: ");
        scanf("%s", b[i].genre);
        printf("Release Year: ");
        scanf("%d", &b[i].year);
    }

    printf("\nSort Books By:\n");
    printf("1. Title\n2. Author\n3. Genre\n4. Release Year\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    // Exchange Sort
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if ((choice == 1 && strcmp(b[i].title, b[j].title) > 0) ||
                (choice == 2 && strcmp(b[i].author, b[j].author) > 0) ||
                (choice == 3 && strcmp(b[i].genre, b[j].genre) > 0) ||
                (choice == 4 && b[i].year > b[j].year)) {

                temp = b[i];
                b[i] = b[j];
                b[j] = temp;
            }
        }
    }

    printf("\nSorted Book List:\n");
    printf("Title\tAuthor\tGenre\tYear\n");
    for (i = 0; i < n; i++) {
        printf("%s\t%s\t%s\t%d\n",
               b[i].title, b[i].author, b[i].genre, b[i].year);
    }

    return 0;
}