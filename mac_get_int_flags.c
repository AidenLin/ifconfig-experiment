// Mac compile and run: `gcc mac_get_int_flags.c -o mac_get_int_flags.out && ./mac_get_int_flags.out`

#include <string.h>
#include <ifaddrs.h>
#include <stdio.h>
#include <stdlib.h>
#include <err.h>

// Get flags of `en0` from Mac
int main(int argc, char *argv[])
{
    // change your interface name here
    const char *ifname = "en0";

    struct ifaddrs *ifa;
    if (getifaddrs(&ifa) != 0)
    {
        err(EXIT_FAILURE, "getifaddrs");
    }
    for (; ifa; ifa = ifa->ifa_next)
    {
        if (strcmp(ifname, ifa->ifa_name) != 0)
        {
            continue;
        }

        printf("NIC name         : %s\n", ifa->ifa_name);
        printf("flags as decimal : %d\n", ifa->ifa_flags);
        printf("flags as hex     : %X\n", ifa->ifa_flags);
        break;
    }
    return 0;
}