#include "db.h"

int init_db(void)
{
    sqlite3 *db;
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
            sqlite3_close(db);
            return 1;
        }
    }

    sqlite3_close(db);
    return 0;
}
