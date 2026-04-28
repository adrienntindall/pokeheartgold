build_dir = meson.current_build_dir()

############################################################
###                         PPARK                        ###
############################################################

ppark_c = custom_target('ppark.c',
    command : [
        jsonproc_exe,
        'ppark.json',
        'ppark.json.txt',
        build_dir + '/ppark.c'
    ],
    output : [
        'ppark.c'
    ]
)

