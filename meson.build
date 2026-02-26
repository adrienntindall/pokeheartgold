project('pokeheartgold', ['c', 'cpp'],
    version: '1.0',
    meson_version: '>=1.5.0',
    default_options : [
        'buildtype=plain',
        'warning_level=0'
    ]
)

fs = import('fs')

############################################################
###                         TOOLS                        ###
############################################################
subdir('tools')

############################################################
###                         FILES                        ###
############################################################
subdir('files')

subdir('asm')
subdir('src')

#ARM 9 BINARY

main = executable('main',
    sources : [
        pokeheartgold_c,
        pokeheartgold_asm,
        naix_headers,
    ],
    c_args : [
        '-thumb'
    ]
    native : false
)

#DS Rom

pokeheartgold_nds = custom_target('pokeheartgold.us.nds',
    output : 'pokeheartgold.us.nds',
    input : [
        main,
        rom_header_template,
    ],
    command : [
        nitrorom_exe,
        'pack',
    ]