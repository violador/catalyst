#include "log_file_handler.hpp"
//
//
//
void log_file_handler::report_input_list()
{
    #pragma omp critical
    switch(config -> output_mode() and config -> tasks() > 1)
    {
        case true:
        #ifdef FIRST_COLUMN_LENGTH
            #undef FIRST_COLUMN_LENGTH
            #define FIRST_COLUMN_LENGTH 5
        #else
            #define FIRST_COLUMN_LENGTH 5
        #endif
        #ifdef SECOND_COLUMN_LENGTH
            #undef SECOND_COLUMN_LENGTH
            #define SECOND_COLUMN_LENGTH 9
        #else
            #define SECOND_COLUMN_LENGTH 9
        #endif
        #ifdef THIRD_COLUMN_LENGTH
            #undef THIRD_COLUMN_LENGTH
            #define THIRD_COLUMN_LENGTH 9
        #else
            #define THIRD_COLUMN_LENGTH 9
        #endif
        #ifdef FOURTH_COLUMN_LENGTH
            #undef FOURTH_COLUMN_LENGTH
            #define FOURTH_COLUMN_LENGTH 9
        #else
            #define FOURTH_COLUMN_LENGTH 9
        #endif
//
//      To print the title bar:
//
        write_title_bar("Input list",
                        FIRST_COLUMN_LENGTH
                        + SECOND_COLUMN_LENGTH
                        + THIRD_COLUMN_LENGTH
                        + FOURTH_COLUMN_LENGTH
                        + 3*SPACE_LENGTH);
//
//      To print "Tasks":
//
        set_width(FIRST_COLUMN_LENGTH);
        set_right();
        log_file << "Tasks";
//
//      To print "Filenames":
//
        set_width(SECOND_COLUMN_LENGTH + SPACE_LENGTH);
        set_right();
        log_file << "Filenames";
//
//      To print "Size":
//
        set_width(THIRD_COLUMN_LENGTH + SPACE_LENGTH);
        set_right();
        log_file << "Size (kB)";
//
//      To print "Status":
//
        set_width(FOURTH_COLUMN_LENGTH + SPACE_LENGTH);
        set_right();
        log_file << "Status";
//
//      To print a section bar:
//
        set_new_line();
        fill_line_with(FIRST_COLUMN_LENGTH
                       + SECOND_COLUMN_LENGTH
                       + THIRD_COLUMN_LENGTH
                       + FOURTH_COLUMN_LENGTH
                       + 3*SPACE_LENGTH,
                       "-");
        set_new_line();
        file_system input;
        for(unsigned int i = 1; i <= config -> tasks(); ++i)
        {
            input.file_system::init(config -> work_dir(),
                                    config -> input_filename(i));
//
//          To print the task number in the task column:
//
            set_width(FIRST_COLUMN_LENGTH);
            set_right();
            log_file << i;
//
//          To print the filename in the filename column:
//
            set_width(SECOND_COLUMN_LENGTH + SPACE_LENGTH);
            set_right();
            log_file << config -> input_filename(i);
//
//          To print the file size in the size column:
//
            set_width(THIRD_COLUMN_LENGTH + SPACE_LENGTH);
            set_right();
            log_file << tools::kB(input.file_system::size());
//
//          To print the status in the status column:
//
            set_width(FOURTH_COLUMN_LENGTH + SPACE_LENGTH);
            set_right();
            log_file << (input.file_system::exists()? "found": "not found");
//
            set_new_line();
        }
        #undef FIRST_COLUMN_LENGTH
        #undef SECOND_COLUMN_LENGTH
        #undef THIRD_COLUMN_LENGTH
        #undef FOURTH_COLUMN_LENTH
        break;
    }
};
