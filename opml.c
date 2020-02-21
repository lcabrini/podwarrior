/*
 * Use of this source code is governed by an MIT-style
 * license that can be found in the LICENSE file or at
 * https://opensource.org/licenses/MIT.
 */

#include "opml.h"

void parse_opml(char *fn)
{
    int i;

    const xmlChar *up = (xmlChar *)"//@xmlUrl";
    xmlDocPtr d = xmlParseFile(fn);
    xmlXPathContextPtr c = xmlXPathNewContext(d);
    xmlXPathObjectPtr u = xmlXPathEvalExpression(up, c);

    for (i = 0; i < u->nodesetval->nodeNr; ++i) {
        printf("%d. %s\n", i,
                xmlNodeGetContent(u->nodesetval->nodeTab[i]));
    }

    xmlXPathFreeObject(u);
    xmlXPathFreeContext(c);
    xmlFreeDoc(d);
}
