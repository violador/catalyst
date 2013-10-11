//
//
//
inline unsigned int size_of_row()
{
    return (not deleted_array? sizeof_row : 0);
};
//
//
//
inline unsigned int size_of_column()
{
    return (not deleted_array? sizeof_column : 0);
};
//
//
//
inline unsigned int size_of_1st_layer()
{
    return (not deleted_array? sizeof_1st_layer : 0);
};
//
//
//
inline unsigned int size_of_2nd_layer()
{
    return (not deleted_array? sizeof_2nd_layer : 0);
};
