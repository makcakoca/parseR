#include "../include/textpacket.h"

TextPacket::TextPacket() {
    printer = new ConsoleWriter();
}

TextPacket::~TextPacket() {
}

void TextPacket::Display() {
    std::stringstream ss;

    ss << printer->ConvertHex2Print(this->GetHeader()) << " ";
    ss << printer->ConvertHex2Print(this->GetLength()) << " ";

    for ( int i = 0; i < this->GetPayloadLength(); i++ ) {
        ss << printer->ConvertHex2Print(this->GetPayload()[i]) << " ";
    }
    ss << printer->ConvertHex2Print(this->GetChecksum()) << std::endl;

    printer->Write(ss.str());
}
