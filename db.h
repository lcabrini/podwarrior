/*
 * Use of this source code is governed by an MIT-style
 * license that can be found in the LICENSE file or at
 * https://opensource.org/licenses/MIT.
 */

#ifndef _PODW_DB
#define _PODW_DB

#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <sqlite3.h>
#include "config.h"

char CREATEDB_SQL[] =
    "create table feeds(id int primary key, name text, url text);";

int init_db(void);

#endif
