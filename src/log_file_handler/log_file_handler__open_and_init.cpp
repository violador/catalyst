//
//
//
void inline open_and_init()
{
    file_manager -> open_txt_output(log_file);
    switch(file_manager -> is_open())
    {
        case false:
        {
            log_file_ready = false;
            report_bad_init();
        }
        break;
        case true:
        {
            log_file_ready = true;
            init_log_file();
            report_input_list();
        }
        break;
    }
};
