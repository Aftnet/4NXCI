#include "libgen.h"

#include <stdlib.h>
#include <string.h>

char *basename(char *path)
{
    static char filename[_MAX_FNAME + _MAX_EXT];
    static char ext[_MAX_EXT];
    _splitpath_s(path, NULL, 0, NULL, 0, filename, _MAX_FNAME, ext, _MAX_EXT);
    return strcat(filename, ext);
}