# QMK planck keymap

This is my keyboard custom layout source code.
It works for the [Planck Light](https://www.youtube.com/watch?v=Gw1oJP-Rj0o) 40% 4x12 ortholinear keyboard.

# How to use

- add the source code folder to your qmk_firmware fork, in the planck keymaps folder
- connect your keyboard in debug/reset mode to allow its firmware to be flashed
- run the following command at the root of your QMK repository

`make planck/light:PutTheKeymapFolderNameHere:dfu`
