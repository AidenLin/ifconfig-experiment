// Linux compile and run: gcc get_txqueuelen_ioctl.c -o get_txqueuelen_ioctl.out && ./get_txqueuelen_ioctl.out
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <netdb.h>
#include <linux/if.h>
#include <sys/ioctl.h>

int get_txqlen(int fd, const char *device)
{
    struct ifreq ifr;

    memset(&ifr, 0, sizeof(ifr));
    strncpy(ifr.ifr_name, device, sizeof(ifr.ifr_name));
    if (ioctl(fd, SIOCGIFTXQLEN, &ifr) == -1)
    {
        perror("Error opening:");
        exit(EXIT_FAILURE);
    }

    return ifr.ifr_qlen;
}

// Get txqueuelen value by Linux ioctl
int main(int argc, char *argv[])
{
    // change your interface name here
    const char *ifname = "eth1";

    int fd = socket(PF_INET, SOCK_DGRAM, IPPROTO_IP);
    int txqlen = get_txqlen(fd, ifname);
    printf("%s txqueuelen(SIOCGIFTXQLEN): %d\n", ifname, txqlen);
}