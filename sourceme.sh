#!/bin/bash

# Check if file is sourced or not.
(return 0 2>/dev/null) && SOURCED=1 || SOURCED=0

qmk="qmk_firmware"
qmk_tag="0.24.5"
qmk_url="https://github.com/qmk/$qmk.git"
qmk_cli_image="docker.io/qmkfm/qmk_cli:latest"
keymap_name="gustav"
keymap="keymap.c"
keymap_path="$qmk/keyboards/kinesis/keymaps/$keymap_name"
keyboard="kinesis"
keyboardtype="stapelberg"
keyboard_path="$keyboard/$keyboardtype"
hexfile="$keyboard_$keyboardtype_$keymap_name.hex"

function show_help() {
	cat << EOF
Sourcing this file gives you following functions directly in bash:
cpkeymap:
    Copies keymap.c to the proper $qmk path.

clone:
    Clones $qmk:$qmk_tag and initializes the necessary git submodules.

pullimage:
    Downloads The latest qmk cli using either podman or docker.

build:
    All in one command. Clones, copies, and builds the firmware.
EOF
}


function cpkeymap {
    echo "Copy keymap to $keymap_path"
    mkdir -p "$keymap_path"
    cp -f "$keymap" "$keymap_path"
}

function clone {

    if test ! -d "$qmk"; then
        git clone --depth 1 -b "$qmk_tag" "$qmk_url" "$qmk"
        git -C "$qmk" submodule update --init --depth 1 lib/lufa
    else
        echo "$qmk already cloned"
    fi
}

function pullimage {
    local cont_mgr=

    if command -v podman >/dev/null 2>&1; then
        cont_mgr="podman"
    elif command -v docker >/dev/null 2>&1; then
        cont_mgr="docker"
    else
        2>&1 echo "Error: no compatible container runtime found."
        2>&1 echo "Please install podman or docker."
        return 1
    fi

    "$cont_mgr" pull "$qmk_cli_image"
}

function build {

    clone
    cpkeymap

    bash -c "cd $qmk && ./util/docker_build.sh $keyboard_path:$keymap_name"
    ln -srf ./"$qmk/$hexfile" .
}

if [[ $SOURCED -eq 1 ]]; then
    show_help
else
    2>&1 echo "You must source this file!"
fi
