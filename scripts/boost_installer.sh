#!/bin/bash
# Matthew M Reid 10/01/2013. Please use and distribute under GNU licence.
# This script will compile boost on the maximum number of physical cores.
# If you plan to build the Parallel Graph Libraries you may find the
# following warning: Graph library does not contain MPI-based parallel components.
# note: to enable them, add "using mpi ;" to your user-config.jam. The script does this for you.
# Get the required libraries, main ones are icu for boost::regex support
echo "Getting required libraries..."
sudo apt-get update
sudo apt-get install build-essential g++ python-dev autotools-dev libicu-dev build-essential 
./bootstrap.sh --prefix=/usr/local
# pipe "using mpi ;" to the config file so that mpi is enabled
user_configFile=`find $PWD -name user-config.jam`
echo "using mpi ;" >> $user_configFile
# Build using maximum number of physical cores
n=`cat /proc/cpuinfo | grep "cpu cores" | uniq | awk '{print $NF}'`
# begin install
sudo ./b2 --with=all -j $n install
sudo ldconfig
