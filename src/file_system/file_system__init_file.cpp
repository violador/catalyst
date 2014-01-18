//
//
//
inline boost::filesystem::path* init_file(const std::string &given_filename,
                                          const std::string &given_pathname)
{
    switch(given_pathname.std::string::empty())
    {
        case false:
        {
            boost::filesystem::path init(given_pathname + given_filename);
            file = init;
            return &file;
        }
        break;
        case true:
        {
            boost::filesystem::path init(tools::default_current_dir() + given_filename);
            file = init;
            return &file;
        }
        break;
    }
    return NULL;
};
//
//
//
inline boost::filesystem::path* init_file(const std::string &given_filename)
{
    boost::filesystem::path init(tools::default_current_dir() + given_filename);
    file = init;
    return &file;
};
//
//
//
inline boost::filesystem::path* init_file()
{
    boost::filesystem::path init(tools::default_current_dir());
    file = init;
    return &file;
};
