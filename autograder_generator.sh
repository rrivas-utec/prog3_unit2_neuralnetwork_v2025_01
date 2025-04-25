#!/usr/bin/env bash

project_name=prog3_unit2_neuralnetwork_v2025_01
source_code='
 neural_network.h
  '

# Create autograder zip file
rm -f ../autograder.zip

cd autograder/tests || return
rm ${source_code}
cd ..
zip -r ../../autograder .
cd ../tools/source/ || return
zip -ru ../../../autograder .
cd ../..

# Create probe test zip file
rm -f ../${project_name}.zip
cd src || return
zip -r ../../${project_name} ${source_code}
cd ..

# Create probe test zip file
rm -f ../${project_name}.zip
cd src || return
zip -r ../../${project_name} ${source_code}
cd ..
