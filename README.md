# WinMus
WinMus is the utility to make some basic stuff easily, and it's so useless.

It's **NOT** ready. I just started to code this stuff, and **all of my code is just a big joke**.

I'll add some features over time.

![зображення](https://github.com/user-attachments/assets/792db815-985e-4bc8-a11e-e5cb13e07cab)

## Functions
At this time i made following functions:
### File Sorting
You can sort files by file extensions, and config will be saved at the same place for the next sorting.

![зображення](https://github.com/user-attachments/assets/00f061de-d0fd-4e68-b698-9cb00460c32f) ![зображення](https://github.com/user-attachments/assets/81cdb3b8-87ef-46e4-a763-2ddf661119df)

### Install Software
You can install software using package managers, but at this time you can choose only one:
#### Choco
you can search, install, list and remove packages with choco.
Also you can install choco in 3 clicks( ok, 8 clicks, but it stills faster ).

![зображення](https://github.com/user-attachments/assets/3a299114-7430-4b03-b550-a22319232ceb)
#### Winget
I didn't add this. But it might be in the future.

### Clean Temp Files
Just clean Temp

![зображення](https://github.com/user-attachments/assets/f5649515-b0e4-496a-8b35-6b7e9327307f)

## Install
You can try v0.0.1 on [Release page](https://github.com/musdev13/WinMus/releases)


## Build
You can also build it from sources, because it uses default c++ libraries.
That means you can compile it using this commands:
### Windows
#### MSVC
```cmd
cl /EHsc /W4 main.cpp add.cpp /link /out:WinMus.exe
```
#### GCC/G++
```shell
g++ *.cpp -o WinMus.exe
```
### Linux
For Linux **I'll make other project** that will be called **LinMus**. It will be suddenly.
### MacOS
I don't have MacBook, and i won't :(
