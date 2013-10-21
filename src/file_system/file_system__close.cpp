//
//
//
inline void close(std::fstream &file)
{
    file.std::fstream::close();
};
//
//
//
inline void close()
{
    switch(input.std::fstream::is_open())
    {
        case true: input.std::fstream::close(); break;
    }
    switch(output.std::fstream::is_open())
    {
        case true: output.std::fstream::close(); break;
    }
};
