# SQLite Amalgamation

This is the SQLite Amalgamation downloaded from:

https://sqlite.org/download.html

## What are all does files:

- shell.c:

It is the comand line interface tool, it is a standalone so it is not
needed to run the amalgamation.

- sqlite3.c

Basically this is the amalgamation core: the sqlite engine.

- sqlite3-h

This is the SQLite API.

- sqlite3ext.h

We can find a extension here.

## What to do

Whe should build the shell in case we want to use the command line tool

mkdir build\
cd build\
Then:
gcc -o shell  ../shell.c ../sqlite3.c -lpthread -ldl

Now you can use ./shell in command prompt.
