//
//
//
inline double my_size()
{
    if(is_1d_array)
    {
        return sizeof(*this)*BYTE_TO_KILOBYTE
               + sizeof(user_1d_array[0]*sizeof_row)*BYTE_TO_KILOBYTE;
    }
    else if(is_2d_array)
    {
        return sizeof(*this)*BYTE_TO_KILOBYTE
               + sizeof(user_2d_array[0]*sizeof_row*sizeof_column)*BYTE_TO_KILOBYTE;
    }
    else if(is_3d_array)
    {
        return sizeof(*this)*BYTE_TO_KILOBYTE
               + sizeof(user_3d_array)*BYTE_TO_KILOBYTE;
    }
    else if(is_4d_array)
    {
        return sizeof(*this)*BYTE_TO_KILOBYTE
               + sizeof(user_4d_array)*BYTE_TO_KILOBYTE;
    }
    else
    {
        return sizeof(*this)*BYTE_TO_KILOBYTE;
    }
};
