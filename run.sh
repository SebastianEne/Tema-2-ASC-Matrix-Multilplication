#!/bin/bash
#
# Author: Heri
#
# Script de submitere a job-urilor pe fiecare coda, folosind compilatoare diferite
#
module load libraries/atlas-3.10.1-gcc-4.4.6-nehalem
module load libraries/atlas-3.10.1-gcc-4.4.6-opteron
module load libraries/atlas-3.10.1-gcc-4.4.6-quad
module list

qdel -f -u sebastian.ene
make clean
make

mprun.sh --job-name MyTestGcc-O --queue ibm-opteron.q \
	 --script exec_opteron.sh --show-qsub --show-script --batch-job
mprun.sh --job-name MyTestGcc-N --queue ibm-nehalem.q \
	--script exec_nehalem.sh --show-qsub --show-script --batch-job
mprun.sh --job-name MpiTestGcc-Q --queue ibm-quad.q \
	--script exec_quad.sh --show-qsub --show-script --batch-job

