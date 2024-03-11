#include <stdio.h>
#include <string.h>

#define MAX_MOVIES 100

struct Movie {
    int id;
    char name[100];
    char release_date[20];
};

struct Movie movies[MAX_MOVIES];
int num_movies = 0;

void addMovie() {
    if (num_movies < MAX_MOVIES) {
        struct Movie new_movie;
        printf("Enter Movie ID: ");
        scanf("%d", &new_movie.id);
        printf("Enter Movie Name: ");
        scanf("%s", new_movie.name);
        printf("Enter Release Date (YYYY-MM-DD): ");
        scanf("%s", new_movie.release_date);
        
        movies[num_movies++] = new_movie;
        printf("Movie added successfully.\n");
    } else {
        printf("Maximum number of movies reached.\n");
    }
}

void displayAllMovies() {
    printf("All Movies:\n");
    int i;
    for ( i = 0; i < num_movies; ++i) {
        printf("ID: %d, Name: %s, Release Date: %s\n", movies[i].id, movies[i].name, movies[i].release_date);
    }
}

void editMovie(int id) {
	int i;
    for ( i = 0; i < num_movies; ++i) {
        if (movies[i].id == id) {
            printf("Enter new Movie Name: ");
            scanf("%s", movies[i].name);
            printf("Enter new Release Date (YYYY-MM-DD): ");
            scanf("%s", movies[i].release_date);
            printf("Movie edited successfully.\n");
            return;
        }
    }
    printf("Movie with ID %d not found.\n", id);
}

void deleteMovie(int id) {
	int i;
    for ( i = 0; i < num_movies; ++i) {
        if (movies[i].id == id) {
        	int j;
            for ( j = i; j < num_movies - 1; ++j) {
                movies[j] = movies[j + 1];
            }
            --num_movies;
            printf("Movie deleted successfully.\n");
            return;
        }
    }
    printf("Movie with ID %d not found.\n", id);
}

void searchMovieByName(const char *name) {
    printf("Movies with name \"%s\":\n", name);
    int found = 0;
    int i;
    for ( i = 0; i < num_movies; ++i) {
        if (strcmp(movies[i].name, name) == 0) {
            printf("ID: %d, Name: %s, Release Date: %s\n", movies[i].id, movies[i].name, movies[i].release_date);
            found = 1;
        }
    }
    if (!found) {
        printf("No movie found with name \"%s\".\n", name);
    }
}

void searchMovieByReleaseDate(const char *release_date) {
    printf("Movies released on \"%s\":\n", release_date);
    int found = 0;
    int i;
    for ( i = 0; i < num_movies; ++i) {
        if (strcmp(movies[i].release_date, release_date) == 0) {
            printf("ID: %d, Name: %s, Release Date: %s\n", movies[i].id, movies[i].name, movies[i].release_date);
            found = 1;
        }
    }
    if (!found) {
        printf("No movie found released on \"%s\".\n", release_date);
    }
}

int main() {
    int choice;
    do {
        printf("\nMovie Management System Menu:\n");
        printf("1. Add New Movie Record\n");
        printf("2. Display All Movie Records\n");
        printf("3. Edit Movie Record by Movie ID\n");
        printf("4. Delete Movie from List by Movie ID\n");
        printf("5. Search Movie by Name\n");
        printf("6. Search Movie by Release Date\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addMovie();
                break;
            case 2:
                displayAllMovies();
                break;
            case 3: {
                int id;
                printf("Enter Movie ID to edit: ");
                scanf("%d", &id);
                editMovie(id);
                break;
            }
            case 4: {
                int id;
                printf("Enter Movie ID to delete: ");
                scanf("%d", &id);
                deleteMovie(id);
                break;
            }
            case 5: {
                char name[100];
                printf("Enter Movie Name to search: ");
                scanf("%s", name);
                searchMovieByName(name);
                break;
            }
            case 6: {
                char release_date[20];
                printf("Enter Release Date (YYYY-MM-DD) to search: ");
                scanf("%s", release_date);
                searchMovieByReleaseDate(release_date);
                break;
            }
            case 7:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(choice != 7);

    return 0;
}

