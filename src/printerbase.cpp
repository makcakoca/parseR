#include "../include/printerbase.h"

PrinterBase::PrinterBase() {
}

PrinterBase::~PrinterBase() {
}

std::string PrinterBase::ConvertHex2Print(uint8_t data) {
    std::stringstream ss;
    ss << std::setfill('0') << std::setw(2) << std::hex << (int)data;
    return ss.str();
}
