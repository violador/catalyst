//
//
//
inline std::string build_filename()
{
    return "array" 
            + tools::convert<std::string>(array_id)
            + BIN_FILE_EXTENSION;
};
