#include "help.hpp"

#include <argp.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <cstdarg>

#include "config.h"

static bool use_color = false;

void init_color() { use_color = isatty(STDOUT_FILENO); }

void colored_error(struct argp_state* state, const char* fmt, ...) {
  fprintf(stderr, "%s%s%s: ", use_color ? BOLD : "", state->name, RESET);
  fprintf(stderr, "%serror:%s ", use_color ? R : "", RESET);

  va_list args;
  va_start(args, fmt);
  vfprintf(stderr, fmt, args);
  va_end(args);
  fprintf(stderr, "\n");

  argp_state_help(state, stderr, ARGP_HELP_STD_ERR);
  exit(EXIT_FAILURE);
}
void print_fish_completion() {
  for (int i = 0; options[i].name != NULL; i++) {
    printf("complete -c matter");
    if (options[i].name) printf(" -l %s", options[i].name);
    if (options[i].key && isprint(options[i].key)) {
      printf(" -s %c", options[i].key);
    }
    if (options[i].doc) printf(" -d '%s'", options[i].doc);
    if (options[i].key == 'l') printf(" -a '0 1 2 3 4'");

    printf("\n");
  }
}
void print_custom_help() {
  printf("\n%s%s v%s%s\n", BOLD, PROJECT_NAME, PROJECT_VERSION, RESET);
  printf("%s%s%s\n\n", G, PROJECT_DESCRIPTION, RESET);

  printf("%sUsage:%s\n  matter %s[OPTIONS]%s\n\n", BOLD, RESET, M, RESET);

  printf("%sOptions:%s\n", BOLD, RESET);
  for (int i = 0; options[i].name != NULL; i++) {
    printf("  -%s%c%s, --%s%s%s", C, options[i].key, RESET, C, options[i].name,
           RESET);

    if (options[i].arg) {
      printf("=%s%s%s", M, options[i].arg, RESET);
    }

    int len = 6 + strlen(options[i].name);
    if (options[i].arg) len += 1 + strlen(options[i].arg);
    for (int j = len; j < 25; j++) printf(" ");

    printf("%s%s%s\n", Y, options[i].doc, RESET);
  }
  printf("\n");
  printf("%sBug Reports:%s %s%s%s\n", BOLD, RESET, B, PROJECT_BUG_ADDRESS,
         RESET);
  printf("\n");
}
