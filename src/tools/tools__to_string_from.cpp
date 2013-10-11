//
//
//
template <typename data_type> 
inline std::string to_string_from(const data_type &given_number)
{
    std::ostringstream converter;
    converter << given_number;
    return converter.str();
};
