# hugaxyu
![Alt text](/screenshots/screenshot.png "screenshot")

## Compilation
```
$ sudo pacman -S sdl2 sdl2_image sdl2_ttf sdl2_mixer jsoncpp
$ git clone https://github.com/nohashduck/hugaxyu
$ cd hugaxyu/
$ g++ -c source.cpp && g++ source.o -o app -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer -ljsoncpp
$ ./app
```
