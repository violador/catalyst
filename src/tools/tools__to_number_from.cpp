//
//
//
template <typename data_type> 
inline data_type to_number_from(const std::string &given_string)
{
    std::istringstream converter(given_string);
    data_type result;
    return (data_type) (converter >> result? result : 0);
};
