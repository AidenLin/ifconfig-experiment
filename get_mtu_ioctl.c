// Linux compile and run: gcc get_mtu_ioctl.c -o get_mtu_ioctl.out && ./get_mtu_ioctl.out
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <netdb.h>
#include <linux/if.h>
#include <sys/ioctl.h>

int get_mtu(int fd, const char *device)
{
    struct ifreq ifr;

    memset(&ifr, 0, sizeof(ifr));
    strncpy(ifr.ifr_name, device, sizeof(ifr.ifr_name));
    if (ioctl(fd, SIOCGIFMTU, &ifr) == -1)
    {
        perror("Error opening:");
        exit(EXIT_FAILURE);
    }

    return ifr.ifr_mtu;
}

// Get MTU value by Linux ioctl
int main(int argc, char *argv[])
{
    // change your interface name here
    const char *ifname = "eth1";

    int fd = socket(PF_INET, SOCK_DGRAM, IPPROTO_IP);
    int mtu = get_mtu(fd, ifname);
    printf("%s mtu(SIOCGIFMTU): %d\n", ifname, mtu);
}