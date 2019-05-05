/**
* @file         textpacket.h
* @brief        TextPacket class
* @author       Mehmet Akcakoca
*/

#ifndef PARSER_INCLUDE_TEXT_PACKET_H_
#define PARSER_INCLUDE_TEXT_PACKET_H_

#include "packetbase.h"
#include "consolewriter.h"
#include <sstream>
#include <iomanip>

/**
 * @class TextPacket
 * @brief includes packet members.
 *
 * This class includes packet members and their set/get functions.
 * Also displays full packet.
 *
 */
class TextPacket : public PacketBase {
 public:
    /// Constructor
    TextPacket();

    /// Destructor
    ~TextPacket();
    
    /// Display packet elements using PrinterBase class
    void Display();
};

#endif  // PARSER_INCLUDE_TEXT_PACKET_H_
