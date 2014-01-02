//
//
//
inline void save()
{
    input.file_system::init(config -> dir_path_of(option::scratch),
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
    input.file_system::init(config -> dir_path_of(option::scratch),
                            filename);
    switch(input.file_system::exists())
    {
        case true: book_data(); break;
    }
};
