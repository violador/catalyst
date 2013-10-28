//
//
//
inline void init(array &h_matrix, array &s_matrix, array &v_matrix)
{
    global_log::file.write_debug_msg("algorithm::scf::init(): Invoking roothaan_equation_solver()");
    roothaan_equation_solver(h_matrix, s_matrix, v_matrix);
};
