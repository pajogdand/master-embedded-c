#include <stdio.h>
#include <errno.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#define SH_RESP_BUF_LEN 512
#define CMD_BUF_LEN     128

void log_mod_info(char * mod)
{
    char cmd[CMD_BUF_LEN] = "";
    snprintf(cmd, CMD_BUF_LEN, "modinfo %s 2>/dev/null", mod);

    FILE * fp = popen(cmd, "r");
    if (!fp)
    {
        printf("Failed to popen for command '%s', errno: %d", cmd, errno);
        return;
    }

    char resp[SH_RESP_BUF_LEN] = "";
    bool found = false;

    while (fgets(resp, SH_RESP_BUF_LEN, fp))
    {
        if (strstr(resp, "version:") && !strstr(resp, "srcversion:"))
        {
            printf("module name %s  and version %s", mod, resp);
            found = true;
            break;
        }
    }

    if (!found)
    {
        printf("Unable to log %s version info. Drivers from MBPL R17 or newer are required.", mod);
    }

    pclose(fp);
}

int main()
{    

    char *mod = "qcserial";
    log_mod_info(mod);

    
    exit(0);
}