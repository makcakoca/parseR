#include "../include/packetparser.h"

PacketParser::PacketParser() {
    reader_ = new TextReader();
    parser_ = new TextParser();
    reader_->Open();
}

PacketParser::PacketParser(std::string file_name) {
    reader_ = new TextReader(file_name);
    parser_ = new TextParser();
    reader_->Open();
}

PacketParser::~PacketParser() {
    reader_->Close();
}

void PacketParser::Run() {
    std::vector<uint8_t> raw_data;
    std::vector<PacketBase *> valid_packets;
    
    /// Read text file. Get converted string to hex number raw data.
    reader_->GetRawData(raw_data);

    /// Parse rawdata 
    parser_->ParseData(raw_data);

    /// Get valid parsed packets
    valid_packets = parser_->GetValidPackets();

    /// Print valid packets
    for ( int i = 0; i < valid_packets.size(); i++ ) {
        valid_packets[i]->Display();
    }
}
