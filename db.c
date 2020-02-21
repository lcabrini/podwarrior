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
    } else {
        if (sqlite3_open(PODW_DB_FILE, &db) != SQLITE_OK) {
            fprintf(stderr, "could not open database: %s\n", 
                    sqlite3_errmsg(db));
            sqlite3_close(db);
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
    sqlite3_stmt *stmt;
    char sql[] = "insert into feeds(name, url) values(?1, ?2);";

    sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
    sqlite3_bind_text(stmt, 1, name, -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, url, -1, SQLITE_STATIC);

    if (sqlite3_step(stmt) != SQLITE_DONE) {
        fprintf(stderr, "Error inserting data: %s\n", sqlite3_errmsg(db));
    }

    sqlite3_finalize(stmt);
    return 0;

    /*    
    fprintf(stderr, "SQL: %s\n", sql); 



    if (sqlite3_exec(db, sql, 0, 0, &em) != SQLITE_OK) {
        fprintf(stderr, "SQL Error: %s\n", em);
        sqlite3_free(em);
        return 1;
    }
    */

    return 0;
}

