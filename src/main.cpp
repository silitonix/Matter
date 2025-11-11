#include <argp.h>
#include <stdbool.h>
#include <stdlib.h>

#include "config.h"
#include "global.hpp"
#include "help.hpp"

const struct argp_option options[] = {
    {"verbose", 'v', NULL, 0, "Enable verbose output", 0},
    {"log-level", 'l', "[0..4]", 0, "Sets the log level for backend", 0},
    {"help", 'h', NULL, 0, "Give this help list", 0},
    {}};

const char* argp_program_version = PROJECT_NAME "v" PROJECT_VERSION;
const char* argp_program_bug_address = PROJECT_BUG_ADDRESS;
const char doc[] = PROJECT_DESCRIPTION;
const char args_doc[] = "";

Global g;

static error_t parse_opt(int key, char* arg, struct argp_state* state) {
  Global* g = (Global*)state->input;
  switch (key) {
    case 'v': g->opt.verbose = true; break;
    case 'l': {
      if (arg == NULL || arg[1] != '\0' || arg[0] < '0' || arg[0] > '4') {
        colored_error(state, "Log level '%s' invalid. Use [0-4].", arg);
      }
      g->opt.log_level[0] = arg[0];
      break;
    }
    case 'h':
      print_custom_help();
      exit(EXIT_SUCCESS);
      break;
    case ARGP_KEY_ARG: colored_error(state, "no input is allowed."); break;
    case ARGP_KEY_END: break;
    default: return ARGP_ERR_UNKNOWN;
  }
  return 0;
}

const struct argp argp = {options, parse_opt, args_doc, doc, NULL, NULL, NULL};

int main(int argc, char** argv) {
  init_color();

  int parse_result = argp_parse(&argp, argc, argv, ARGP_NO_HELP, 0, &g);
  if (parse_result != 0) {
    return parse_result;
  }

  return g.initialize();
}
