//
//
//
inline double check_disk_space()
{
    return disk_space.boost::filesystem::space_info::available*tools::byte_to_gigabyte();
};
