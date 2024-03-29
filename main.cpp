#include <iostream>
#include <pcap.h>
#include <libnet.h>
#include <netinet/in.h>
#include "PacketParser.h"
#include "Packet.h"
#include "PacketStatic.h"
using namespace std;

int main(int argc, char* argv[])
{
    char *dev = argv[1];    // interface name
    PacketParser p(dev);
    PacketStatic *ps = new PacketStatic();
    while(true){
        int res = p.getRes();
        if (res == 0)
            continue;
        if (res == -1 || res == -2) {
            cout << "pcap_next_ex return " << res << endl;
            break;
        }

        Packet *ptr = new Packet();
        if(p.run(ptr) == true){
            ptr->printinfo(ps);
        }
    }
}
