#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#include <QMessageBox>

#include <windows.h>

#include "debug.h"

#define DEBUG_BUFFER_SIZE	1024

static int debug_level = 0;

int set_debug_level(int level)
{
    int ret = debug_level;

    debug_level = level;
    return ret;
}

int mod_debug_level(int mod_by)
{
    return set_debug_level(debug_level+mod_by);
}

int FORMAT_PRINTF UserPrintf(const char* fmt, ...)
{
    char *dbg;
    va_list ap;

    dbg = (char *)malloc(DEBUG_BUFFER_SIZE);
    if (!dbg)
        return 0;

    va_start(ap, fmt);
    size_t len = vsnprintf(dbg, DEBUG_BUFFER_SIZE, fmt, ap);
    va_end(ap);

    QMessageBox::information(NULL, "YACE", dbg);
    free(dbg);
    return (int)len;
}

int FORMAT_PRINTF DebugPrintf(const char* fmt, ...)
{
    if (debug_level <= 0)
        return 0;

    char *dbg;
    va_list ap;

    dbg = (char *)malloc(DEBUG_BUFFER_SIZE);
    if (!dbg)
        return 0;

    va_start(ap, fmt);
    size_t len = vsnprintf(dbg, DEBUG_BUFFER_SIZE, fmt, ap);
    va_end(ap);

    if (debug_level == 1)
    {
        printf("%s", dbg);
    }
    else
    {
        MessageBoxA(nullptr, dbg, "YACE", MB_ICONWARNING);
    }

    free(dbg);
    return (int)len;
}


