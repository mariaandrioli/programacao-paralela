#ifndef __READ_H__
#define __READ_H__

#define SIZE_TYPE 13
#define MAX_GENRES 3
#define SIZE_GENRES 12
#define TOTAL_GENRES 25
#define CATEGORIES 9

#define MOVIE "movie"

#define DRAMA_INDEX 0
#define COMEDY_INDEX 1
#define SHORT_INDEX 2
#define ROMANCE_INDEX 3
#define DOCUMENTARY_INDEX 4
#define FAMILY_INDEX 5
#define ANIMATION_INDEX 6
#define MUSIC_INDEX 7
#define CRIME_INDEX 8
#define ACTION_INDEX 9
#define ADVENTURE_INDEX 10
#define GAME_SHOW_INDEX 11
#define THRILLER_INDEX 12
#define FANTASY_INDEX 13
#define ADULT_INDEX 14
#define MYSTERY_INDEX 15
#define SCI_FI_INDEX 16
#define SPORT_INDEX 17
#define HORROR_INDEX 18
#define HISTORY_INDEX 19
#define BIOGRAPHY_INDEX 20
#define MUSICAL_INDEX 21
#define WAR_INDEX 22
#define WESTERN_INDEX 23
#define FILM_NOIR_INDEX 24

#define DRAMA_GENRE "Drama"
#define COMEDY_GENRE "Comedy"
#define SHORT_GENRE "Short"
#define ROMANCE_GENRE "Romance"
#define DOCUMENTARY_GENRE "Documentary"
#define FAMILY_GENRE "Family"
#define ANIMATION_GENRE "Animation"
#define MUSIC_GENRE "Music"
#define CRIME_GENRE "Crime"
#define ACTION_GENRE "Action"
#define ADVENTURE_GENRE "Adventure"
#define GAME_SHOW_GENRE "Game show"
#define THRILLER_GENRE "Thriller"
#define FANTASY_GENRE "Fantasy"
#define ADULT_GENRE "Adult"
#define MYSTERY_GENRE "Mystery"
#define SCI_FI_GENRE "Sci fi"
#define SPORT_GENRE "Sport"
#define HORROR_GENRE "Horror"
#define HISTORY_GENRE "History"
#define BIOGRAPHY_GENRE "Biography"
#define MUSICAL_GENRE "Musical"
#define WAR_GENRE "War"
#define WESTERN_GENRE "Western"
#define FILM_NOIR_GENRE "Film noir"

#define FINAL_YEAR 2020
#define INITIAL_YEAR 1920
#define YEARS 100

typedef struct {
  char type[SIZE_TYPE];
  int year;
  char genres[MAX_GENRES][SIZE_GENRES];
} movieData;

int matrix[YEARS][TOTAL_GENRES];

const char* getField(char* line, movieData *movie);

movieData * readTsv(FILE* file, int size);
int getFileLines(char const *arg);
int compare (const void *a, const void *b);
void countGenres(movieData *movies, int size);

#endif