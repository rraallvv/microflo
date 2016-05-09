
Supported boards
-----------------

MicroFlo for Embedded Linux is *work-in-progress*.
A basic [I/O backend](../microflo/linux.hpp) with support for sysfs-based GPIO exists.

It has been tested on:

* Raspberry Pi
* Desktop Linux like Arch, Ubuntu
* add-your-board-here

Prerequisites
-----------------

1. Download and install [Node.JS](http://nodejs.org)
2. Download and install a C++ toolchain for your Embedded Linux device


Building MicroFlo
------------------
It is assumed that you have common build tools such as 'make', 'git', also that microflo is being installed in a module other than microflo itself. To build the embedding example from the microflo module please see the alternate method.

1. Install MicroFlo

    ```
    npm install microflo
    export PATH=`pwd`/node_modules/.bin/
    ```

2. Download example code

    ```
    wget https://github.com/microflo/microflo/raw/master/examples/embedding.cpp
    ```

3. Build

    ```
    microflo generate embedding.cpp build/ --target linux
    g++ -o build/firmware embedding.cpp -std=c++11 -I./build -I./node_modules/microflo/microflo
    # TODO: add a way to get include flags from MicroFlo executable
    ```

4. Run

    ```
    ./build/firmware
    # Should print out 14
    ```

5. Open code, make changes, GOTO .3

    ```
    $EDITOR embedding.cpp
    ```


Alternatively the embedding example can be built from within the micrfoflo module like this.

1. Create the target directory

    ```
    rm -rf build/embedding && mkdir build/embedding
    ```

2. Build

    ```
    ./microflo.js generate examples/embedding.cpp build/embedding --target linux
    g++ -o build/embedding/firmware examples/embedding.cpp -std=c++11 -I./build/embedding -I./microflo
    # TODO: add a way to get include flags from MicroFlo executable
    ```

3. Run

    ```
    ./build/embedding/firmware
    # Should print out 14
    ```

4. Open code, make changes, GOTO .2

    ```
    $EDITOR examples/embedding.cpp
    ```
