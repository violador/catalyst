//
//
//
inline unsigned int size_of_row()
{
    switch(not deleted_array)
    {
        case false: return 0; break;
        case  true: return sizeof_row; break;
    }
};
//
//
//
inline unsigned int size_of_column()
{
    switch(not deleted_array)
    {
        case false: return 0; break;
        case  true: return sizeof_column; break;
    }
};
//
//
//
inline unsigned int size_of_1st_layer()
{
    switch(not deleted_array)
    {
        case false: return 0; break;
        case  true: return sizeof_1st_layer; break;
    }
};
//
//
//
inline unsigned int size_of_2nd_layer()
{
    switch(not deleted_array)
    {
        case false: return 0; break;
        case  true: return sizeof_2nd_layer; break;
    }
};
