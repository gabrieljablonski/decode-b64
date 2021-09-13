#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "b64.h"

int main(int argc, char **argv) {
  if (argc != 3) {
    printf("Parâmetros:\n\n\t%s <caminho output> <string base64>\n\n", argv[0]);
    exit(-1);
  }
  char *path = argv[1];
  char *encoded = argv[2];
  size_t decsize;
  unsigned char *dec = b64_decode_ex(encoded, strlen(encoded), &decsize);
  FILE *fd = fopen(path, "wb");
  if (!fd) {
    printf("Escrita falhou.\n");
    exit(-1);
  }
  fwrite(dec, decsize, sizeof(unsigned char), fd);
  fclose(fd);
  char command[1024];
  sprintf(command, ".\\gzip.exe -d \"%s\" -f", path);
  system(command);
  return 0;
}
