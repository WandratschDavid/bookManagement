//*********************************************************************
//
//                H T L - W E L S   /   Klasse 3BHIT
//
//---------------------------------------------------------------------
// Programm         : Buchverwaltung
//
// Ersteller        : David Wandratsch
//
// Erstelldatum     : 2021-04-22
//
// Kurzbeschreibung : Verwaltung und Abfrage von Büchern
//
// GitHub Repository: https://github.com/WandratschDavid/bookManagement
//*********************************************************************

// Including (standard) libraries
#include <stdio.h>
#include <stdbool.h>

struct book{
    int book_num;
    char author[50];
    char title[50];
    int release_year;
    char publisher[50];
} book;

// defining the function header
int search(struct book* cat, int len, char* id);

// Main program
int main()
{
    int choice;
    bool run = true;
    int i = 0;
    int bookcount = 3;
    char search_term;

    struct book catalog[200] = {
            {1234567, "LUSTIG", "LACH-STORY", 1986, "TROCKEN"},
             {8745343, "KARL", "ABENTEUER", 1981, "VERITAS"},
             {7654321, "MUTIG", "KRIMI-ROMANZE", 1989, "SPANNEND"}
    };

    while(run)
    {
        // Display the different options to the user
        printf("1. Add book information\n");
        printf("2. Display all books\n");
        printf("3. List a book of a specific author\n");
        printf("4. List the amount of books in the system\n");
        printf("5. Exit\n");

        // Asking the user for a his choice
        printf ("Please choose one of the options above: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf ("\nBook number: ");
                scanf ("%i", catalog[i].book_num);

                printf ("\nAuthor name: ");
                scanf ("%s", catalog[i].author);

                printf ("\nBook title: ");
                scanf ("%s", catalog[i].title);

                printf ("\nRelease year: ");
                scanf ("%i", catalog[i].release_year);

                printf ("\nPublisher: ");
                scanf ("%s", catalog[i].publisher);

                bookcount++;
                break;

            case 2:
                for(i = 0; i < bookcount; i++)
                {
                    printf("Bookindex: %i\n", i);
                    printf("Booknumber: %d\n", catalog[i].book_num);
                    printf("Author: %s\n", catalog[i].author);
                    printf("Title: %s\n", catalog[i].title);
                    printf("Release year: %d\n", catalog[i].release_year);
                    printf("Publisher: %s\n\n", catalog[i].publisher);
                }
                break;

            case 3:
                printf ("Please enter the name of the author you are looking for: ");
                scanf ("%s", &search_term);

                int results = search(catalog, 200, &search_term);

                printf("\nSearch results: %i\n", results);
                break;

            case 4:
                printf("There are currently %d books in the library!\n", bookcount);
                break;

            case 5:
                run = false;
                printf("Thank you for using my program!\nGoodbye!");
                break;

            default:
                printf("Please make sure to enter a number from 1 - 5!\n");
                break;
        }
    }
    return 0;
}

//********************************************************************
// Funktion        : search
//
// Kurzbeschreibung: function to search a book from a specific author
//
// Beschreibung    : searching through the array for a book from the
//                   specific author
//--------------------------------------------------------------------
// Parameter       :
//    1   cat          struct book  defining the array to search in
//    2   len          int          specifying the length of the array
//    3   id           char         passing the search term along
//
//    R   i            int         returning the index of the book
//********************************************************************
int search(struct book* cat, int len, char* id)
{
    bool array_passed = false;
    int results = 0;

    while (!array_passed)
    {
        for (int i = 0; i < len; ++i)
        {
            if (id == cat[i].author)
            {
                printf("\nResult found!\n");
                printf("Booknumber: %d\n", cat[i].book_num);
                printf("Author: %s\n", cat[i].author);
                printf("Title: %s\n", cat[i].title);
                printf("Release year: %d\n", cat[i].release_year);
                printf("Publisher: %s\n", cat[i].publisher);

                results++;
            }
        }
        array_passed = true;
    }
    return results;
}