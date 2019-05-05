/**
* @file         packetbase.h
* @brief        abstract class for packet
* @author       Mehmet Akcakoca
*/

#ifndef PARSER_INCLUDE_PACKETBASE_H_
#define PARSER_INCLUDE_PACKETBASE_H_

#include "printerbase.h"
#include <iostream>
#include <vector>

/**
 * @class PacketBase
 * @brief This class includes packet members.
 *
 * and their set/get functions. Also displays full packet.
 *
 */
class PacketBase {
 private:
    uint8_t header_;
    uint8_t length_;
    uint8_t checksum_;
    std::vector<uint8_t> payload_;

 protected:
    PrinterBase* printer;
    
 public:
    /// Constructor
    PacketBase();

    /// Destructor
    ~PacketBase();

   /**
    * @brief Get header of packet.
    *
    * @return header of packet.
    */
    uint8_t GetHeader() const;

    /**
    * @brief Get length of packet.
    *
    * @return length of packet.
    */
    uint8_t GetLength() const;

    /**
    * @brief Get payload length of packet.
    *
    * @return payload length of packet.
    */
    uint8_t GetPayloadLength() const;

    /**
    * @brief Get checksum of packet.
    *
    * @return checksum of packet.
    */
    uint8_t GetChecksum() const;

    /**
    * @brief Get payload of packet.
    *
    * @return payload of packet.
    */
    std::vector<uint8_t> GetPayload() const;

   /**
    * @brief Set header of packet.
    *
    * @param header[in] header of packet.
    */
    void SetHeader(uint8_t header);

    /**
    * @brief Set length of packet.
    *
    * @param length[in] length of packet.
    */
    void SetLength(uint8_t length);

    /**
    * @brief Set checksum of packet..
    *
    * @param checksum[in] chacksum of packet.
    */
    void SetChecksum(uint8_t checksum);

    /**
    * @brief Set payload of packet.
    *
    * @param payload[in] payload of packet.
    */
    void SetPayload(std::vector<uint8_t> payload);

    /**
    * @brief Push new byte back of payload.
    *
    * @param payload[in] new byte for payload.
    */
    void AddPayload(uint8_t payload);
    
    /// Clear packet attributes.  
    void Clear();

    void virtual Display() = 0;
};

#endif  // PARSER_INCLUDE_PACKETBASE_H_
