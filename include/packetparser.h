/**
* @file         packetparser.h
* @brief        PacketParser Class
* @author       Mehmet Akcakoca
*/
#ifndef PARSER_INCLUDE_PACKETPARSER_H_
#define PARSER_INCLUDE_PACKETPARSER_H_

#include "textreader.h"
#include "textparser.h"
#include "textpacket.h"

/**
 * @class PacketParser
 * @brief This class is meta class which manages all parse operations.
 * 
 */
class PacketParser {
 private:
    ReaderBase* reader_;
    ParserBase* parser_;

 public:
    /// Constructor
    PacketParser();

   /**
    * @brief Constructor
    *
    * @param file_name[in] file path and name.
    */
    PacketParser(std::string file_name);

    /// Destructor
    ~PacketParser();
    
    /// Perform all parsing operations 
    void Run();
};

#endif  // PARSER_INCLUDE_PACKETPARSER_H_
