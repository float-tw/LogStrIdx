What this project do
====================

Demo loggin log wtih string index (the address of const string) to reduce log

size and translate back to string with log string section. The log string

section is renamed so it can strip from object file.


Build and test
==============

::

    $ make
    $ make test

    # result

    # log output
    # ==========
    # 0x4005f8
    # 0x4005fd

    # translator output
    # ==========
    # test
    # test2

