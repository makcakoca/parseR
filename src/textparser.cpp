#include "../include/textparser.h"

TextParser::TextParser() : parser_state_(PARSING_HEADER), header_index_(0) {
}

TextParser::~TextParser() {
}

void TextParser::ParseData(std::vector<uint8_t> data) {

    for ( size_t i = 0; i < data.size(); ++i ) {
        switch ( parser_state_ ) {
            /// Parsing Header.
            case PARSING_HEADER:
                /// Check if data is header
                if ( data[i] != HEADER ) {
                    parser_state_ = PARSING_HEADER;;
                    continue;
                }
                /* 
                 * if header is found, point header index
                 */
                header_index_ = i;
                single_packet = new TextPacket();
                single_packet->Clear();
                single_packet->SetHeader(data[i]);
                parser_state_ = PARSING_LENGTH;
                break;

            /// Parsing Length.
            case PARSING_LENGTH:
                single_packet->SetLength(data[i]);
                parser_state_ = PARSING_PAYLOAD;
                break;

            /// Parsing Payload
            case PARSING_PAYLOAD:
                if ( single_packet->GetPayload().size() ==
                 single_packet->GetPayloadLength() ) {
                    parser_state_ = PARSING_CHECKSUM;
                } else {
                    single_packet->AddPayload(data[i]);
                    break;
                }

            /// Parsing Checksum.
            case PARSING_CHECKSUM:
                single_packet->SetChecksum(data[i]);
                parser_state_ = PARSING_HEADER;
                /// Check if packet is valid or not using checksum.
                if ( CheckData() ) {
                    valid_packets.push_back(single_packet);
                } else {
                    /*
                     * if packet is not valid, all data will be not thrown.
                     * We just get rid of first byte,
                     * since the header we called may be payload data.
                     */
                    i = header_index_ + 1;
                }
                break;
        }
    }
}

bool TextParser::CheckData() {
    uint8_t calculatedChecksum = 0;

    /*
     * Calculating Checksum
     *  checksum = mod(header+length+payload, 256)
     */
    calculatedChecksum = single_packet->GetHeader() + single_packet->GetLength();

    for ( int i = 0; i < single_packet->GetPayloadLength(); i++ ) {
        calculatedChecksum += single_packet->GetPayload()[i];
    }

    calculatedChecksum %= 256;

    return (calculatedChecksum == single_packet->GetChecksum());
}
