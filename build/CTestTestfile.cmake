# CMake generated Testfile for 
# Source directory: /home/mfracker/csce/personal/FrackDB
# Build directory: /home/mfracker/csce/personal/FrackDB/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(unit "/home/mfracker/csce/personal/FrackDB/build/test/frackdb_test_unit")
add_test(integration "/home/mfracker/csce/personal/FrackDB/build/test/frackdb_test_integration")
subdirs(frackdb)
subdirs(test)
