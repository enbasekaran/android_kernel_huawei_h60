####################################################################################################
#
####################################################################################################


####################################################################################################
#Directories for library files 
####################################################################################################
vob_lib_dirs :=

####################################################################################################
#library files
####################################################################################################
vob_lib_files :=

####################################################################################################
#Directories for include files
####################################################################################################
include $(CODEC_MK_FILE_PATH)/dsp_code_gu_modem_core_med.inc

####################################################################################################
#Directories for source files
####################################################################################################
vob_src_dirs := $(CODEC_SRC_FILE_PATH)/om/src

####################################################################################################
#Source files
####################################################################################################
vob_src_files :=$(vob_src_dirs)/om_comm.c        \
	$(vob_src_dirs)/om_cpuview.c     \
	$(vob_src_dirs)/om_log.c         \
	$(vob_src_dirs)/om_msghook.c     \
	

####################################################################################################
#general make rules
####################################################################################################


####################################################################################################
#
####################################################################################################


####################################################################################################
#
####################################################################################################