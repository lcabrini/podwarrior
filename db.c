/*
 * Use of this source code is governed by an MIT-style
 * license that can be found in the LICENSE file or at
 * https://opensource.org/licenses/MIT.
 */

#include "db.h"

int init_db(void)
{
    char *em = NULL;

    if (access(PODW_DB_FILE, R_OK) == -1) {
        if (sqlite3_open(PODW_DB_FILE, &db) != SQLITE_OK) {
            fprintf(stderr, "could not open database: %s\n", 
                    sqlite3_errmsg(db));
            sqlite3_close(db);
            return 1;
        }

        if (sqlite3_exec(db, CREATEDB_SQL, 0, 0, &em) != SQLITE_OK) {
            fprintf(stderr, "SQL Error: %s\n", em);
            sqlite3_free(em);
            return 1;
        }
    }

    return 0;
}

void close_db(void)
{
    sqlite3_close(db);
}

int add_feed(char *name, char *url)
{
    char *em = NULL;
    char sql[512];

    snprintf(sql, 200, "insert into feeds(name, url) values('%s', '%s')",
            name, url);

    if (sqlite3_exec(db, sql, 0, 0, &em) != SQLITE_OK) {
        fprintf(stderr, "SQL Error: %s\n", em);
        sqlite3_free(em);
        return 1;
    }

    return 0;
}

