#include <stdio.h>
#include <stdint.h>
#include <stdarg.h>
#include <stdint.h>

typedef void (*LOG_FUNC)(__uint8_t lvl, const char *fmt, ...);

void log_func(__uint8_t lvl, const char *fmt, ...)
{
    va_list args;
    va_start(args, fmt);

    printf("[%d]: ", lvl);
    vprintf(fmt, args);
    printf("\n");

    va_end(args);
}

void foo(LOG_FUNC logger)
{
    logger(1, "Inside foo()\n");
}

int main()
{
    foo(log_func);
    return 0;
}
