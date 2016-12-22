//
// Created by jm on 12/16/16.
//

#include <common.h>

static char * evalstr(char *s)
{
    /* if the parameter starts with a * then assume a string pointer else its a literal */
//    if (s[0] == '*') {
//        return (char *)simple_strtoul(&s[1], NULL, 16);
//    } else
    if (s[0] == '$') {
        int i = 2;

        if (s[1] != '{')
            return NULL;

        while (s[i] != '}') {
            if (s[i] == 0)
                return NULL;
            i++;
        }
        s[i] = 0;
        return  getenv((const char *)&s[2]);
    } else {
        return s;
    }
}

static int do_strstr(cmd_tbl_t *cmdtp, int flag, int argc, char * const argv[])
{
    ulong hs_start, hs_len, hs_end;
    int found_loc = -1;
    char * patt;
    ulong curr;
    ulong pattlen;

    /*
     * We take 5 arguments:
     * 5 : strstr hs_start hs_len string found_loc
     */

    /* > 5 already tested by max command args */
    if (argc < 5)
        return CMD_RET_USAGE;

    hs_start = simple_strtoul(argv[1], NULL, 16);
    hs_len = simple_strtoul(argv[2], NULL, 16);
    hs_end = hs_start + hs_len;

    patt = evalstr(argv[3]);

    printf("start %lx, len %lx, end %lx, patt %s\n", hs_start, hs_len, hs_end, patt);

    if (patt == NULL)
    {
        printf("Invalid string pattern\n");
        return 1;
    }

    pattlen = strlen(patt);

    for (curr = hs_start; curr < hs_end; curr++)
    {
        found_loc = memcmp((const void*)curr, patt, pattlen);
        if (found_loc == 0)
            break;
    }

    if (found_loc == 0)
    {
        curr += strlen(patt);
        setenv_hex(argv[4], curr);
        return 0;
    } else {
        setenv_hex(argv[4], 0);
        return 1;
    }
}

U_BOOT_CMD(
        strstr, 5, 0, do_strstr,
"perform strstr search",
"hs_start hs_len needlestr found_loc\n"
"  hs_start is memory address\n"
"  hs_len is length of buffer to search\n"
"  needlestr can be string or address of null-term string\n"
"  found_loc is env variable to be set with address of byte\n"
"    immediately after found string\n"
);
