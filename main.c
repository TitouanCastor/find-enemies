#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MIN_CHUNK -8
#define MAX_CHUNK 8

void download_image(int chunk_x, int chunk_y, char *folder)
{
    char string_url[100];
    char mv_file[30];

    memset(string_url, 0, 100);
    sprintf(string_url, "curl -o chunk%d_%d.png -O https://map.abovetheflood.fr/tiles/minecraft_overworld/3/%d_%d.png", chunk_x, chunk_y, chunk_x, chunk_y);
    system(string_url);
}

int main(void)
{
    char folder[25];
    char mkdir_folder[35];
    char mv_pngs[35];
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    sprintf(folder, "%02d:%02d:%02d", tm.tm_mday, tm.tm_mon, 1900 + tm.tm_year);
    sprintf(mkdir_folder, "mkdir %s", folder);
    system(mkdir_folder);
    for (int i = MIN_CHUNK; i < MAX_CHUNK; i++)
        for (int j = MIN_CHUNK; j < MAX_CHUNK; j++)
            download_image(i, j, folder);
    sprintf(mv_pngs, "mv *.png %s", folder);
    system(mv_pngs);
}
