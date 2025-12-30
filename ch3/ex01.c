#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int binsearch(int x, int v[], int n)
{
    int low, high, mid;

    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low + high) / 2;
        if (x < v[mid]) {
            high = mid - 1;
        } else if (x > v[mid]) {
            low = mid + 1;
        } else {
            return mid;
        }
    }
    return -1;
}

int binsearch_fast(int x, int v[], int n)
{
    int low, high, mid, diff;

    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low + high) / 2;
        if (x < v[mid]) {
            high = mid - 1;
        } else {
            low = mid + 1;
            diff = x - v[mid];
        }
    }
    return diff == 0 ? (low - 1) : -1;
}

int main(int argc, char *argv[])
{
    int size, *values, value, i;
    struct timespec before, after;

    size = atoi(argv[1]);
    values = malloc(sizeof(int) * size);
    srand(time(NULL));
    for (i = 0; i < size; i++) {
        values[i] = i + 1;
    }
    value = rand() % size + 1;

    clock_gettime(CLOCK_REALTIME, &before);
    i = binsearch(value, values, size);
    clock_gettime(CLOCK_REALTIME, &after);
    printf("original binsearch: %d at %d in %ldns\n",
           value, i, ((after.tv_nsec - before.tv_nsec) / 1));

    clock_gettime(CLOCK_REALTIME, &before);
    i = binsearch_fast(value, values, size);
    clock_gettime(CLOCK_REALTIME, &after);
    printf("improved binsearch: %d at %d in %ldns\n",
           value, i, ((after.tv_nsec - before.tv_nsec) / 1));

    return 0;
}
