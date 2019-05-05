#include "../include/packetbase.h"

PacketBase::PacketBase(/* args */) {
}

PacketBase::~PacketBase() {
}

uint8_t PacketBase::GetHeader() const {
    return this->header_;
}

uint8_t PacketBase::GetLength() const {
    return this->length_;
}

uint8_t PacketBase::GetPayloadLength() const {
    return this->length_-3;
}


uint8_t PacketBase::GetChecksum() const {
    return this->checksum_;
}

std::vector<uint8_t> PacketBase::GetPayload() const {
    return this->payload_;
}

void PacketBase::SetHeader(uint8_t header) {
    this->header_ = header;
}

void PacketBase::SetLength(uint8_t length) {
    this->length_ = length;
}

void PacketBase::SetChecksum(uint8_t checksum) {
    this->checksum_ = checksum;
}

void PacketBase::SetPayload(std::vector<uint8_t> payload) {
    this->payload_ = payload;
}

void PacketBase::AddPayload(uint8_t payload) {
    this->payload_.push_back(payload);
}

void PacketBase::Clear() {
    this->header_ = 0;
    this->length_ = 0;
    this->payload_.clear();
    this->checksum_ = 0;
}
