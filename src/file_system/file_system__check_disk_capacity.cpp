//
//
//
inline double check_disk_capacity()
{
    return disk_space.boost::filesystem::space_info::capacity*BYTE_TO_GIGABYTE;
};
