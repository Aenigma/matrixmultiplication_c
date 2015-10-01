#include <stdio.h>
#include <stdlib.h>
#include "matrixgen.h"

#define DEFAULT_BUF_SIZE 512


static void show_arr(long int *arr, int size);
static void arr_join(long int *arr, int size, const char* prefix, const char* delimiter, const char* suffix);
static void fill_from(long int *arr, long int **arr_list, int d1, int d2);
static void show_arr(long int *arr, int size);

static void fill_from(long int *arr, long int **arr_list, int d1, int d2)
{
#ifdef DEBUG
	printf("fill_from called\n");
#endif
	/* index for original array */
	int arr_index = 0;
	/* index for the split arrays */
	int i = 0;

	for (i = 0; i < d1; i++) {
		/* index for elements in the split arrays */
		int j;
		for (j = 0; j < d2; j++) {
#ifdef DEBUG
			printf("fillfrom %d -> (%d, %d)\n", arr_index, i, j);
#endif
			arr_list[i][j] = arr[arr_index++];
		}
	}
}

static void show_arr(long int *arr, int size)
{
	int i;
	for (i = 0; i < size; i++) {
		printf("%ld\n", arr[i]);
	}
}

static void arr_join(long int *arr, int size, const char* prefix, const char* delimiter, const char* suffix)
{
	printf("%s", prefix);
	if(size >= 1) {
		int i;
		for (i = 0; i < size-1; i++) {
			printf("%ld%s", arr[i], delimiter);
		}
		printf("%ld", arr[i]);
	}
	printf("%s", suffix);
}

void arr_rect_join(long int **arr, int d1, int d2, const char* prefix, const char* delimiter, const char* suffix)
{
	printf("%s", prefix);
	if(d1 >= 1) {
		int i;
		for (i = 0; i < d1-1; i++) {
			arr_join(arr[i], d2, "[", delimiter, "]");
			puts(delimiter);
		}
		arr_join(arr[i], d2, "[", delimiter, "]");
	}

	printf("%s", suffix);
}

static void allocate_ptrptr(long int **arr_list, int d1, int d2)
{
#ifdef DEBUG
	printf("DEBUG: allocate_ptrptr called\n");
#endif
	int i = d1;
	while(i--) {
		arr_list[i] = (long int *) malloc(d2 * sizeof(long int));
		if(arr_list[i] == NULL) {
			fputs("Error mallocing! Exiting...", stderr);
			exit(-1);
		}
	}

#ifdef DEBUG
	i = d1;
	while(i--) {
		int j = d2;
		printf("DEBUG: zeroing and displaying allocated arr: \n");
		while(j--) arr_list[i][j] = 0;
		show_arr(arr_list[i], d2);
	}
#endif
}


/**
 * 
 */
int readldfile(FILE *fin, long int **buffer_ptr, int *size_ptr)
{
	/* number of elements in buffer */
	int size = *size_ptr;
	long int *buffer = *buffer_ptr;
	int count = 0;

	while(fscanf(fin, "%ld", &buffer[count++]) != EOF) {
#ifdef DEBUG
		printf("(%d, %d): %ld\n", count, size, buffer[0]);
#endif
		if(count == size) {
			long int *newbuffer;
			size *= 2;
			newbuffer = (long int *) realloc(buffer, size*sizeof(long int));

			if (newbuffer == NULL) {
				fputs("Error reallocating buffer", stderr);
				free(buffer);
				exit(-1);
			}

			buffer = newbuffer;
		}
	}

	count--;

	*buffer_ptr = buffer;
	*size_ptr = size;

	return count;
}

int split_arr(long int *arr, int count, int quotient, long int ***split_arr_list_ptr)
{

	long int **split_arr_list;
	/* the number of elements in the split array */
	int split_arr_count = count/quotient;

	if(count % quotient != 0) {
		fprintf(stderr,
			"count (%d) is not divisible by quotient (%d)",
			count, quotient);
		return -1;
	}

	/* we will now allocate this data here */
	split_arr_list = (long int **) malloc(quotient * sizeof(long int **));

	/* now we need to malloc each array with count/quotient elements */
	allocate_ptrptr(split_arr_list, quotient, split_arr_count);

	fill_from(arr, split_arr_list, quotient, split_arr_count);

	*split_arr_list_ptr = split_arr_list;

	return 0;
}

int read_2_matrices(FILE *fin, long int ****mat)
{
	/** size of buffer in # of elements */
	int size = DEFAULT_BUF_SIZE;
	/** buffer, contains 1D array for all elements */
	long int * buffer = (long int *) malloc(size * sizeof(long int));

	long int **tmp_mats = NULL;
	long int ***mats = NULL;

	int count = readldfile(fin, &buffer, &size);

	if (count%10 != 0) {
		fputs("# elements in file not divisible by 10; exiting...", stderr);
		exit(-1);
	}

	split_arr(buffer, count, 2, &tmp_mats);

	mats = (long int ***) malloc(2 * sizeof(long int **));

	// split subarray with count/2 elements into 5
	split_arr(tmp_mats[0], count/2, 5, &mats[0]);
	split_arr(tmp_mats[1], count/2, count/10, &mats[1]);

	*mat = mats;

	return count;
}

