#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MIN_CHUNK -10
#define MAX_CHUNK 10

void download_image(int chunk_x, int chunk_y, char *folder)
{
    char string_url[100];
    char mv_file[30];

    memset(string_url, 0, 100);
    sprintf(string_url, "curl -o chunk%d_%d.png -O https://map.abovetheflood.fr/tiles/minecraft_overworld/3/%d_%d.png", chunk_x, chunk_y, chunk_x, chunk_y);
    system(string_url);
}

int compare_image(int chunk_x, int chunk_y, char *date_1, char *date_2)
{
    char compare[120];

    sprintf(compare, "compare %s/chunk%d_%d.png %s/chunk%d_%d.png chunk%d_%d", date_1, chunk_x, chunk_y, date_2, chunk_x, chunk_y, chunk_x, chunk_y);
    system(compare);
}

int compare(char **argv)
{
    char folder[20];
    char mkdir_folder[40];
    char mv_file[50];

    sprintf(folder, "%s-%s", argv[1], argv[2]);
    sprintf(mkdir_folder, "mkdir %s", folder);
    system(mkdir_folder);
    for (int i = MIN_CHUNK; i < MAX_CHUNK; i++)
        for (int j = MIN_CHUNK; j < MAX_CHUNK; j++)
            compare_image(i, j, argv[1], argv[2]);
    sprintf(mv_file, "mv chunk* %s/", folder);
    system(mv_file);
    return 0;
}

int main(int argc, char **argv)
{
    char folder[25];
    char mkdir_folder[35];
    char mv_pngs[35];
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    char mv_folder[80];

    if (argc == 3)
        return compare(argv);
    sprintf(folder, "%02d:%02d:%02d", tm.tm_mday, tm.tm_mon, 1900 + tm.tm_year);
    sprintf(mkdir_folder, "mkdir %s", folder);
    system(mkdir_folder);
    for (int i = MIN_CHUNK; i < MAX_CHUNK; i++)
        for (int j = MIN_CHUNK; j < MAX_CHUNK; j++)
            download_image(i, j, folder);
    sprintf(mv_pngs, "mv *.png %s", folder);
    system(mv_pngs);
    sprintf(mv_folder, "mv %s ~/delivery/tek1/hub/compare_maps/find-enemies/", folder); // <-- path to the repository
    system(mv_folder);
    return 0;
}
