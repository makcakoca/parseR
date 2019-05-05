#include "../include/parserbase.h"

ParserBase::ParserBase() {
}

ParserBase::~ParserBase() {
}

std::vector<PacketBase *> ParserBase::GetValidPackets() const {
    return valid_packets;
}
