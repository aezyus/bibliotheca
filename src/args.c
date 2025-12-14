#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
#include "args.h"

ProgramAction parse_arguments(int argc, char *argv[]){
  
  int opt;
  static struct option long_options[] = {
    {"version", no_argument, 0, 'v'},
    {"help", no_argument, 0, 'h'},
    {0, 0, 0, 0}
  };

  while((opt = getopt_long(argc, argv, "vh", long_options, NULL)) != -1){
    switch(opt){
      case 'v':
        return ACTION_VERSION;
      case 'h':
        return ACTION_HELP;
      case '?':
      default:
        return ACTION_ERROR;
    }
  }

  return ACTION_NONE;
}
