#ifndef PODW_MAIN
#define PODW_MAIN

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include "config.h"

extern void parse_opml(char *);

int setup_podw_dir(void);

#endif /* PODW_MAIN */
