//
//
//
template <typename data_type0, typename data_type1> 
inline data_type0 convert(const data_type1 &number)
{
    std::ostringstream converter;
    converter << number;
    return converter.std::ostringstream::str();
};
//
//
//
template <typename data_type>
inline data_type convert(const std::string &string)
{
    std::istringstream converter(string);
    data_type number;
    return (converter >> number? number : 0.0);
};
