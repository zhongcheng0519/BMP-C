#include <stdio.h>
#include <stdlib.h>
#include "bmpfile.h"

#define NCLOLORS 256

int test_read_write(const char* in_fn, const char* out_fn)
{
    bmpfile_t* in_bmp;
    in_bmp = bmp_create_from_file(in_fn);
    if (in_bmp == NULL)
    {
        return -1;
    }
    
    bmp_save(in_bmp, out_fn);
}


int main(int argc, char* argv[])
{
    if (argc != 3)
    {
        printf("%s [input bmpname] [output bmpname]\n", argv[0]);
        return -1;
    }
    test_read_write(argv[1], argv[2]);
    
    return 0;
}

/*
int
main(int argc, char **argv)
{
  bmpfile_t *bmp;
  int i, j;
  rgb_pixel_t gray_map[NCLOLORS];

  if (argc < 5) {
    printf("Usage: %s filename width height depth.\n", argv[0]);
    return 1;
  }

  // Initilize gray_map
  for (i = 0; i < NCLOLORS; i++)
  {
      gray_map[i].red = i;
      gray_map[i].green = i;
      gray_map[i].blue = i;
      gray_map[i].alpha = 0;
  }
  

  if ((bmp = bmp_create(atoi(argv[2]), atoi(argv[3]), atoi(argv[4]))) == NULL) {
    printf("Invalid depth value: %s.\n", argv[4]);
    return 1;
  }

  for (i = 0, j = 0; i < atoi(argv[2]); ++i, ++j) {
    bmp_set_pixel(bmp, i, j, gray_map[i]);
  }

  bmp_save(bmp, argv[1]);
  bmp_destroy(&bmp);

  return 0;
}
*/
