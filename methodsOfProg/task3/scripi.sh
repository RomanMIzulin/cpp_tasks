#!/bin/bash

python3 generatedata.py 1000
`time ./a.out` >> result.txt
python3 generatedata.py 5000
python3 generatedata.py 1000
python3 generatedata.py 1500
python3 generatedata.py 2000
python3 generatedata.py 50000
python3 generatedata.py 100000
python3 generatedata.py 300000
python3 generatedata.py 500000
