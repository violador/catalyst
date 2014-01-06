//
//
//
template <typename data_type0, typename data_type1> 
inline data_type0 convert(const data_type1 &input)
{
    return boost::lexical_cast<data_type0>(input);
};
//
//
//
template <typename data_type0>
inline data_type0 convert(const std::string &input)
{
    return boost::lexical_cast<data_type0>(input);
};
