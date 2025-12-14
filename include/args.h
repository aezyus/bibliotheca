/**
 *  @file args.h
 *  @brief  Command-line argument parsing for bibtec.
 *  This module is responsible for:
 *  - Parsing CLI flags
 *  - Mapping user intent to ProgramAction
 *  It does NOT:
 *  - Perform side effects
 */

#ifndef ARGS_H
#define ARGS_H

/**
 *  @enum ProgramAction
 *  @brief  High-level user intent parsed from CLI args.
 *  This enum represents *what* the user wants.
 *  It is decoupled from *how* the program executes it
 */

typedef enum {
  ACTION_NONE = 0,
  ACTION_VERSION,
  ACTION_HELP,
  ACTION_ERROR
} ProgramAction;


/**
 *  @brief  Parse command-line arguments
 *  
 *  @param argc Argument count from main()
 *  @param argv Argument vector from main()
 *
 *  @return A ProgramAction indicating user intent.
 *
 *  @note This function performs no I/O.
 */
ProgramAction parse_arguments(int argc, char *argv[]);

#endif
