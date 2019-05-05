/**
* @file         printerbase.h
* @brief        PrinterBase Class
* @author       Mehmet Akcakoca
*/

#ifndef PARSER_INCLUDE_PRINTERBASE_H_
#define PARSER_INCLUDE_PRINTERBASE_H_

#include <iostream>
#include <sstream>
#include <iomanip>

/**
 * @class PrinterBase
 * @brief Abstract class for print operations.
 *
 */
class PrinterBase {
 public:
    /// Constructor
    PrinterBase();

    /// Destructor
    ~PrinterBase();

    /**
    * @brief Convert hex data to printable string.
    *
    * @param data[in] hex value.
    * @return string version of hex data
    */
    std::string ConvertHex2Print(uint8_t data);

    void virtual Write(std::string data) = 0;
};

#endif  // PARSER_INCLUDE_PRINTERBASE_H_
