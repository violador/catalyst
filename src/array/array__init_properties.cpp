//
//
//
inline void init_properties(const unsigned int local_row_size = 0,
                            const unsigned int local_column_size = 0,
                            const unsigned int local_1st_layer_size = 0,
                            const unsigned int local_2nd_layer_size = 0)
{
    #pragma omp parallel sections num_threads(6)
    {
        #pragma omp section
        {
            switch(local_row_size == 0)
            {
                case true:
                sizeof_row = 0;
                sizeof_column = 0;
                sizeof_1st_layer = 0;
                sizeof_2nd_layer = 0;
                sizeof_3rd_layer = 0;
                is_1d_array = false;
                is_2d_array = false;
                is_3d_array = false;
                is_4d_array = false;
                break;
            }
        }
        #pragma omp section
        {
            switch((local_row_size > 0) 
                   and (local_column_size == 0))
            {
                case true:
                sizeof_row = local_row_size;
                sizeof_column = 0;
                sizeof_1st_layer = 0;
                sizeof_2nd_layer = 0;
                sizeof_3rd_layer = 0;
                is_1d_array = true;
                is_2d_array = false;
                is_3d_array = false;
                is_4d_array = false;
                break;
            }
        }
        #pragma omp section
        {
            switch((local_row_size > 0) 
                   and (local_column_size > 0) 
                   and (local_1st_layer_size == 0))
            {
                case true:
                sizeof_row = local_row_size;
                sizeof_column = local_column_size;
                sizeof_1st_layer = 0;
                sizeof_2nd_layer = 0;
                sizeof_3rd_layer = 0;
                is_1d_array = false;
                is_2d_array = true;
                is_3d_array = false;
                is_4d_array = false;
                break;
            }
        }
        #pragma omp section
        {
            switch((local_row_size > 0) 
                   and (local_column_size > 0) 
                   and (local_1st_layer_size > 0) 
                   and (local_2nd_layer_size == 0))
            {
                case true:
                sizeof_row = local_row_size;
                sizeof_column = local_column_size;
                sizeof_1st_layer = local_1st_layer_size;
                sizeof_2nd_layer = 0;
                sizeof_3rd_layer = 0;
                is_1d_array = false;
                is_2d_array = false;
                is_3d_array = true;
                is_4d_array = false;
                break;
            }
        }
        #pragma omp section
        {
            switch((local_row_size > 0) 
                   and (local_column_size > 0) 
                   and (local_1st_layer_size > 0) 
                   and (local_2nd_layer_size > 0))
            {
                case true:
                sizeof_row = local_row_size;
                sizeof_column = local_column_size;
                sizeof_1st_layer = local_1st_layer_size;
                sizeof_2nd_layer = local_2nd_layer_size;
                sizeof_3rd_layer = 0;
                is_1d_array = false;
                is_2d_array = false;
                is_3d_array = false;
                is_4d_array = true;
                break;
            }
        }
        #pragma omp section
        {
            #pragma omp parallel sections num_threads(11)
            {
                #pragma omp section
                {
                    switch(local_row_size > 0)
                    {
                        case false:
                        {
                            array_id = 0;
                            array_filename = "";
                        }
                        break;
                        case true:
                        {
                            array_id = tools::random_number<unsigned long int>();
                            array_filename = "array" 
                                           + tools::convert<std::string>(array_id) 
                                           + BIN_FILE_EXTENSION;
                        }
                        break;
                    }
                }
                #pragma omp section
                {
                    is_const_array = false;
                }
                #pragma omp section
                {
                    is_square_array = (local_row_size == local_column_size? true : false);
                }
                #pragma omp section
                {
                    is_transposed = false;
                }
                #pragma omp section
                {
                    created_array = (local_row_size not_eq 0? true : false);
                }
                #pragma omp section
                {
                    deleted_array = (local_row_size not_eq 0? false : true);
                }
                #pragma omp section
                {
                    lowend_mode_on = false;
                }
                #pragma omp section
                {
                    setup_ready = true;
                }
                #pragma omp section
                {
                    array_name = DEFAULT_ARRAY_NAME;
                }
                #pragma omp section
                {
                    temp_filename = "";
                }
                #pragma omp section
                {
                    config = &global_settings::config;
                }
            } // pragma omp parallel sections num_threads(9)
        } // pragma omp section 
    } // pragma omp parallel sections num_threads(6)
    global_log::file.write_debug_msg("array::init_properties(): Array ID = ", array_id);
};
