#include "../include/packetparser.h"

int main(int argc, char *argv[])
{
    PacketParser * packet_parser;

    if ( argc == 2 ) {
        packet_parser = new PacketParser(argv[1]);
    } else {
        packet_parser = new PacketParser();
    }
    
    packet_parser->Run();
    
    return 0;
}