build_dir = meson.current_build_dir()

############################################################
###                        RECORD                        ###
############################################################
subdir('record')

pgradio_gra_narc = custom_target('record.narc',
    command : [
        narc_exe, 
        '-p', build_dir + '/record.narc',
        '-d', build_dir + '/record.narc.p',
        '-i'
    ],
    input : [
        record_nclr,
        record_bin
    ],
    output : [
        'record.narc',
        'record.naix',
    ],
    build_by_default:true,
)