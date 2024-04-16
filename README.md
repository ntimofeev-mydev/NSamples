# Nau engine.

## Get source
`git clone https://github.com/NauEngine/NauPrototype`

## Initialize repository
`git submodule update --init --recursive`

## Configure

Configure with cmake presets:
Windows
`cd NauPrototype`
`cmake --preset win_vs2022_x64`
or (optional)
`cmake --preset win_ninja_clangcl-debug`

## Build
Build the engine with Visual Stuidio IDE
`cd build\win_vs2022_x64'


## Prepare samples:
Changes engine location root at 'CMakePresets.json'
                "NAU_ROOT_DIR": "PATH_TO_ENGINE_ROOT",