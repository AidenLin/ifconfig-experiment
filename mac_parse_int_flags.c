// Mac compile and run：`gcc mac_parse_int_flags.c -o mac_parse_int_flags.out && ./mac_parse_int_flags.out`

#include <stdio.h>

// Print a value a la the %b format of the kernel's printf
// see: https://github.com/apple-opensource-mirror/network_cmds/blob/b4ac2ac03f0af8ed3bf575bae9ca9a8d9adecb11/ifconfig.tproj/ifconfig.c#L1808-L1837
void printb(const char *s, unsigned v, const char *bits)
{
    int i, any = 0;
    char c;

    if (bits && *bits == 8)
        printf("%s=%o", s, v);
    else
        printf("%s=%x", s, v);
    bits++;
    if (bits)
    {
        putchar('<');
        while ((i = *bits++) != '\0')
        {
            if (v & (1 << (i - 1)))
            {
                if (any)
                    putchar(',');
                any = 1;
                for (; (c = *bits) > 32; bits++)
                    putchar(c);
            }
            else
                for (; *bits > 32; bits++)
                    ;
        }
        putchar('>');
    }
}

// see: https://github.com/apple-opensource-mirror/network_cmds/blob/b4ac2ac03f0af8ed3bf575bae9ca9a8d9adecb11/ifconfig.tproj/ifconfig.c#L1205-L1208
#define IFFBITS                                                                 \
    "\020\1UP\2BROADCAST\3DEBUG\4LOOPBACK\5POINTOPOINT\6SMART\7RUNNING"         \
    "\10NOARP\11PROMISC\12ALLMULTI\13OACTIVE\14SIMPLEX\15LINK0\16LINK1\17LINK2" \
    "\20MULTICAST"

int main()
{
    // change value after `0x` by your ifconfig flags number, like `8963`
    unsigned a = 0x8863;
    printb("flags", a, IFFBITS);
    printf("\n");
    // all output: flags=8863<UP,BROADCAST,SMART,RUNNING,SIMPLEX,MULTICAST>
    return 0;
}
