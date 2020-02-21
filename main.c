/*
 * Use of this source code is governed by an MIT-style
 * license that can be found in the LICENSE file or at
 * https://opensource.org/licenses/MIT.
 */

#include "main.h"

int main(int argc, char *argv[])
{
    /*
    FILE *f;
    CURL *c;

    f = fopen("foo.txt", "w");
    if (!f) return -1;

    c = curl_easy_init();
    if (!c) return -1;

    curl_easy_setopt(c, CURLOPT_URL, FEED);
    curl_easy_setopt(c, CURLOPT_WRITEDATA, f);
    CURLcode r = curl_easy_perform(c);
    if (r) return -1;

    curl_easy_cleanup(c);
    fclose(f);
    */

    if (setup_podw_dir() != 0) {
        fprintf(stderr, "Could not set up podwarrior directory");
    }

    init_db();

    if (argc < 2) {
        fprintf(stderr, "no command given\n");
        return EXIT_FAILURE;
    }

    if (!strcmp(argv[1], "import")) {
        if (argc < 3) {
            fprintf(stderr, "no OPML file specified\n");
        } else if (access(argv[2], F_OK) == -1) {
            fprintf(stderr, "file not found\n");
        } else {
            parse_opml(argv[2]);
        }
    }

    close_db();
    return EXIT_SUCCESS;
}

int setup_podw_dir(void)
{
    if (mkdir(PODW_HOME, 0755) < 0) {
        if (errno == EEXIST || errno == 0)
            return 0;
        else 
            return 1;
    } else {
        return 0;
    }
}
