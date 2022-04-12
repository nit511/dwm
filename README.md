# DWM
DWM is a dynamic window manager for X. It manages windows in tiled, monocle and floating layouts. All of the layouts can be applied dynamically, optimising the environment for the application in use and the task performed.

# Screenshots
![2022-04-04-121104_1600x900_scrot](https://user-images.githubusercontent.com/82656244/161488811-6127ca50-0d6b-4993-aaf4-dd703f044b54.png)
![2022-04-04-121128_1600x900_scrot](https://user-images.githubusercontent.com/82656244/161488835-6f69cbea-0331-4c83-b674-1bb6f2ed3d8a.png)

# Requirements
- python-pywal
- ttf-font-awesome
- ttf-jetbrains-mono

# Installation
```
git clone https://github.com/nit511/dwm/
cd dwm/
sudo make install
```
# Notes:-
- If your compilation gives error try to change $USER to your username in config.h file line no.16.
- To use pywal you need to delete line no.17 in ```~/.cache/wal/colors-wal-dwm.h``` (if you are not using Urgent patch in dwm).
- Dwm is installed into the ```/usr/local/bin/``` directory by default, if you want to install it locally you can change prefix path in config.mk file.
- You can check this dwm's key bindings and can also change them as per your needs in config.h file.
- If you like dwm statusbar check [this](https://github.com/nit511/dwmblocks/).

![2022-04-07-141057_532x40_scrot_cropped](https://user-images.githubusercontent.com/82656244/162164347-b1fc5b14-c05f-48d6-928f-48de7320ff02.jpg)
