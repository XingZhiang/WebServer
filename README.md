# WebServer
基于C++11的跨平台的http WebServer

## 环境搭建
- 安装boost库
```zsh
sudo pacman -S boost
sudo pacman -S boost-libs
```
- 安装jsoncpp
``` zsh
sudo pacman -S jsoncpp
```

## 运行
``` zsh
cd webserver
mkdir build
cmake ..
make
./webserver
```
