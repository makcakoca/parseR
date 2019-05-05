/**
* @file         textreader.h
* @brief        TextReader Class
* @author       Mehmet Akcakoca
*/

#ifndef PARSER_INCLUDE_TEXTREADER_H_
#define PARSER_INCLUDE_TEXTREADER_H_

#include "readerbase.h"

#include <fstream>

/**
 * @class TextReader
 * @brief The class is responsible for opening, reading and closing text file.
 *
 */
class TextReader : public ReaderBase {
 private:
    std::fstream file_;
    std::string file_name_;

 public:
    /// Constructor
    TextReader();

   /**
    * @brief Constructor
    *
    * @param file_name[in] file path and name.
    */
    TextReader(std::string file_name);

    /// Destructor
    ~TextReader();

    /// Open text file for reading.
    void Open();

    /**
    * @brief Read text file and convert hex string to number.
    *
    * @param data[out] read and converted data.
    */
    void GetRawData(std::vector<uint8_t>& rawData);

    /// Close the file.
    void Close();

    /**
    * @brief Return whether file is completely read or not 
    *
    * @return true if file reader reached end of file or vice versa. 
    */
    bool isReadAll() const;
};

#endif  // PARSER_INCLUDE_TEXTREADER_H_
