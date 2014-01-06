//
//
//
inline void init(const unsigned int &element)
{
    current_element = element;
    update_data();
};
//
//
//
inline void init(const std::string &element)
{
    current_element = 0;
    do
    {
        ++current_element;
        update_data();
    }
    while(element.std::string::compare(current_symbol) not_eq 0);
};
