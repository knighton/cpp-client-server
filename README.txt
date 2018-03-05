1. Introduction
   ------------

A webserver and clients that talk JSON.  Identical C++ and python APIs.

This is a really nice way to do this in C++ using libraries that are analogous
to the elegance you're used to with python, so I'm putting this code in a
standalone repo for my future reference and yours.  I hope you find it useful.

2. Libraries used
   --------------

Commandline flags:
* pip3 install argparse
* Google Commandline Flags (GFlags): https://github.com/gflags/gflags

JSON:
* pip3 install ujson
* JSON for Modern C++: https://github.com/nlohmann/json

String printf:
* (built-in)
* StringPrintf() methods from GFlags

HTTP server:
* pip3 install flask
* Crow C++ micro web framework: https://github.com/ipkn/crow

Sending HTTP requests:
* pip3 instal requests
* Curl for People: https://github.com/whoshuu/cpr

3. Installation
   ------------

Instructions for Xubuntu 17.10:

    +
    |
    |  # Gflags.
    |  apt install libgflags-dev
    |
    |  # Crow.
    |  apt install libboost_system-dev libboost_thread-dev
    |
    |  # CPR.
    |  apt install libcurl4-openssl-dev
    |
    |  # Builds with clang++-5.0.
    |  apt install clang++5
    |
    +

4. Building
   --------

Builds with make, with hilariously paranoid flags.  External libraries are each
wrapped with a middle-man header file containing pragmas to disable some
warnings.  Static analysis is good.

    +
    |
    |  make clean
    |  make all
    |
    +
