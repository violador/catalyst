//
//
//
inline boost::filesystem::path* init_path(const std::string &given_pathname)
{
    switch(given_pathname.std::string::empty())
    {
        case false:
        {
            boost::filesystem::path init(given_pathname);
            path = init;
            return &path;
        }
        break;
        case true:
        {
            boost::filesystem::path init(tools::default_current_dir());
            path = init;
            return &path;
        }
        break;
    }
    return NULL;
};
//
//
//
inline boost::filesystem::path* init_path()
{
    boost::filesystem::path init(tools::default_current_dir());
    path = init;
    return &path;
};
