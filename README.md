# LOP_MA-EDM

This repository contains the source code of Memetic Algorithm with Explicit Diversity Management (MA-EDM). MA-EDM is a population-based optimizer that has been used to generate several new best-known solutions (BKSs) of the Linear Ordering Problem (LOP).

The information about the BKSs are in the "Supplementary Material - BKS.pdf" file and the new BKSs are in BKS.zip.

The description is in arxiv in the document "" by Lázaro Lugo, Carlos Segura and Gara Miranda and it has been submitted to the Applied Soft Computing Journal.


# Usage

1) Compile with make
2) Execute with the following parameters:
- Number of individuals in the population
- Crossover: it can be cx or ob
- Stopping criterion in seconds 
- Seed
- Instance file
- Output file

Example: ./main 200 cx 14400 99 N-stabu3_150 output.txt

The instances are available at: http://grafo.etsii.urjc.es/optsicom/lolib/ and https://github.com/sgpceurj/EJOR2015
