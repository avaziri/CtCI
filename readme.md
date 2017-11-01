For C++ files:
// Install and build GTest
mkdir CtCI/build
cd CtCI/build
cmake ..
make

Each question's library will be placed in CtCI/lib
Each test exe will be placed in CtCI/bin

For Python files:
Both the implementation and tests can be found in the CtCI/src/python folder.

To run the tests I suggest:
cd CtCI/src/python
pytest -v -s /path/to/test_file.py
