/**
* @file         consolewriter.h
* @brief        write messages to console
* @author       Mehmet Akcakoca
*/

#ifndef PARSER_INCLUDE_CONSOLEWRITER_H_
#define PARSER_INCLUDE_CONSOLEWRITER_H_

#include "printerbase.h"

/**
 * @class ConsoleWriter
 * @brief Display messages on console.
 *
 */
class ConsoleWriter : public PrinterBase {
 public:
    /// Constructor
    ConsoleWriter();
    
    /// Destructor
    ~ConsoleWriter();
    
    /**
    * @brief Print data to screen.
    *
    * @param data[in] string message is printed.
    */
    void Write(std::string data);
};

#endif  // PARSER_INCLUDE_CONSOLEWRITER_H_
