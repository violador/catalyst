//
//
//
inline void save()
{
    input.file_system::init(config -> scratch_dir(),
                                   build_filename());
    switch(input.file_system::exists())
    {
        case true: book_data(); break;
    }
};
//
//
//
inline void save(std::string &filename)
{
    input.file_system::init(config -> scratch_dir(),
                                          filename);
    switch(input.file_system::exists())
    {
        case true: book_data(); break;
    }
};
