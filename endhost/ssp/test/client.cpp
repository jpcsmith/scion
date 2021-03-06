#include <arpa/inet.h>
#include <unistd.h>

#include "SCIONSocket.h"

#define BUFSIZE 1024

int main(int argc, char **argv)
{
    uint16_t src_isd, dst_isd;
    uint32_t src_as, dst_as;
    char str[40];
    if (argc >= 2) {
        src_isd = atoi(strtok(argv[1], "-"));
        src_as = atoi(strtok(NULL, "-"));
    } else {
        src_isd = 1;
        src_as = 19;
    }
    if (argc == 3) {
        dst_isd = atoi(strtok(argv[2], "-"));
        dst_as = atoi(strtok(NULL, "-"));
    } else {
        dst_isd = 2;
        dst_as = 26;
    }

    sprintf(str, "/run/shm/sciond/%d-%d.sock", src_isd, src_as);
    SCIONSocket s(L4_SSP, str);

    SCIONAddr saddr;
    memset(&saddr, 0, sizeof(saddr));
    saddr.isd_as = ISD_AS(dst_isd, dst_as);
    saddr.host.addr_len = 4;
    saddr.host.port = 8080;
    sprintf(str, "127.%d.%d.254", dst_isd, dst_as);
    in_addr_t in = inet_addr(str);
    memcpy(saddr.host.addr, &in, 4);

    //s.bind(saddr);
    s.connect(saddr);
    printf("connected to (%d, %d):%s\n", dst_isd, dst_as, str);

    /*
    SCIONOption option;
    memset(&option, 0, sizeof(option));
    option.type = SCION_OPTION_ISD_WLIST;
    option.val = 0;
    option.len = 4;
    *(uint16_t *)(option.data) = 1;
    *(uint16_t *)(option.data + 2) = 3;
    s.setSocketOption(&option);
    */

    int count = 0;
    char buf[BUFSIZE];
    memset(buf, 0, BUFSIZE);
    while (1) {
        count++;
        sprintf(buf, "This is message %d\n", count);
        s.send((uint8_t *)buf, BUFSIZE);
        //s.send((uint8_t *)buf, BUFSIZE, &saddr);
        //usleep(500000);
    }
    exit(0);
}
