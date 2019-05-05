/**
* @file         readerbase.h
* @brief        ReaderBase Class
* @author       Mehmet Akcakoca
*/

#ifndef PARSER_INCLUDE_READERBASE_H_
#define PARSER_INCLUDE_READERBASE_H_

#include <iostream>
#include <string>
#include <vector>

/**
 * @class ReaderBase
 * @brief Abtract class to read data interfaces.
 *
 */
class ReaderBase {
 public:
    /// Constructor
    ReaderBase();

    /// Destructor
    ~ReaderBase();
    
    virtual void Open() = 0;
    virtual bool isReadAll() const = 0;
    virtual void GetRawData(std::vector<uint8_t>& rawData) = 0;
    virtual void Close() = 0;
};

#endif  // PARSER_INCLUDE_READERBASE_H_
