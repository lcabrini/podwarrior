/*
 * Use of this source code is governed by an MIT-style
 * license that can be found in the LICENSE file or at
 * https://opensource.org/licenses/MIT.
 */

#ifndef _PODW_MAIN
#define _PODW_MAIN

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include "config.h"

extern void parse_opml(char *);
extern int init_db(void);

int setup_podw_dir(void);

#endif /* PODW_MAIN */
