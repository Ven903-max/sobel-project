set SynModuleInfo {
  {SRCNAME entry_proc MODELNAME entry_proc RTLNAME sobel_accel_entry_proc}
  {SRCNAME Loop_LoadLoop_proc MODELNAME Loop_LoadLoop_proc RTLNAME sobel_accel_Loop_LoadLoop_proc
    SUBMODULES {
      {MODELNAME sobel_accel_flow_control_loop_pipe RTLNAME sobel_accel_flow_control_loop_pipe BINDTYPE interface TYPE internal_upc_flow_control INSTNAME sobel_accel_flow_control_loop_pipe_U}
    }
  }
  {SRCNAME sobel_filter MODELNAME sobel_filter RTLNAME sobel_accel_sobel_filter
    SUBMODULES {
      {MODELNAME sobel_accel_sobel_filter_linebuf_RAM_AUTO_1R1W RTLNAME sobel_accel_sobel_filter_linebuf_RAM_AUTO_1R1W BINDTYPE storage TYPE ram IMPL auto LATENCY 2 ALLOW_PRAGMA 1}
    }
  }
  {SRCNAME Loop_StoreLoop_proc MODELNAME Loop_StoreLoop_proc RTLNAME sobel_accel_Loop_StoreLoop_proc}
  {SRCNAME sobel_accel MODELNAME sobel_accel RTLNAME sobel_accel IS_TOP 1
    SUBMODULES {
      {MODELNAME sobel_accel_in_img_RAM_AUTO_1R1W_memcore RTLNAME sobel_accel_in_img_RAM_AUTO_1R1W_memcore BINDTYPE storage TYPE ram IMPL auto LATENCY 2 ALLOW_PRAGMA 1}
      {MODELNAME sobel_accel_in_img_RAM_AUTO_1R1W RTLNAME sobel_accel_in_img_RAM_AUTO_1R1W BINDTYPE storage TYPE ram IMPL auto LATENCY 2 ALLOW_PRAGMA 1}
      {MODELNAME sobel_accel_fifo_w64_d4_S RTLNAME sobel_accel_fifo_w64_d4_S BINDTYPE storage TYPE fifo IMPL srl ALLOW_PRAGMA 1 INSTNAME out_r_c_U}
      {MODELNAME sobel_accel_gmem_m_axi RTLNAME sobel_accel_gmem_m_axi BINDTYPE interface TYPE adapter IMPL m_axi}
      {MODELNAME sobel_accel_control_s_axi RTLNAME sobel_accel_control_s_axi BINDTYPE interface TYPE interface_s_axilite}
    }
  }
}
