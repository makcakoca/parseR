#include "../include/consolewriter.h"

ConsoleWriter::ConsoleWriter() {
}

ConsoleWriter::~ConsoleWriter() {
}

void ConsoleWriter::Write(std::string data) {
    printf("-> %s", data.c_str());
}
