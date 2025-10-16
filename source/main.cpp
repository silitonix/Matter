#include <argp.h>
#include <stdbool.h>

#include "config.h"
#include "global.h"

const char* argp_program_version = PROJECT_NAME " v" PROJECT_VERSION;
const char* argp_program_bug_address = PROJECT_BUG_ADDRESS;
const char doc[] = PROJECT_DESCRIPTION;
const char args_doc[] = "[INPUT_FILE]";

const struct argp_option options[] = {
    {"verbose", 'v', NULL, 0, "Enable verbose output", 0}, {}};

Global global;

static error_t parse_opt(int key, char* arg, struct argp_state* state) {
  (void)arg;
  Global* g = (Global*)state->input;
  switch (key) {
    case 'v': g->conf.verbose = true; break;
    case ARGP_KEY_ARG: argp_error(state, "no input is allowed."); break;
    case ARGP_KEY_END: g->setup(); break;
    default: return ARGP_ERR_UNKNOWN;
  }
  return 0;
}

const struct argp argp = {options, parse_opt, args_doc, doc, NULL, NULL, NULL};

int main(int argc, char** argv) {
  return argp_parse(&argp, argc, argv, 0, 0, &global);
}
