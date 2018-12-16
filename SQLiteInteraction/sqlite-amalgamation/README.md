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

## Getting started with SQLite Command Line Interface

We should build the shell in case we want to use the command line tool

In linux:
```console
foo@bar:~$ mkdir build
foo@bar:~$ cd build
foo@bar:~$ gcc -o shell  ../shell.c ../sqlite3.c -lpthread -ldl
foo@bar:~$ ./shell
```

Now you can use ./shell in command prompt.

Let's play a bit:

```console
sqlite> create table Users
   ...> (Name, Age);
sqlite> insert into Users values ("Anacleto",25);
sqlite> select Name || ' is ' || Age || ' years old. ' from Users;
Joe is 27 years old. 
sqlite> select Name, Age from Users;
Joe|27
sqlite> .save Test.db
```

You got a database in a file Test.db, Urra!.