#!/bin/bash

rm -rf *.data

for ((i = 1; i <= 100; ++i)); do
	make
done

echo 'Génération du PDF'
R CMD BATCH study.R