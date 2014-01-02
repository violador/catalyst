//
//
//
inline bool check_if(const unsigned int &option)
{
    switch(option)
    {
        case   option::is_positive: return is_positive();   break;
        case   option::is_negative: return is_negative();   break;
        case       option::is_null: return is_null();       break;
        case   option::is_constant: return is_const_array;  break;
        case     option::is_square: return is_square_array; break;
        case    option::is_deleted: return deleted_array;   break;
        case option::is_transposed: return is_transposed;   break;
                           default: return false;           break;
    }
};
