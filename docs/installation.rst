Installing
==========

Compilation
-----------

In order to compile the binaries,
you'll need a recent of the `gcc` compiler and the `gnu-make` toolchain.

Multiple binary can be compiled for this project.

.. tab-set::

  .. tab-item:: Default

    This is the release binary, used for the delivery.

    .. code-block:: sh

      make

    This will provide a binary named `42sh`.

  .. tab-item:: Debug

    This binary come with additional logging providing a insight
    of the inner system state to help in the development process.

    Some extra "developer features" are provided by this binary.

    .. code-block:: sh

      make debug

    This will provide a binary named `debug`.

  .. tab-item:: Angry

    This binary ships with the Google memory sanitizer library
    to find possible problems and memory leaks.

    It allows had debug features.

    .. code-block:: sh

      make angry

    This will provide a binary named `angry`.

  .. tab-item:: Tests

    This binary contains a set of tests to ensure the proper behaving
    of the main binary features.

    It uses the *criterion* library for unit, integration
    and end-to-end testing.

    .. code-block:: sh

      make run_tests

    You can also run the tests directly using

    .. code-block:: sh

      make tests_run

    Or directly generate a coverage report using *gcvor*

    .. code-block:: sh

      make cov

    This will provide a binary named `run_tests`.

  .. tab-item:: AFL

    This binary is used to run fuzzy testing.
    It uses American Fuzzy Lop and require too have to afl-gcc custom compiler.

    .. code-block:: sh

      make afl

    You can run the fuzzer program using

    .. code-block:: sh

      make afl_run

    This will provide a binary named `42sh_afl`.

.. note::

  To compile the project fast, you can use the `-j` flag on the `make` command

  .. code-block:: sh

    make -j 42sh

.. note::

  You can compile all the binaries at once using the following command:

  .. code-block:: sh

    make bundle
