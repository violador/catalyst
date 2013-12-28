//
//
//
inline void open()
{
    file_manager -> open_txt_output(log_file);
    file_manager -> is_open()? log_file_ready = true : log_file_ready = false;
};
