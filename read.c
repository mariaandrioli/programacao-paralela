#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <omp.h>

#include "read.h"

const char* getField(char* line, movieData *movie)
{
    char *tok, *tmp;
    int i = 0; 

    for (tok = strtok(line, "\t"); tok && *tok; tok = strtok(NULL, "\t\n"), ++i)
    {
    	switch(i)
    	{
    		case 1:
    			strcpy(movie->type, tok);
		    	break;

		    case 5:
		    	movie->year = atoi(tok);
		    	break;

		    case 8:
		    	tmp = malloc(SIZE_GENRES*sizeof(char));
			    tmp = strtok(tok, ",");
			    for (int j = 0; j < MAX_GENRES && tmp && *tmp; ++j)
			    {
			    	strncpy(movie->genres[j], tmp, SIZE_GENRES);
			    	tmp = strtok(NULL, ",\n");
			    }
			    free(tmp);
		    	break;

		    default:
		    	break;
    	}
    }

    return NULL;
}

movieData *readTsv(FILE* file, int size){
	char line[1024];
	int i = 0;
	movieData *movies;

	movies = malloc(sizeof(movieData)*size);
	while (fgets(line, 1024, file))
	{
		char tmp[1024];
		strcpy(tmp, line);
		getField(tmp, &movies[i]);

		i++;
	}

	return movies;
}

int getFileLines(char const *arg) {
	FILE *fp;
	char path[1035];
	int size;

	char command[256] = "wc -l ";

	fp = popen(strcat(command, arg), "r");

	if (fp == NULL) {
		printf("Failed to run command\n" );
		exit(1);
	}

	if (fgets(path, sizeof(path), fp) != NULL) {
		size = atoi(strtok(path, " "));
	}

	pclose(fp);

	return size;
}

int compare (const void *a, const void *b){
  movieData *movieA = (movieData *)a;
  movieData *movieB = (movieData *)b;

  return (movieB->year - movieA->year);
}

void countGenres(movieData *movies, int size) {
#ifdef PAR
#pragma omp parallel for
#endif 
	for (int i = 0; i < size-1; ++i)
	{
		if (movies[i].year > INITIAL_YEAR && movies[i].year <= FINAL_YEAR)
		{
			int index = (movies[i].year - INITIAL_YEAR) - 1;
			for (int j = 0; j < MAX_GENRES; ++j)
			{
				if (strcmp(movies[i].genres[j], DRAMA_GENRE) == 0)
					matrix[index][DRAMA_INDEX]++;

				else if (strcmp(movies[i].genres[j], COMEDY_GENRE) == 0)
					matrix[index][COMEDY_INDEX]++;

				else if (strcmp(movies[i].genres[j], SHORT_GENRE) == 0)
					matrix[index][SHORT_INDEX]++;

				else if (strcmp(movies[i].genres[j], ROMANCE_GENRE) == 0)
					matrix[index][ROMANCE_INDEX]++;

				else if (strcmp(movies[i].genres[j], DOCUMENTARY_GENRE) == 0)
					matrix[index][DOCUMENTARY_INDEX]++;

				else if (strcmp(movies[i].genres[j], FAMILY_GENRE) == 0)
					matrix[index][FAMILY_INDEX]++;

				else if (strcmp(movies[i].genres[j], ANIMATION_GENRE) == 0)
					matrix[index][ANIMATION_INDEX]++;

				else if (strcmp(movies[i].genres[j], MUSIC_GENRE) == 0)
					matrix[index][MUSIC_INDEX]++;

				else if (strcmp(movies[i].genres[j], CRIME_GENRE) == 0)
					matrix[index][CRIME_INDEX]++;

				else if (strcmp(movies[i].genres[j], ACTION_GENRE) == 0)
					matrix[index][ACTION_INDEX]++;

				else if (strcmp(movies[i].genres[j], ADVENTURE_GENRE) == 0)
					matrix[index][ADVENTURE_INDEX]++;

				else if (strcmp(movies[i].genres[j], GAME_SHOW_GENRE) == 0)
					matrix[index][GAME_SHOW_INDEX]++;
					
				else if (strcmp(movies[i].genres[j], THRILLER_GENRE) == 0)
					matrix[index][THRILLER_INDEX]++;
					
				else if (strcmp(movies[i].genres[j], FANTASY_GENRE) == 0)
					matrix[index][FANTASY_INDEX]++;

				else if (strcmp(movies[i].genres[j], ADULT_GENRE) == 0)
					matrix[index][ADULT_INDEX]++;

				else if (strcmp(movies[i].genres[j], MYSTERY_GENRE) == 0)
					matrix[index][MYSTERY_INDEX]++;

				else if (strcmp(movies[i].genres[j], SCI_FI_GENRE) == 0)
					matrix[index][SCI_FI_INDEX]++;

				else if (strcmp(movies[i].genres[j], SPORT_GENRE) == 0)
					matrix[index][SPORT_INDEX]++;

				else if (strcmp(movies[i].genres[j], HORROR_GENRE) == 0)
					matrix[index][HORROR_INDEX]++;
					
				else if (strcmp(movies[i].genres[j], HISTORY_GENRE) == 0)
					matrix[index][HISTORY_INDEX]++;

				else if (strcmp(movies[i].genres[j], BIOGRAPHY_GENRE) == 0)
					matrix[index][BIOGRAPHY_INDEX]++;

				else if (strcmp(movies[i].genres[j], MUSICAL_GENRE) == 0)
					matrix[index][MUSICAL_INDEX]++;

				else if (strcmp(movies[i].genres[j], WAR_GENRE) == 0)
					matrix[index][WAR_INDEX]++;
					
				else if (strcmp(movies[i].genres[j], WESTERN_GENRE) == 0)
					matrix[index][WESTERN_INDEX]++;

				else if (strcmp(movies[i].genres[j], FILM_NOIR_GENRE) == 0)
					matrix[index][FILM_NOIR_INDEX]++;
				
			}
		}
	}
}