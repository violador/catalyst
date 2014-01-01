//
//
//
inline double size()
{
    switch(exists())
    {
        case false: return 0.0; break;
        case  true: return boost::filesystem::file_size(file); break;
    }
};
