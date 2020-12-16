#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "read.h"

int main(int argc, char const *argv[])
{
	FILE* file;
	file = fopen(argv[1], "r+");

	int size = getFileLines(argv[1]);
	movieData *movies = malloc(sizeof(movieData)*size);


	movies = readTsv(file, size);


#ifdef PAR
#pragma omp parallel for 
#endif 
	for (int i = 0; i < size-1; ++i)
	{	
	   if ( (strcmp(movies[i].type, MOVIE) != 0) || (strcmp(movies[i].genres[0], "\\N") == 0) )
	   {
	   		movies[i].year = 0;
	   }
	}

	// #pragma omp single
	qsort(movies, size, sizeof(movieData), compare); // Fica mais lento paralelo 

#ifdef PAR
#pragma omp parallel for collapse(2) 
#endif 
	for (int i = 0; i < YEARS; ++i)
	{
		for (int j = 0; j < TOTAL_GENRES; ++j)
		{
			matrix[i][j] = 0;
		}
	}

	countGenres(movies, size);

#ifdef PAR
#pragma omp barrier
#endif
	FILE *fp = fopen("saida.csv", "w");
	fprintf(fp, ",%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s\n", DRAMA_GENRE, COMEDY_GENRE, SHORT_GENRE, 
	ROMANCE_GENRE, DOCUMENTARY_GENRE, FAMILY_GENRE, ANIMATION_GENRE, MUSIC_GENRE, CRIME_GENRE, ACTION_GENRE, ADVENTURE_GENRE,
	GAME_SHOW_GENRE, THRILLER_GENRE, FANTASY_GENRE, ADULT_GENRE, MYSTERY_GENRE, SCI_FI_GENRE, SPORT_GENRE,
	HORROR_GENRE, HISTORY_GENRE, BIOGRAPHY_GENRE, MUSICAL_GENRE, WAR_GENRE, WESTERN_GENRE, FILM_NOIR_GENRE);

	for (int i = 0; i < YEARS; ++i)
	{
		fprintf(fp, "%d,", i + INITIAL_YEAR + 1);
		for (int j = 0; j < TOTAL_GENRES; ++j)
			fprintf(fp, "%d,", matrix[i][j]);
		fprintf(fp, "\n");
	}
	fclose(fp);



// #pragma omp barrier
// 	for (int i = 0; i < size-1; ++i)
// 	{	
// 	   printf("%d ", movies[i].year);
// 	   for (int j = 0; j < MAX_GENRES; ++j)
// 	   {
// 	   		printf("%s ", movies[i].genres[j]);
// 	   }
// 	   printf("\n");
// 	}
// 	return 0;
}