/**
* @file         textparser.h
* @brief        parse packet through defined structure
* @author       Mehmet Akcakoca
*/
#ifndef PARSER_INCLUDE_TEXTPARSER_H_
#define PARSER_INCLUDE_TEXTPARSER_H_

#include "parserbase.h"
#include "textpacket.h"

#define HEADER 0xAB

/**
 * @class TextParser
 * @brief parse text through defined packet structure
 * 
 */
class TextParser : public ParserBase {
 private:
    int parser_state_;
    int header_index_;

 public:
    /// Constructor
    TextParser();

    /// Destructor
    ~TextParser();

   /**
    * @brief Parse text as header | length | payload | checksum
    *
    * @param data[in] rawdata will be parsed.
    */
    void ParseData(std::vector<uint8_t> data);

   /**
    * @brief Check if packet is correct or not.
    *
    * @return true if calculated checksum is same with packet or vice versa.
    */
    bool CheckData();
};

#endif  // PARSER_INCLUDE_TEXTPARSER_H_
