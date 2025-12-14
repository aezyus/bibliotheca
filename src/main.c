#include <stdio.h>
#include <stdlib.h>
#include "version.h"
#include "args.h"

int main(int argc, char *argv[]){
  
  ProgramAction action = parse_arguments(argc, argv);

  switch(action){
    case ACTION_VERSION:
      printf("%s %s\n", argv[0], BIBTEC_VERSION);
      return EXIT_SUCCESS;
    case ACTION_HELP:
      printf("usage: %s [-v|--version] [-h|--help]\n", argv[0]);
      return EXIT_SUCCESS;
    case ACTION_ERROR:
      fprintf(stderr, "Invalid arguments\n");
      return EXIT_FAILURE;
    case ACTION_NONE:
    default:
      fprintf(stderr, "usage: %s --help\n", argv[0]);
      return EXIT_FAILURE;
  }
} 
