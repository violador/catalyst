//
//
//
inline void start_iterations(array &h_matrix, array &s_matrix, array &v_matrix)
{
    global_log::file.write_debug_msg("algorithm::scf::start_iterations(): Invoking roothaan_equation_solver()");
    scf_iterations_ready = false;
    roothaan_equation_solver(h_matrix, s_matrix, v_matrix);
    scf_iterations_ready = true;
};
