//
//
//
inline double check_disk_space()
{
    return disk_space.boost::filesystem::space_info::available*BYTE_TO_GIGABYTE;
};
