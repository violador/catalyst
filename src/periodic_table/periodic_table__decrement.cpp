//
//
//
inline void operator --()
{
    switch(current_element > 1)
    {
        case true:
        --current_element;
        update_data();
        break;
    }
};
//
//
//
inline void operator --(int)
{
    switch(current_element > 1)
    {
        case true:
        --current_element;
        update_data();
        break;
    }
};
