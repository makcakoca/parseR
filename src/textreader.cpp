    #include "../include/textreader.h"

    TextReader::TextReader() : file_name_("rawdata.txt"){
    }

    TextReader::TextReader(std::string file_name) : file_name_(file_name){
    }

    TextReader::~TextReader() {
    }

    void TextReader::Open() {
        file_.open(file_name_.c_str(), std::fstream::in);
        if ( !file_.is_open() ) {
            perror("in TextReader::Open following error occured");
            exit(-1);
        }
    }

    void TextReader::GetRawData(std::vector<uint8_t>& rawData) {
        int convertedHex;
        std::string strData;

        while ( !file_.eof() ) {
            /// Read file until space character
            file_ >> strData;

            /// Convert string to long integer base 16
            convertedHex = strtol(strData.c_str(), NULL, 16);

            /// Push back converted raw data
            rawData.push_back((uint8_t)convertedHex);
        }
    }

    void TextReader::Close() {
        file_.close();
    }

    bool TextReader::isReadAll() const {
        return file_.eof();
    }
