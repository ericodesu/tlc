# About

Project in order to learn the basics from programming languages

## C++

### Console

#### Project requirements

  - g++ - [Windows](https://sourceforge.net/projects/mingw/) | Linux [[Ubuntu](https://linuxize.com/post/how-to-install-gcc-on-ubuntu-20-04/)];
  - cmake - [Windows & Linux](https://cmake.org/download/) - Follow [this](https://cmake.org/install/) guide in order install it;
  - OpenCV - [Windows](https://sourceforge.net/projects/opencvlibrary/) | [Linux](https://docs.opencv.org/4.5.2/d7/d9f/tutorial_linux_install.html);

#### Installation information

There's a few things I'd like to point it out in order to run sucessfully in your machine:

  - 1 - When it comes to the compiler, at least in Windows envrionments _"Even tough I pointed out a [minGW](https://sourceforge.net/projects/mingw/) as a compiler kit"_ I wasn't able to make it find the OpenCV 3rd party library for image processing _"Has something to do with how the compiled version not being compatible"_,  so I ended up using the [Visual Studio Community 2019 - x86_amd64](https://visualstudio.microsoft.com/downloads/) kit;
  
  - 2 - Now, in the OpenCV [[Windows](https://sourceforge.net/projects/opencvlibrary/), [Linux](https://docs.opencv.org/4.5.2/d7/d9f/tutorial_linux_install.html)] case the folder where you install it it's crucial since the cmake can't find it sometimes:

      - Windows environments:

          - The project assumes that your installation it's done at the ```C:/OpenCV/``` directory;

          - There's this step where you need to add the build into the system variable ```PATH```, in my case since I used Microsoft's kit i ended up inserting ```C:\OpenCV\build\x64\vc15\bin```.

       - Linux environments:

          - The project assumes that your installation it's done at the ```/usr/local/``` directory (this is where the library it's installed by default).    

### GUI

#### Project requirements

  - g++ - [Windows](https://sourceforge.net/projects/mingw/) | Linux [[Ubuntu](https://linuxize.com/post/how-to-install-gcc-on-ubuntu-20-04/)];
  - cmake - [Windows & Linux](https://cmake.org/download/) - Follow [this](https://cmake.org/install/) guide in order install it;

#### Installation information

The libraries used in this project are imported by `.gitsubmodules`, in order to run it, just issue the `cmake` commad;

### Unreal

#### Project requirements

  - Visual Studio 2019 - [Windows](https://visualstudio.microsoft.com/pt-br/downloads/);
  - Unreal Egine  `4.27.0` - [Windows](https://www.unrealengine.com/en-US/download);

#### Installation information

Reach out to the link used above and download it via Epic Game Store, then choose the version according to this `readme.md`.

## C#

### Project requirements

   - Visual Studio Preview 2022 - [Windows](https://visualstudio.microsoft.com/vs/preview/vs2022/#download-preview)

## Java

### Project requirements

   - A Java based IDE, I'd recommend using [Netbeans](https://www.oracle.com/technetwork/java/javase/downloads/jdk-netbeans-jsp-3413139-esa.html) since it's the one I'm using to develop it;
