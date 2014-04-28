//
//
//
inline double my_size()
{
    if(is_1d())
    {
        return sizeof(*this)*BYTE_TO_KILOBYTE
               + sizeof(data1[0]*rank1)*BYTE_TO_KILOBYTE;
    }
    else if(is_2d())
    {
        return sizeof(*this)*BYTE_TO_KILOBYTE
               + sizeof(data2[0]*rank1*rank2)*BYTE_TO_KILOBYTE;
    }
    else if(is_3d())
    {
        return sizeof(*this)*BYTE_TO_KILOBYTE
               + sizeof(data3)*BYTE_TO_KILOBYTE;
    }
    else if(is_4d())
    {
        return sizeof(*this)*BYTE_TO_KILOBYTE
               + sizeof(data4)*BYTE_TO_KILOBYTE;
    }
    else
    {
        return sizeof(*this)*BYTE_TO_KILOBYTE;
    }
};
