/**
* @file         parserbase.h
* @brief        ParserBase Class
* @author       Mehmet Akcakoca
*/

#ifndef PARSER_INCLUDE_PARSERBASE_H_
#define PARSER_INCLUDE_PARSERBASE_H_

#include "packetbase.h"

/**
 * @class ParserBase
 * @brief abstract class for parsing packets
 * 
 */
class ParserBase {
 protected:
    std::vector<PacketBase *> valid_packets;
    PacketBase* single_packet;

 public:
    /// Constructor
    ParserBase();
    
    /// Destructor
    ~ParserBase();
    
    virtual void ParseData(std::vector<uint8_t> data) = 0;
    
   /**
    * @brief Get valid packets.
    *
    * @return valid packets.
    */
    std::vector<PacketBase *> GetValidPackets() const;
};

#endif  // PARSER_INCLUDE_PARSERBASE_H_
