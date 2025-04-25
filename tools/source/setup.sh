#!/usr/bin/env bash

# Prepare autograder environment
add-apt-repository ppa:deadsnakes/ppa
add-apt-repository ppa:ubuntu-toolchain-r/test
echo "deb http://cz.archive.ubuntu.com/ubuntu eoan main universe" | sudo tee -a  /etc/apt/sources.list

apt-get update
apt-get install -y \
    build-essential \
    manpages-dev \
    software-properties-common \
    libtbb-dev \
    gcc-11 \
    g++-11 \
    gdb \
    clang-tidy \
    clang \
    clang-tools \
    clang-format \
    rsync \
    tar \
    python \
    valgrind \
    catch \
    dos2unix \
    jq

# Update C++ alternatives
apt-get clean
update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-11 120 \
    --slave /usr/bin/g++ g++ /usr/bin/g++-11 \
    --slave /usr/bin/gcov gcov /usr/bin/gcov-11

# Install Python dependencies declared in requirements.txt
apt-get install -y python python3-pip
pip3 install -r /autograder/source/requirements.txt

# Move python uploaded grader files into the same directory as run_autograder
cp /autograder/source/grade_util.py /autograder
cp /autograder/source/bootstrap.py /autograder
cp /autograder/source/config.yml /autograder
