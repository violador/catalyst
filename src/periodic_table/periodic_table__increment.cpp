//
//
//
inline void operator ++()
{
    switch(current_element < table_length)
    {
        case true:
        ++current_element;
        update_data();
        break;
    }
};
//
//
//
inline void operator ++(int)
{
    switch(current_element < table_length)
    {
        case true:
        ++current_element;
        update_data();
        break;
    }
};
