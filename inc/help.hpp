
#ifndef _HELP
#define _HELP
#define RESET "\x1b[0m"
#define BOLD "\x1b[1m"

// Normal Colors
#define K "\x1b[30m"  // Black
#define R "\x1b[31m"  // Red
#define G "\x1b[32m"  // Green
#define Y "\x1b[33m"  // Yellow
#define B "\x1b[34m"  // Blue
#define M "\x1b[35m"  // Magenta
#define C "\x1b[36m"  // Cyan
#define W "\x1b[37m"  // White

// Bright Colors
#define BK "\x1b[90m"  // Bright Black (Gray)
#define BR "\x1b[91m"  // Bright Red
#define BG "\x1b[92m"  // Bright Green
#define BY "\x1b[93m"  // Bright Yellow
#define BB "\x1b[94m"  // Bright Blue
#define BM "\x1b[95m"  // Bright Magenta
#define BC "\x1b[96m"  // Bright Cyan
#define BW "\x1b[97m"  // Bright White

extern const struct argp_option options[];

void init_color();
void print_custom_help();
void colored_error(struct argp_state* state, const char* fmt, ...);
#endif
