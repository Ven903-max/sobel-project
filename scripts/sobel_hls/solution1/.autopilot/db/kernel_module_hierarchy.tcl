set ModuleHierarchy {[{
"Name" : "sobel_accel","ID" : "0","Type" : "dataflow",
"SubInsts" : [
	{"Name" : "entry_proc_U0","ID" : "1","Type" : "sequential"},
	{"Name" : "Loop_LoadLoop_proc_U0","ID" : "2","Type" : "sequential",
		"SubLoops" : [
		{"Name" : "LoadLoop_VITIS_LOOP_19_1","ID" : "3","Type" : "pipeline"},]},
	{"Name" : "sobel_filter_U0","ID" : "4","Type" : "sequential",
		"SubLoops" : [
		{"Name" : "RowLoop_ColLoop","ID" : "5","Type" : "pipeline"},]},
	{"Name" : "Loop_StoreLoop_proc_U0","ID" : "6","Type" : "sequential",
		"SubLoops" : [
		{"Name" : "StoreLoop_VITIS_LOOP_31_2","ID" : "7","Type" : "pipeline"},]},]
}]}