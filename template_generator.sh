#!/usr/bin/env bash

project_name=prog3_unit2_neuralnetwork_v2025_01

# Create Template
mkdir ../${project_name}_template -p
rsync -au .github ../${project_name}_template/
rsync -au autograder ../${project_name}_template/
mkdir ../${project_name}_template/src -p
rsync -au template/src/ ../${project_name}_template/src
# shellcheck disable=SC2144
#if [[ -f template/src/*.cpp ]]; then
#  cp template/src/*.cpp ../${project_name}_template/src
#fi
## shellcheck disable=SC2144
#if [[ -f template/src/*.h ]]; then
#  cp template/src/*.h ../${project_name}_template/src
#fi

mkdir ../${project_name}_template/tools -p
rsync -au tools/catch ../${project_name}_template/tools/
#rsync -au tools/docker ../${project_name}_template/tools/
rsync -a -f"- */" -f"+ *" ./ ../${project_name}_template
rm -f ../${project_name}_template/autograder_generator.sh
rm -f ../${project_name}_template/template_generator.sh

echo 'template folder has been synchronized correctly'